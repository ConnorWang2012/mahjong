/*******************************************************************************
@ copyright(C), 2015-2020, ConnorAndHisFriendsCompany.Inc
@ filename:	    msg_manager.cc
@ author:	    Connor
@ version:	    1.0.0
@ date:		    2017-05-01
@ description:  see the header.
@ others:
@ history:
1.date:
author:
modification:
********************************************************************************/

#include "msg_manager.h"

#include "event_headers.h"
#include "lua_bind_helper.h"
#include "msg/msg_type.h"
#include "msg/msg_id.h"
#include "msg/protocol/my_login_msg_protocol.pb.h"
#include "network/network_manager.h"

#include "cocos2d.h"

namespace gamer
{

MsgManager::MsgManager()
{
    this->init();
}

MsgManager* MsgManager::getInstance()
{
	static MsgManager s_msg_mgr; 
	return &s_msg_mgr;
}

bool MsgManager::sendMsg(msg_header_t msg_type,
                         msg_header_t msg_id,
                         const MsgResponseCallback& response_cb)
{
    return this->sendMsg({ gamer::client_msg_header_len(), msg_type, msg_id, nullptr },
        response_cb);
}

bool MsgManager::sendMsg(const ClientMsg& msg, const MsgResponseCallback& response_cb)
{
    char buf[MsgManager::MAX_MSG_LEN] = { 0 };
    msg_header_t len = 0;
    if (this->packMsg(msg, buf, len))
    {
        auto key = this->getMsgCallbackKey(msg.type, msg.id);
        msg_response_callbacks_.insert(std::make_pair(key, response_cb));

        return NetworkManager::getInstance()->send(buf, len);
    }
    return false;
}

bool MsgManager::sendMsg(msg_header_t msg_type, msg_header_t msg_id, LuaFunction response_cb)
{
    LuaBindHelper::getInstance()->storeLuaFunction(4);

    char buf[MsgManager::MAX_MSG_LEN] = { 0 };
    msg_header_t len = 0;
    gamer::ClientMsg msg = { gamer::client_msg_header_len(), msg_type, msg_id, nullptr };
    if (this->packMsg(msg, buf, len))
    {
        auto key = this->getMsgCallbackKey(msg_type, msg_id);
        msg_response_lua_callbacks_.insert(std::make_pair(key, response_cb));

        return NetworkManager::getInstance()->send(buf, len);
    }
    return false;
}

void MsgManager::init()
{
    auto l = EventListener::create((int)EventIDs::EVENT_ID_SOCKET_CONNECTED,
        CALLBACK_SELECTOR_1(MsgManager::onSocketConnected, this),
        "MsgManager::onSocketConnected",
        (int)Listener::ListenerPriorities::SENIOR);
    EventManager::getInstance()->addEventListener(l);

    this->addMsgDispatchHandlers();
    this->addMsgHandlers();
}

void MsgManager::addMsgDispatchHandlers()
{
    msg_dispatch_handlers_.insert(std::make_pair((int)MsgTypes::S2C_MSG_TYPE_LOGIN, 
        CALLBACK_SELECTOR_1(MsgManager::dealWithLoginMsg, this)));
    
}

void MsgManager::addMsgHandlers()
{
    msg_handlers_.insert(std::make_pair((int)MsgIDs::MSG_ID_LOGIN_MY,
        CALLBACK_SELECTOR_1(MsgManager::dealWithMgLoginMsg, this)));
}

bool MsgManager::packMsg(const ClientMsg& msg, char* buf, msg_header_t& len)
{
    auto len_total = gamer::client_msg_header_len();
    auto len_data = 0;
    if (msg.context) 
    {
        len_data = strlen((char*)msg.context);
        len_total += len_data;
    }

    if (len_total > MsgManager::MAX_MSG_LEN)
        return false;

    len = len_total;

    memcpy(buf, &len_total, sizeof(msg_header_t));
    memcpy(buf + sizeof(msg_header_t), &msg.type, sizeof(msg_header_t));
    memcpy(buf + sizeof(msg_header_t) * 2, &msg.id, sizeof(msg_header_t));
    if (len_data > 0) 
    {
        memcpy(buf + gamer::client_msg_header_len(), msg.context, len_data);
    }

    return true;
}

std::string MsgManager::getMsgCallbackKey(msg_header_t msg_type, msg_header_t msg_id)
{
    char buf[gamer::client_msg_header_len()];
    snprintf(buf, sizeof(buf), "%d%d", msg_type, msg_id);
    return buf;
}

void MsgManager::getMsgCallbacks(const std::string& key,
                                 MsgResponseCallback& cpp_cb,
                                 gamer::LuaFunction& lua_cb)
{
    // C++ callback
    auto itr1 = msg_response_callbacks_.find(key);
    if (itr1 != msg_response_callbacks_.end())
    {
        cpp_cb = itr1->second;
    }
    else
    {
        cpp_cb = nullptr;
    }

    // Lua callback
    auto itr2 = msg_response_lua_callbacks_.find(key);
    gamer::LuaFunction lua_callback = -1;
    if (itr2 != msg_response_lua_callbacks_.end())
    {
        lua_cb = itr2->second;
    }
    else
    {
        lua_cb = -1;
    }
}

void MsgManager::dispatchMsg(int msg_code, 
                             msg_header_t msg_type,
                             msg_header_t msg_id,
                             const google::protobuf::Message* msg,
                             const std::string& class_name)
{
    MsgResponseCallback cppcb = nullptr;
    auto luacb                = -1;
    auto msgcode              = msg_code;
    auto msgtype              = msg_type;
    auto msgid                = msg_id;
    auto msgtmp               = msg;
    auto classname            = class_name;

    auto key = this->getMsgCallbackKey(msg_type, msg_id);
    this->getMsgCallbacks(key, cppcb, luacb);

    auto callback = [=](float) {
        cocos2d::Director::getInstance()->getScheduler()->unschedule("dispatch_msg", this);
        
        // C++
        if (nullptr != cppcb)
        {
            cppcb(msgcode, msgtype, msgid, msgtmp);
        }

        // Lua
        if (-1 != luacb)
        {
            LuaBindHelper::getInstance()->dispatchMsg(luacb,
                                                      msgcode,
                                                      msgtype,
                                                      msgid,
                                                      msgtmp,
                                                      classname);
        }
    };

    auto scheduler = cocos2d::Director::getInstance()->getScheduler();
    scheduler->schedule(callback, this, 0, false, "dispatch_msg");
}

void MsgManager::dealWithLoginMsg(const ServerMsg& msg)
{
    printf("[MsgManager::DealWithLoginMsg] msg_type : %d, msg_id : %d", msg.type, msg.id);
    auto itr = msg_handlers_.find((int)msg.id);
    if (itr != msg_handlers_.end())
    {
        itr->second(msg);
    }
}

void MsgManager::dealWithMgLoginMsg(const ServerMsg& msg)
{
    if (msg.context)
    {
        char buf[MsgManager::MAX_MSG_LEN] = { 0 };
        auto len = msg.total_len - gamer::server_msg_header_len();
        protocol::MyLoginMsgProtocol proto;
        proto.ParseFromArray(msg.context, len);

        this->dispatchMsg(msg.code, 
                          msg.type, 
                          msg.id, 
                          &proto, 
                          "gamer::protocol::MyLoginMsgProtocol");
    }
}

void MsgManager::onSocketConnected(gamer::Event* event)
{
 /*   char buf[MsgManager::MAX_MSG_LEN] = { 0 };
    protocol::MyLoginMsgProtocol proto;
    proto.set_account("2017");
    proto.set_password(2018);
    proto.SerializeToArray(buf, proto.ByteSize());

    auto len_total = gamer::client_msg_header_len() + proto.ByteSize();
    gamer::ClientMsg msg = { len_total, 0, 1, buf };

    auto func = [&](int code, msg_header_t msg_type, msg_header_t msg_id, void* ctx) {
        printf("msg callback code : %d, msg_type : %d, msg_id : %d\n", code, msg_type, msg_id);
    };

    this->sendMsg(msg, func);
    */
}

void MsgManager::onMsgReceived(const ServerMsg& msg)
{
    auto itr = msg_dispatch_handlers_.find((int)msg.type);
    if (itr != msg_dispatch_handlers_.end())
    {
        itr->second(msg);
    }
}

} // namespace gamer
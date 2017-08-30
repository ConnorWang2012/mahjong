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

#include <algorithm>

#include "cocos/base/CCDirector.h"
#include "cocos/base/CCScheduler.h"

#include "data/data_constants.h"
#include "data/data_manager.h"
#include "event_headers.h"
#include "lua_bind_helper.h"
#include "msg/msg_type.h"
#include "msg/msg_id.h"
#include "msg/msg_code.h"
#include "msg/protocol/room_operation_msg_protocol.pb.h"
#include "network/network_manager.h"

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

bool MsgManager::sendMsg(const ClientMsg& msg)
{
    auto msg_tmp = static_cast<google::protobuf::Message*>(msg.context);
    return this->sendMsg(msg.type, msg.id, *msg_tmp);
}

bool MsgManager::sendMsg(msg_header_t msg_type, 
                         msg_header_t msg_id, 
                         const google::protobuf::Message& msg)
{
    return this->doSendMsg(msg_type, msg_id, msg);
}

void MsgManager::addMsgListener(msg_header_t msg_type, 
                                msg_header_t msg_id, 
                                const MsgResponseCallback& listener)
{
    this->addMsgListenerForCpp(msg_type, msg_id, listener);
}

void MsgManager::addMsgListener(msg_header_t msg_type, const MsgResponseCallback& listener)
{
    this->addMsgListenerForCpp(msg_type, (msg_header_t)MsgIDs::MSG_ID_UNKNOW, listener);
}

void MsgManager::addMsgListener(msg_header_t msg_type, 
                                msg_header_t msg_id, 
                                gamer::LuaFunction listener)
{
    LuaBindHelper::getInstance()->storeLuaFunction(4);
    this->addMsgListenerForLua(msg_type, msg_id, listener);
}

void MsgManager::addMsgListener(msg_header_t msg_type, gamer::LuaFunction listener)
{
    LuaBindHelper::getInstance()->storeLuaFunction(3);
    this->addMsgListenerForLua(msg_type, (msg_header_t)MsgIDs::MSG_ID_UNKNOW, listener);
}

void MsgManager::removeMsgListener(msg_header_t msg_type, 
                                   msg_header_t msg_id, 
                                   const MsgResponseCallback& listener)
{
    this->removeMsgListenerForCpp(msg_type, msg_id, listener);
}

void MsgManager::removeMsgListener(msg_header_t msg_type, const MsgResponseCallback& listener)
{
    this->removeMsgListenerForCpp(msg_type, (msg_header_t)MsgIDs::MSG_ID_UNKNOW, listener);
}

void MsgManager::removeMsgListener(msg_header_t msg_type, 
                                   msg_header_t msg_id, 
                                   gamer::LuaFunction listener)
{
    this->removeMsgListenerForLua(msg_type, msg_id, listener);
}

void MsgManager::removeMsgListener(msg_header_t msg_type, gamer::LuaFunction listener)
{
    this->removeMsgListenerForLua(msg_type, (msg_header_t)MsgIDs::MSG_ID_UNKNOW, listener);
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
    // login
    msg_dispatchers_.insert(std::make_pair((int)MsgTypes::S2C_MSG_TYPE_LOGIN, 
        CALLBACK_SELECTOR_1(MsgManager::dealWithLoginMsg, this)));
    
    // room
    msg_dispatchers_.insert(std::make_pair((int)MsgTypes::C2S_MSG_TYPE_ROOM,
        CALLBACK_SELECTOR_1(MsgManager::dealWithRoomMsg, this)));
}

void MsgManager::addMsgHandlers()
{
    // login
    msg_handlers_.insert(std::make_pair((int)MsgIDs::MSG_ID_LOGIN_MY,
        CALLBACK_SELECTOR_1(MsgManager::dealWithMgLoginMsg, this)));

    // room
    // create room
    msg_handlers_.insert(std::make_pair((int)MsgIDs::MSG_ID_ROOM_CREATE,
        CALLBACK_SELECTOR_1(MsgManager::dealWithCreateRoomMsg, this)));
    
    // join room
    msg_handlers_.insert(std::make_pair((int)MsgIDs::MSG_ID_ROOM_PLAYER_JOIN,
        CALLBACK_SELECTOR_1(MsgManager::dealWithPlayerJoinRoomMsg, this)));

    // start game
    msg_handlers_.insert(std::make_pair((int)MsgIDs::MSG_ID_ROOM_START_GAME,
        CALLBACK_SELECTOR_1(MsgManager::dealWithStartGameMsg, this)));

    // play card
    msg_handlers_.insert(std::make_pair((int)MsgIDs::MSG_ID_ROOM_PLAY_CARD,
        CALLBACK_SELECTOR_1(MsgManager::dealWithPlayCardMsg, this)));
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

bool MsgManager::packMsg(msg_header_t msg_type, 
                         msg_header_t msg_id, 
                         const google::protobuf::Message& msg, 
                         char* buf, 
                         msg_header_t& len)
{
    auto len_total = gamer::client_msg_header_len() + msg.ByteSize();
    if (len_total > MsgManager::MAX_MSG_LEN) // TODO : log
        return false;

    len = len_total;

    memcpy(buf, &len_total, sizeof(msg_header_t));
    memcpy(buf + sizeof(msg_header_t), &msg_type, sizeof(msg_header_t));
    memcpy(buf + sizeof(msg_header_t) * 2, &msg_id, sizeof(msg_header_t));

    return msg.SerializeToArray(buf + gamer::client_msg_header_len(), msg.ByteSize());
}

bool MsgManager::parseMsg(const ServerMsg & server_msg, google::protobuf::Message* msg)
{
    if (nullptr == msg)
        return false; // TODO : log

    if (MsgCodes::MSG_RESPONSE_CODE_SUCCESS == (MsgCodes)server_msg.code &&
        nullptr != server_msg.context)
    {
        char buf[MsgManager::MAX_MSG_LEN] = { 0 };
        int len = server_msg.total_len - gamer::server_msg_header_len();
        return msg->ParseFromArray(server_msg.context, len);
    }

    return false;
}

bool MsgManager::doSendMsg(msg_header_t msg_type,
                           msg_header_t msg_id,
                           const google::protobuf::Message& msg)
{
    char buf[MsgManager::MAX_MSG_LEN] = { 0 };
    msg_header_t len_total = 0;
    auto ok = this->packMsg(msg_type, msg_id, msg, buf, len_total);
    if (ok)
    {
        return NetworkManager::getInstance()->send(buf, len_total);
    }

    return false;
}

std::string MsgManager::getMsgCallbackKey(msg_header_t msg_type, msg_header_t msg_id)
{
    char buf[gamer::client_msg_header_len()];
    snprintf(buf, sizeof(buf), "%d%d", msg_type, msg_id);
    return buf;
}

void MsgManager::addMsgListenerForLua(msg_header_t msg_type, 
                                      msg_header_t msg_id, 
                                      gamer::LuaFunction lua_cb)
{
    auto key = this->getMsgCallbackKey(msg_type, msg_id);
    auto itr = msg_response_lua_callbacks_.find(key);
    if (itr != msg_response_lua_callbacks_.end())
    {
        itr->second.insert(lua_cb);
    }
    else
    {
        std::unordered_set<gamer::LuaFunction> myset = { lua_cb };
        msg_response_lua_callbacks_.insert(std::make_pair(key, myset));
    }
}

void MsgManager::addMsgListenerForCpp(msg_header_t msg_type, 
                                      msg_header_t msg_id, 
                                      const MsgResponseCallback& cpp_cb)
{
    auto key = this->getMsgCallbackKey(msg_type, msg_id);
    auto itr = msg_response_cpp_callbacks_.find(key);
    if (itr != msg_response_cpp_callbacks_.end())
    {
        itr->second.push_back(cpp_cb);
    }
    else
    {
        std::vector<MsgResponseCallback> vec = { cpp_cb };
        msg_response_cpp_callbacks_.insert(std::make_pair(key, vec));
    }
}

void MsgManager::removeMsgListenerForLua(msg_header_t msg_type, 
                                         msg_header_t msg_id, 
                                         gamer::LuaFunction listener)
{
    auto key = this->getMsgCallbackKey(msg_type, msg_id);
    auto itr = msg_response_lua_callbacks_.find(key);
    if (itr != msg_response_lua_callbacks_.end())
    {
        itr->second.erase(listener);
    }
}

void MsgManager::removeMsgListenerForCpp(msg_header_t msg_type, 
                                         msg_header_t msg_id,
                                         const MsgResponseCallback& listener)
{
    auto key = this->getMsgCallbackKey(msg_type, msg_id);
    auto itr = msg_response_cpp_callbacks_.find(key);
    if (itr != msg_response_cpp_callbacks_.end())
    {
        //auto it = std::find(itr->second.begin(), itr->second.end(), listener); // operation == is not member function
        for (auto it = itr->second.begin(); it != itr->second.end(); it++)
        {
            // NOTE : not strictly right
            auto a = it->target<void(*)(int, msg_header_t, msg_header_t, 
                                        const google::protobuf::Message* msg)>();
            auto b = listener.target<void(*)(int, msg_header_t, msg_header_t, 
                                             const google::protobuf::Message* msg)>();
            if (a == b)
            {
                itr->second.erase(it);
                break;
            }
        }
    }
}

void MsgManager::dispatchMsg(int msg_code, 
                             msg_header_t msg_type,
                             msg_header_t msg_id,
                             const google::protobuf::Message* msg,
                             const std::string& class_name)
{
    //MsgResponseCallback cppcb = nullptr;
    //auto luacb                = -1;
    auto msgcode              = msg_code;
    auto msgtype              = msg_type;
    auto msgid                = msg_id;
    auto msgtmp               = msg;
    auto classname            = class_name;

    auto key = this->getMsgCallbackKey(msg_type, msg_id); // for specific msg
    auto key2 = this->getMsgCallbackKey(msg_type, (int)MsgIDs::MSG_ID_UNKNOW); // for one msg type
    //this->getMsgCallbacks(key, cppcb, luacb);

    auto callback = [=](float) {
        cocos2d::Director::getInstance()->getScheduler()->unschedule("dispatch_msg", this);

        // C++ callback
        auto itr1 = msg_response_cpp_callbacks_.find(key);
        if (itr1 != msg_response_cpp_callbacks_.end())
        {
            for (const MsgResponseCallback& cpp_cb : itr1->second)
            {
                cpp_cb(msgcode, msgtype, msgid, msgtmp);
            }
        }

        itr1 = msg_response_cpp_callbacks_.find(key2);
        if (itr1 != msg_response_cpp_callbacks_.end())
        {
            for (const MsgResponseCallback& cpp_cb : itr1->second)
            {
                cpp_cb(msgcode, msgtype, msgid, msgtmp);
            }
        }

        // Lua callback
        auto itr2 = msg_response_lua_callbacks_.find(key);
        if (itr2 != msg_response_lua_callbacks_.end())
        {
            for (gamer::LuaFunction lua_cb : itr2->second)
            {
                LuaBindHelper::getInstance()->dispatchMsg(lua_cb,
                                                          msgcode,
                                                          msgtype,
                                                          msgid,
                                                          msgtmp,
                                                          classname);
            }
        }

        itr2 = msg_response_lua_callbacks_.find(key2);
        if (itr2 != msg_response_lua_callbacks_.end())
        {
            for (gamer::LuaFunction lua_cb : itr2->second)
            {
                LuaBindHelper::getInstance()->dispatchMsg(lua_cb,
                                                          msgcode,
                                                          msgtype,
                                                          msgid,
                                                          msgtmp,
                                                          classname);
            }
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
	auto proto = DataManager::getInstance()->my_login_msg_protocol();
    if (this->parseMsg(msg, proto))
    {
        this->dispatchMsg(msg.code, msg.type, msg.id, proto, 
            "gamer::protocol::MyLoginMsgProtocol");
    }
    else
    {
        this->dispatchMsg(msg.code, msg.type, msg.id, nullptr, "");
        // TODO : log
    }
    
}

void MsgManager::dealWithRoomMsg(const ServerMsg& msg)
{
    auto itr = msg_handlers_.find((int)msg.id);
    if (itr != msg_handlers_.end())
    {
        itr->second(msg);
    }
}

void MsgManager::dealWithCreateRoomMsg(const ServerMsg& msg)
{
    auto proto = DataManager::getInstance()->create_room_msg_protocol();
    if (this->parseMsg(msg, proto))
    {
        this->dispatchMsg(msg.code, msg.type, msg.id, proto,
            "gamer::protocol::CreateRoomMsgProtocol");
    }
    else
    {
        this->dispatchMsg(msg.code, msg.type, msg.id, nullptr, "");
        // TODO : log
    }
}

void MsgManager::dealWithPlayerJoinRoomMsg(const ServerMsg& msg)
{
    gamer::protocol::RoomOperationMsgProtocol proto;
    if (this->parseMsg(msg, &proto))
    {
        this->dispatchMsg(msg.code, msg.type, msg.id, &proto,
            "gamer::protocol::RoomOperationMsgProtocol");
    }
    else
    {
        this->dispatchMsg(msg.code, msg.type, msg.id, nullptr, "");
        // TODO : log
    }
}

void MsgManager::dealWithStartGameMsg(const ServerMsg& msg)
{
    auto data_mgr = DataManager::getInstance();
    auto proto = data_mgr->room_msg_protocol();
    if ( !this->parseMsg(msg, proto) )
    {
        // TODO : log
        this->dispatchMsg(msg.code, msg.type, msg.id, nullptr, "");
        return;
    }

    // set cards for all players
    // player self
    auto self_player_id = data_mgr->self_player_id();
    auto n = proto->player_cards_size();
    auto index = 0;
    for (auto i = 0; i < n; i++)
    {
        if (self_player_id == proto->player_cards(i).player_id())
        {
            data_mgr->set_player_self_cards_index(i);
            index = i;
            break;
        }
    }
    // left player
    if (n > 2)
    {
        if (0 == index)
        {
            data_mgr->set_left_player_cards_index(n - 1);
        }
        else
        {
            data_mgr->set_left_player_cards_index(index - 1);
        }
    }
    // opposite player
    if (2 == n)
    {
        if (0 == index)
        {
            data_mgr->set_opposite_player_cards_index(1);
        }
        else
        {
            data_mgr->set_opposite_player_cards_index(0);
        }
    }
    else if (4 == n)
    {
        if (index < 2)
        {
            data_mgr->set_opposite_player_cards_index(index + 2);
        }
        else
        {
            data_mgr->set_opposite_player_cards_index(index - 2);
        }
    }
    // right player
    if (n > 2)
    {
        if (index < (n - 1))
        {
            data_mgr->set_right_player_cards_index(index + 1);
        }
        else
        {
            data_mgr->set_right_player_cards_index(0);
        }
    }
    
    // sort invisible hand cards of player self 
    auto cards = data_mgr->cards_msg_protocol_of_player_self()->mutable_invisible_hand_cards();
    std::sort(cards->begin(), cards->end());

    this->dispatchMsg(msg.code, msg.type, msg.id, proto, "gamer::protocol::RoomMsgProtocol");
}

void MsgManager::dealWithPlayCardMsg(const ServerMsg& msg)
{
    auto proto = DataManager::getInstance()->play_card_msg_protocol();
    if (this->parseMsg(msg, proto))
    {
        DataManager::getInstance()->updateCardAfterOperation(proto);

        this->dispatchMsg(msg.code, msg.type, msg.id, proto, 
            "gamer::protocol::PlayCardMsgProtocol");
    }
    else
    {
        this->dispatchMsg(msg.code, msg.type, msg.id, nullptr, "");
        // TODO : log
    }
}

void MsgManager::onSocketConnected(gamer::Event* event)
{

}

void MsgManager::onMsgReceived(const ServerMsg& msg)
{
    auto itr = msg_dispatchers_.find((int)msg.type);
    if (itr != msg_dispatchers_.end())
    {
        itr->second(msg);
    }
}

} // namespace gamer
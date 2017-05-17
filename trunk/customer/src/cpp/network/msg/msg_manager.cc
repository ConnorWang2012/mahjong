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
#include "macros.h"
#include "msg/msg_type.h"
#include "msg/msg_id.h"
#include "msg/protocol/my_login_msg_protocol.pb.h"
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

void MsgManager::init()
{
    auto l = EventListener::create((int)EventIDs::EVENT_ID_SOCKET_CONNECTED,
        CALLBACK_SELECTOR_1(MsgManager::onSocketConnected, this),
        "MsgManager::onSocketConnected",
        (int)Listener::ListenerPriorities::SENIOR);
    EventManager::getInstance()->addEventListener(l);
}

bool MsgManager::sendMsg(const Msg& msg, const MsgResponseCallback& response_cb)
{
    char buf[MsgManager::MAX_MSG_LEN] = { 0 };
    msg_header_t len = 0;
    this->packMsg(msg, buf, len);

    char key[sizeof(msg_header_t) * 2];
    snprintf(key, sizeof(key), "%d%d", msg.type, msg.id);
    msg_response_callbacks_.insert(std::make_pair(key, response_cb));

    return NetworkManager::getInstance()->send(buf, len);
}

void MsgManager::packMsg(const Msg& msg, char* buf, msg_header_t& len)
{
    auto len_total = gamer::msg_header_len();
    auto len_data = 0;
    if (msg.context) 
    {
        len_data = strlen((char*)msg.context);
        len_total += len_data;
    }

    len = len_total;

    memcpy(buf, &len_total, sizeof(msg_header_t));
    memcpy(buf + sizeof(msg_header_t), &msg.type, sizeof(msg_header_t));
    memcpy(buf + sizeof(msg_header_t) * 2, &msg.id, sizeof(msg_header_t));
    if (len_data > 0) 
    {
        memcpy(buf + gamer::msg_header_len(), msg.context, len_data);
    }
}

std::string MsgManager::getMsgCallbackKey(const Msg& msg)
{
    char buf[sizeof(msg_header_t) * 2];
    snprintf(buf, sizeof(buf), "%d%d", msg.type, msg.id);
    return buf;
}

void MsgManager::dealWithLoginMsg(const Msg& msg)
{
    printf("[MsgManager::DealWithLoginMsg] msg_type : %d, msg_id : %d", msg.type, msg.id);
    switch ((MsgIDs)msg.id) 
    {
    case MsgIDs::MSG_ID_LOGIN_MY: 
        {
            if (msg.context)
            {
                char buf[MsgManager::MAX_MSG_LEN] = { 0 };
                auto len = msg.total_len - gamer::msg_header_len();
                protocol::MyLoginMsgProtocol proto;
                proto.ParseFromArray(msg.context, len);

                auto key = this->getMsgCallbackKey(msg);
                auto itr = msg_response_callbacks_.find(key);
                if (itr != msg_response_callbacks_.end())
                {
                    itr->second(proto.code(), msg.type, msg.id, &proto);
                }
            }
        }
        break;
    default:
        break;
    }
}

void MsgManager::onSocketConnected(gamer::Event* event)
{
    char buf[MsgManager::MAX_MSG_LEN] = { 0 };
    protocol::MyLoginMsgProtocol proto;
    proto.set_account("2017");
    proto.set_password(2018);
    proto.SerializeToArray(buf, proto.ByteSize());

    auto len_total = gamer::msg_header_len() + proto.ByteSize();
    gamer::Msg msg = { len_total, 0, 1, buf };

    auto func = [&](int code, msg_header_t msg_type, msg_header_t msg_id, void* ctx) {
        printf("msg callback code : %d, msg_type : %d, msg_id : %d\n", code, msg_type, msg_id);
    };

    this->sendMsg(msg, func);
}

void MsgManager::onMsgReceived(const Msg& msg)
{
    switch ((MsgTypes)msg.type)
    {
    case MsgTypes::S2C_MSG_TYPE_LOGIN:
        {
            this->dealWithLoginMsg(msg);
        }
        break;
    default:
        break;
    }
}

} // namespace gamer
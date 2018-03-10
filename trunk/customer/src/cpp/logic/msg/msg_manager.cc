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

#include "macros.h"
#include "data_constants.h"
#include "player_constants.h"
#include "data_manager.h"
#include "event_headers.h"
#include "lua_bind_helper.h"
#include "mylog.h"
#include "msg_type.h"
#include "msg_id.h"
#include "msg_code.h"
#include "property_id.h"
#include "room_operation_msg_protocol.pb.h"
#include "network_manager.h"

namespace gamer
{

MsgManager::MsgManager() 
    : msg_dispatch_index_(0),
      is_multi_msg_(false)
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
	                            const gamer::LuaFunctionID& funtion_id)
{
	this->addMsgListenerForLua(msg_type, msg_id, funtion_id);
	LuaBindHelper::getInstance()->storeLuaFunction(funtion_id, 4);
}

void MsgManager::addMsgListener(msg_header_t msg_type, const gamer::LuaFunctionID& funtion_id)
{
	this->addMsgListenerForLua(msg_type, funtion_id);
	LuaBindHelper::getInstance()->storeLuaFunction(funtion_id, 3);
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
	                               const gamer::LuaFunctionID& function_id)
{
    this->removeMsgListenerForLua(msg_type, msg_id, function_id);
}

void MsgManager::removeMsgListener(msg_header_t msg_type, const gamer::LuaFunctionID& function_id)
{
    this->removeMsgListenerForLua(msg_type, function_id);
}

void MsgManager::init()
{
    auto listener = EventListener::create((id_t)EventIDs::EVENT_ID_SOCKET_CONNECTED,
        CALLBACK_SELECTOR_1(MsgManager::onSocketConnected, this),
        "MsgManager::onSocketConnected",
        (int)Listener::Priorities::SENIOR);
    EventManager::getInstance()->addEventListener(listener);

    this->addMsgDispatchHandlers();
    this->addMsgHandlers();
}

void MsgManager::addMsgDispatchHandlers()
{
    // login
    msg_dispatchers_.insert(std::make_pair((int)MsgTypes::S2C_MSG_TYPE_LOGIN, 
        CALLBACK_SELECTOR_1(MsgManager::dealWithLoginMsg, this)));
	
	// hall
	// property
	msg_dispatchers_.insert(std::make_pair((int)MsgTypes::S2C_MSG_TYPE_PROPERTY,
		CALLBACK_SELECTOR_1(MsgManager::dealWithPropertyMsg, this)));

    // room
    msg_dispatchers_.insert(std::make_pair((int)MsgTypes::S2C_MSG_TYPE_ROOM,
        CALLBACK_SELECTOR_1(MsgManager::dealWithRoomMsg, this)));
}

void MsgManager::addMsgHandlers()
{
    // login
    msg_handlers_.insert(std::make_pair((int)MsgIDs::MSG_ID_LOGIN_MY,
        CALLBACK_SELECTOR_1(MsgManager::dealWithMgLoginMsg, this)));

	// hall
	// property
	msg_handlers_.insert(std::make_pair((int)MsgIDs::MSG_ID_PROPERTY_GET_PLAYER_INFO,
		CALLBACK_SELECTOR_1(MsgManager::dealWithGetPlayerInfoMsg, this)));

	msg_handlers_.insert(std::make_pair((int)MsgIDs::MSG_ID_PROPERTY_SET,
		CALLBACK_SELECTOR_1(MsgManager::dealWithSetPropertyMsg, this)));

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

    // game end
    msg_handlers_.insert(std::make_pair((int)MsgIDs::MSG_ID_ROOM_GAME_END,
        CALLBACK_SELECTOR_1(MsgManager::dealWithGameEndMsg, this)));

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

bool MsgManager::parseMsg(const ServerMsg& server_msg, google::protobuf::Message* msg)
{
    if (nullptr == msg)
        return false; // TODO : log

    if (MsgCodes::MSG_CODE_SUCCESS == (MsgCodes)server_msg.code &&
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

std::string MsgManager::getKeyForStoreLuaCallback(msg_header_t msg_type, msg_header_t msg_id)
{
    char buf[16];
    snprintf(buf, sizeof(buf), "%d%d", msg_type, msg_id);
    return buf;
}

std::string MsgManager::getMsgDispatchKey()
{
    char buf[14];
    snprintf(buf, sizeof(buf), "m_dispatch%d", msg_dispatch_index_);
    msg_dispatch_index_++;
    if (msg_dispatch_index_ > 10)
    {
        msg_dispatch_index_ = 0;
    }
    return buf;
}

void MsgManager::addMsgListenerForLua(msg_header_t msg_type, 
                                      msg_header_t msg_id,
	                                  const std::string& function_id)
{
    auto key = this->getKeyForStoreLuaCallback(msg_type, msg_id);
   
	auto itr = lua_callbacks1_.find(key);
	if (itr != lua_callbacks1_.end())
	{
		if (itr->second.find(function_id) == itr->second.end())
		{
			itr->second.insert(function_id);
		}
	}
	else
	{
		std::unordered_set<std::string> set = { function_id };
		lua_callbacks1_.insert(std::make_pair(key, set));
	}
}

void MsgManager::addMsgListenerForLua(msg_header_t msg_type, const std::string& function_id)
{
	auto itr = lua_callbacks2_.find(msg_type);
	if (itr != lua_callbacks2_.end())
	{
		if (itr->second.find(function_id) == itr->second.end())
		{
			itr->second.insert(function_id);
		}
	}
	else
	{
		std::unordered_set<std::string> set = { function_id };
		lua_callbacks2_.insert(std::make_pair(msg_type, set));
	}
}

void MsgManager::addMsgListenerForCpp(msg_header_t msg_type, 
                                      msg_header_t msg_id, 
                                      const MsgResponseCallback& cpp_cb)
{
    auto key = this->getKeyForStoreLuaCallback(msg_type, msg_id);
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
	                                     const gamer::LuaFunctionID& function_id)
{
    auto key = this->getKeyForStoreLuaCallback(msg_type, msg_id);
    auto itr = lua_callbacks1_.find(key);
    if (itr != lua_callbacks1_.end())
    {
        auto it = itr->second.find(function_id);
		if (it != itr->second.end())
		{
			itr->second.erase(it);
		}
    }
}

void MsgManager::removeMsgListenerForLua(msg_header_t msg_type, 
	                                     const gamer::LuaFunctionID& function_id)
{
	auto itr = lua_callbacks2_.find(msg_type);
	if (itr != lua_callbacks2_.end())
	{
		auto it = itr->second.find(function_id);
		if (it != itr->second.end())
		{
			itr->second.erase(it);
		}
	}
}

void MsgManager::removeMsgListenerForCpp(msg_header_t msg_type, 
                                         msg_header_t msg_id,
                                         const MsgResponseCallback& listener)
{
    auto key = this->getKeyForStoreLuaCallback(msg_type, msg_id);
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
                             google::protobuf::Message* msg,
                             const std::string& class_name)
{
    if (nullptr == msg)
        return;

    if (this->is_multi_msg())
    {
        // push msg to msg queue
        auto msg_protocol = new MsgProtocol;
        msg_queue_.push(msg_protocol);
        msg_protocol->type          = msg_type;
        msg_protocol->id            = msg_id;
        msg_protocol->code          = msg_code;
        msg_protocol->msg           = msg->New();
        msg_protocol->msg->CopyFrom(*msg);
        msg_protocol->class_name    = class_name;
        msg_protocol->dispatch_key  = this->getMsgDispatchKey();
    }
    else
    {
        // callback for dispatching one msg
        auto callback = [=](float) {
            auto msgtype    = msg_type;
            auto msgid      = msg_id;
            auto msgcode    = msg_code;
            auto msgtmp     = msg;
            auto classname  = class_name;

            cocos2d::Director::getInstance()->getScheduler()->unschedule("s_dispatch", this);

			// deal with special msg
            if (msgid == (msg_header_t)MsgIDs::MSG_ID_ROOM_PLAY_CARD)
            {
                DataManager::getInstance()->updateCardAfterOperation(
                    dynamic_cast<gamer::protocol::PlayCardMsgProtocol*>(msgtmp));
            }

			this->callMsgCallbacks(msgcode, msgtype, msgid, msgtmp, classname);
        };

        // dispatch msg by UI thread(main thread)
        cocos2d::Director::getInstance()->getScheduler()->schedule(callback,
            this, 0, false, "s_dispatch");
    }
}

void MsgManager::callMsgCallbacks(int msg_code, msg_header_t 
	msg_type, msg_header_t msg_id, google::protobuf::Message* msg, const std::string& class_name)
{
	// c++ callbacks
	// callbacks added by msg type and msg id
	auto key = this->getKeyForStoreLuaCallback(msg_type, msg_id);
	auto itr1 = msg_response_cpp_callbacks_.find(key);
	if (itr1 != msg_response_cpp_callbacks_.end())
	{
		for (const MsgResponseCallback& cpp_cb : itr1->second)
		{
			cpp_cb(msg_code, msg_type, msg_id, msg);
		}
	}

	// TODO : call callbacks added by msg type

	// lua callbacks
	// callbacks added by msg type and msg id
	auto itr2 = lua_callbacks1_.find(key);
	if (itr2 != lua_callbacks1_.end())
	{
		for (std::string function_id : itr2->second)
		{
			LuaBindHelper::getInstance()->dispatchMsg(function_id,
				msg_code, msg_type, msg_id, msg, class_name);
		}
	}

	// callbacks added by msg type
	auto itr3 = lua_callbacks2_.find(msg_type);
	if (itr3 != lua_callbacks2_.end())
	{
		for (std::string function_id : itr3->second)
		{
			LuaBindHelper::getInstance()->dispatchMsg(function_id,
				msg_code, msg_type, msg_id, msg, class_name);
		}
	}
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

void MsgManager::dealWithPropertyMsg(const ServerMsg& msg)
{
	auto itr = msg_handlers_.find((int)msg.id);
	if (itr != msg_handlers_.end())
	{
		itr->second(msg);
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

void MsgManager::dealWithGetPlayerInfoMsg(const ServerMsg& msg)
{
	auto proto = DataManager::getInstance()->player_msg_protocol();
	if (this->parseMsg(msg, proto))
	{
		this->dispatchMsg(msg.code, msg.type, msg.id, proto,
			"gamer::protocol::PlayerMsgProtocol");
	}
	else
	{
		this->dispatchMsg(msg.code, msg.type, msg.id, nullptr, "");
	}
}

void MsgManager::dealWithSetPropertyMsg(const ServerMsg& msg)
{
	auto proto = DataManager::getInstance()->set_property_msg_protocol();
	if (this->parseMsg(msg, proto))
	{
		// modify player msg proto in my_login_msg_protocol
		auto player_proto = DataManager::getInstance()->my_login_msg_protocol()->player();
		for (auto i = 0; i < proto->property_ids_size(); i++)
		{
			auto prop_id = proto->property_ids(i);
			if (prop_id == (unsigned)gamer::PropertyIDs::PROP_ID_NICKNAME)
			{
				player_proto.set_nick_name(proto->new_properties(i));
			}
			else if (prop_id == (unsigned)gamer::PropertyIDs::PROP_ID_SEX)
			{				
				//player_proto.set_sex(proto->new_properties(i)); // TODO : string to int
			}
			else if (prop_id == (unsigned)gamer::PropertyIDs::PROP_ID_HEAD_PORTRAIT_LOCAL)
			{
				player_proto.set_head_portrait_type((unsigned)gamer::HeadPortraitTypes::LOCAL);
				//player_proto.set_head_portrait_id(proto->new_properties(i)); // TODO : string to int
			}
		}

		this->dispatchMsg(msg.code, msg.type, msg.id, proto,
			"gamer::protocol::SetPropertyMsgProtocol");
	}
	else
	{
		this->dispatchMsg(msg.code, msg.type, msg.id, nullptr, "");
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
    //proto->clear_player_cards();
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

void MsgManager::dealWithGameEndMsg(const ServerMsg& msg)
{
    auto proto = DataManager::getInstance()->game_end_msg_protocol();
    if (this->parseMsg(msg, proto))
    {
        this->dispatchMsg(msg.code, msg.type, msg.id, proto,
            "gamer::protocol::GameEndMsgProtocol");
    }
    else
    {
        this->dispatchMsg(msg.code, msg.type, msg.id, nullptr, "");
        // TODO : log
    }
}

void MsgManager::dealWithPlayCardMsg(const ServerMsg& msg)
{
    auto proto = DataManager::getInstance()->play_card_msg_protocol();
    if (this->parseMsg(msg, proto))
    {
        this->dispatchMsg(msg.code, msg.type, msg.id, proto, 
            "gamer::protocol::PlayCardMsgProtocol");
    }
    else
    {
        this->dispatchMsg(msg.code, msg.type, msg.id, nullptr, "");
        // TODO : log
    }
}

void MsgManager::dealWithMultiMsgDispatch(float dt)
{
    if (0 == msg_queue_.size())
    {
        gamer::writelog("[MsgManager::dispatchMsg] 0 == msg_queue_.size()");
        return;
    }

    auto msg_protocol = msg_queue_.front();

    if (msg_protocol->id == (msg_header_t)MsgIDs::MSG_ID_ROOM_PLAY_CARD)
    {
        DataManager::getInstance()->updateCardAfterOperation(
            dynamic_cast<gamer::protocol::PlayCardMsgProtocol*>(msg_protocol->msg));
    }

    cocos2d::Director::getInstance()->getScheduler()->unschedule(
        msg_protocol->dispatch_key, this);

	this->callMsgCallbacks(msg_protocol->code,
		                   msg_protocol->type,
		                   msg_protocol->id,
		                   msg_protocol->msg,
		                   msg_protocol->class_name);

    // delete msg from msg queue
    msg_queue_.pop();
    delete msg_protocol->msg;
    delete msg_protocol;

    // check whether msg queue has msg, if has, dispatch next msg
    if (msg_queue_.size() > 0)
    {
        cocos2d::Director::getInstance()->getScheduler()->schedule(
            CALLBACK_SELECTOR_1(MsgManager::dealWithMultiMsgDispatch, this), this, 0, false, 
            msg_queue_.front()->dispatch_key);
    }
}

void MsgManager::onSocketConnected(const gamer::Event& event)
{
}

void MsgManager::onOneMsgReceived(const ServerMsg& msg)
{
    auto itr = msg_dispatchers_.find((int)msg.type);
    if (itr != msg_dispatchers_.end())
    {
        itr->second(msg);
    }
}

void MsgManager::onMultiMsgReceived(const ServerMsg & msg)
{
	auto callback = [=](float) {
		cocos2d::Director::getInstance()->getScheduler()->unschedule("m_dispatch", this);

		this->dealWithMultiMsgDispatch(0);
	};

	// dispatch msg by UI thread(main thread)
	cocos2d::Director::getInstance()->getScheduler()->schedule(callback,
		this, 0, false, "m_dispatch");
}

} // namespace gamer

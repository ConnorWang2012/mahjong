/*******************************************************************************
@ copyright(C), 2015-2020, ConnorAndHisFriendsCompany.Inc
@ filename:	    data_manager.h
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

#include "data_manager.h"

#include "base/macros.h"
#include "data/data_constants.h"
#include "msg/protocol/my_login_msg_protocol.pb.h"
#include "msg/protocol/create_room_msg_protocol.pb.h"
#include "msg/protocol/room_msg_protocol.pb.h"

namespace gamer
{

DataManager::DataManager()
    :self_player_id_(0)
{

}

void DataManager::cacheData(int key, google::protobuf::Message* data) 
{
	auto data_old = this->getMutableData(key);
	if (nullptr != data_old)
	{
		this->releaseData(key, data_old);
	}
	this->setData(key, data);
}

google::protobuf::Message* DataManager::getMutableData(int key)
{
    auto itr = data_map_.find(key);
    if ( itr != data_map_.end())
    {
        return itr->second;
    }
    return nullptr;
}

const int DataManager::getSelfPlayerID()
{
    if (self_player_id_ <= 0)
    {
        auto key = (int)gamer::DataIDs::DATA_ID_MY_LOGIN_MSG_PROTOCOL;
        auto proto_login = DataManager::getInstance()->getMutableData(key);
        auto msg = dynamic_cast<protocol::MyLoginMsgProtocol*>(proto_login);
        self_player_id_ = msg->player().player_id();
    }
    return self_player_id_;
}

void DataManager::setData(int key, google::protobuf::Message* data)
{
	auto itr = data_map_.find(key);
	if (itr != data_map_.end())
	{
		itr->second = data;
	}
	else
	{
		data_map_.insert(std::make_pair(key, data));
	}
}

void DataManager::releaseData(int key, google::protobuf::Message* data)
{
	switch (key)
	{
	case (int)gamer::DataIDs::DATA_ID_MY_LOGIN_MSG_PROTOCOL:
		{
			auto proto = dynamic_cast<protocol::MyLoginMsgProtocol*>(data);
			SAFE_DELETE(proto);
		}
		break;
	case (int)gamer::DataIDs::DATA_ID_CREATE_ROOM_MSG_PROTOCOL:
		{
			auto proto = dynamic_cast<protocol::CreateRoomMsgProtocol*>(data);
			SAFE_DELETE(proto);
		}
		break;
	case (int)gamer::DataIDs::DATA_ID_ROOM_MSG_PROTOCOL:
		{
			auto proto = dynamic_cast<protocol::RoomMsgProtocol*>(data);
            proto->mutable_player_cards()->DeleteSubrange(0, proto->player_cards_size());
            SAFE_DELETE(proto);
		}
		break;
	default:
		break;
	}
}

} // namespace gamer
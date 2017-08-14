/*******************************************************************************
@ copyright(C), 2015-2020, ConnorAndHisFriendsCompany.Inc
@ filename:	    data_manager.h
@ author:	    Connor
@ version:	    1.0.0
@ date:		    2017-05-01
@ description:  data manager.
@ others:
@ history:
1.date:
author:
modification:
********************************************************************************/

#ifndef CONNOR_GAME_SRC_DATA_MANAGER_H_
#define CONNOR_GAME_SRC_DATA_MANAGER_H_

#include <unordered_map>

#include "base/basic_manager.h"
#include "msg/protocol/my_login_msg_protocol.pb.h"
#include "msg/protocol/create_room_msg_protocol.pb.h"
#include "msg/protocol/room_msg_protocol.pb.h"
#include "msg/protocol/player_cards_msg_protocol.pb.h"

namespace google
{

//namespace protobuf
//{
//    class Message;
//}

}

namespace gamer
{

//namespace protocol
//{
//    class MyLoginMsgProtocol;
//    class CreateRoomMsgProtocol;
//    class RoomMsgProtocol;
//    class PlayerCardsMsgProtocol;
//}

class DataManager : public BasicManager<DataManager>
{
public:
    DataManager();

    template<typename DataType>
    DataType* createData();

    inline void set_my_login_msg_protocol(gamer::protocol::MyLoginMsgProtocol* proto);

    inline gamer::protocol::MyLoginMsgProtocol* my_login_msg_protocol();

    inline void set_create_room_msg_protocol(gamer::protocol::CreateRoomMsgProtocol* p);

    inline gamer::protocol::CreateRoomMsgProtocol* create_room_msg_protocol();

    inline void set_room_msg_protocol(gamer::protocol::RoomMsgProtocol* proto);

    inline gamer::protocol::RoomMsgProtocol* room_msg_protocol();

    inline void set_cards_msg_protocol_of_player_self(protocol::PlayerCardsMsgProtocol* p);

    inline gamer::protocol::PlayerCardsMsgProtocol* cards_msg_protocol_of_player_self();

    inline void set_cards_msg_protocol_of_left_player(protocol::PlayerCardsMsgProtocol* p);

    inline gamer::protocol::PlayerCardsMsgProtocol* cards_msg_protocol_of_left_player();

    inline void set_cards_msg_protocol_of_opposite_player(protocol::PlayerCardsMsgProtocol* p);

    inline gamer::protocol::PlayerCardsMsgProtocol* cards_msg_protocol_of_opposite_player();

    inline void set_cards_msg_protocol_of_right_player(protocol::PlayerCardsMsgProtocol* p);

    inline gamer::protocol::PlayerCardsMsgProtocol* cards_msg_protocol_of_right_player();

    inline int self_player_id() const;

    inline int left_player_id() const;

    inline int opposite_player_id() const;

    inline int right_player_id() const;

    void updateCardForDiscard(int discard);

    void updateInvisibleHandCard(int new_card);

private:
    // keep the ownership
    gamer::protocol::MyLoginMsgProtocol* my_login_msg_protocol_;
    gamer::protocol::CreateRoomMsgProtocol* create_room_msg_protocol_;
    gamer::protocol::RoomMsgProtocol* room_msg_protocol_;
    // not keep the ownership
    gamer::protocol::PlayerCardsMsgProtocol* cards_msg_proto_of_player_self_;
    gamer::protocol::PlayerCardsMsgProtocol* cards_msg_proto_of_left_player_;
    gamer::protocol::PlayerCardsMsgProtocol* cards_msg_proto_of_opposite_player_;
    gamer::protocol::PlayerCardsMsgProtocol* cards_msg_proto_of_right_player_;
};

template<typename DataType>
inline DataType* DataManager::createData()
{
    return new DataType;
}

inline void DataManager::set_my_login_msg_protocol(gamer::protocol::MyLoginMsgProtocol* proto)
{
    my_login_msg_protocol_ = proto;
}

inline gamer::protocol::MyLoginMsgProtocol* DataManager::my_login_msg_protocol()
{
    return my_login_msg_protocol_;
}

inline void DataManager::set_create_room_msg_protocol(gamer::protocol::CreateRoomMsgProtocol* p)
{
    create_room_msg_protocol_ = p;
}

inline gamer::protocol::CreateRoomMsgProtocol* DataManager::create_room_msg_protocol()
{
    return create_room_msg_protocol_;
}

inline void DataManager::set_room_msg_protocol(gamer::protocol::RoomMsgProtocol* proto)
{
    room_msg_protocol_ = proto;
}

inline gamer::protocol::RoomMsgProtocol* DataManager::room_msg_protocol()
{
    return room_msg_protocol_;
}

inline void DataManager::set_cards_msg_protocol_of_player_self(protocol::PlayerCardsMsgProtocol* p)
{
    cards_msg_proto_of_player_self_ = p;
}

inline gamer::protocol::PlayerCardsMsgProtocol* DataManager::cards_msg_protocol_of_player_self()
{
    return cards_msg_proto_of_player_self_;
}

inline void DataManager::set_cards_msg_protocol_of_left_player(protocol::PlayerCardsMsgProtocol* p)
{
    cards_msg_proto_of_left_player_ = p;
}

inline gamer::protocol::PlayerCardsMsgProtocol* DataManager::cards_msg_protocol_of_left_player()
{
    return cards_msg_proto_of_left_player_;
}

inline void DataManager::set_cards_msg_protocol_of_opposite_player(protocol::PlayerCardsMsgProtocol* p)
{
    cards_msg_proto_of_opposite_player_ = p;
}

inline gamer::protocol::PlayerCardsMsgProtocol* DataManager::cards_msg_protocol_of_opposite_player()
{
    return cards_msg_proto_of_opposite_player_;
}

inline void DataManager::set_cards_msg_protocol_of_right_player(protocol::PlayerCardsMsgProtocol* p)
{
    cards_msg_proto_of_right_player_ = p;
}

inline gamer::protocol::PlayerCardsMsgProtocol* DataManager::cards_msg_protocol_of_right_player()
{
    return cards_msg_proto_of_right_player_;
}

inline int DataManager::self_player_id() const
{
    if (my_login_msg_protocol_)
    {
        return my_login_msg_protocol_->player().player_id();
    }
    return 0;
}

inline int DataManager::left_player_id() const
{
    if (cards_msg_proto_of_left_player_)
    {
        return cards_msg_proto_of_left_player_->player_id();
    }
    return 0;
}

inline int DataManager::opposite_player_id() const
{
    if (cards_msg_proto_of_opposite_player_)
    {
        return cards_msg_proto_of_opposite_player_->player_id();
    }
    return 0;
}

inline int DataManager::right_player_id() const
{
    if (cards_msg_proto_of_right_player_)
    {
        return cards_msg_proto_of_right_player_->player_id();
    }
    return 0;
}

} // namespace gamer

#endif // CONNOR_GAME_SRC_DATA_MANAGER_H_

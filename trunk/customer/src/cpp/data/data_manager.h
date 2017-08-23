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
#include "msg/protocol/play_card_msg_protocol.pb.h"

namespace gamer
{

class DataManager : public BasicManager<DataManager>
{
public:
    DataManager();

    inline gamer::protocol::MyLoginMsgProtocol* my_login_msg_protocol();

    inline gamer::protocol::CreateRoomMsgProtocol* create_room_msg_protocol();

    inline gamer::protocol::RoomMsgProtocol* room_msg_protocol();

    inline protocol::PlayCardMsgProtocol* play_card_msg_protocol();

    inline gamer::protocol::PlayerCardsMsgProtocol* cards_msg_protocol_of_player_self();

    inline gamer::protocol::PlayerCardsMsgProtocol* cards_msg_protocol_of_left_player();

    inline gamer::protocol::PlayerCardsMsgProtocol* cards_msg_protocol_of_opposite_player();

    inline gamer::protocol::PlayerCardsMsgProtocol* cards_msg_protocol_of_right_player();

    inline void set_player_self_cards_index(int index);

    inline void set_left_player_cards_index(int index);

    inline void set_opposite_player_cards_index(int index);

    inline void set_right_player_cards_index(int index);

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
    gamer::protocol::PlayCardMsgProtocol* play_card_msg_protocol_;

    int player_self_cards_index_;
    int left_player_cards_index_;
    int opposite_player_cards_index_;
    int right_player_cards_index_ = 0;
};

inline gamer::protocol::MyLoginMsgProtocol* DataManager::my_login_msg_protocol()
{
    if (nullptr == my_login_msg_protocol_)
    {
        my_login_msg_protocol_ = new protocol::MyLoginMsgProtocol;
    }
    return my_login_msg_protocol_;
}

inline gamer::protocol::CreateRoomMsgProtocol* DataManager::create_room_msg_protocol()
{
    if (nullptr == create_room_msg_protocol_)
    {
        create_room_msg_protocol_ = new protocol::CreateRoomMsgProtocol;
    }
    return create_room_msg_protocol_;
}

inline gamer::protocol::RoomMsgProtocol* DataManager::room_msg_protocol()
{
    if (nullptr == room_msg_protocol_)
    {
        room_msg_protocol_ = new protocol::RoomMsgProtocol;
    }
    return room_msg_protocol_;
}

inline protocol::PlayCardMsgProtocol* DataManager::play_card_msg_protocol()
{
    if (nullptr == play_card_msg_protocol_)
    {
        play_card_msg_protocol_ = new protocol::PlayCardMsgProtocol;
        // init next operating player id
        if (nullptr != room_msg_protocol_)
        {
            play_card_msg_protocol_->set_next_operate_player_id(room_msg_protocol_->room_owner_id());
        }
    }
    return play_card_msg_protocol_;
}

inline gamer::protocol::PlayerCardsMsgProtocol* DataManager::cards_msg_protocol_of_player_self()
{
    if (nullptr != room_msg_protocol_)
    {
        return room_msg_protocol_->mutable_player_cards(player_self_cards_index_);
    }
    return nullptr;
}

inline gamer::protocol::PlayerCardsMsgProtocol* DataManager::cards_msg_protocol_of_left_player()
{
    if (nullptr != room_msg_protocol_)
    {
        return room_msg_protocol_->mutable_player_cards(left_player_cards_index_);
    }
    return nullptr;
}

inline gamer::protocol::PlayerCardsMsgProtocol* DataManager::cards_msg_protocol_of_opposite_player()
{
    if (nullptr != room_msg_protocol_)
    {
        return room_msg_protocol_->mutable_player_cards(opposite_player_cards_index_);
    }
    return nullptr;
}

inline gamer::protocol::PlayerCardsMsgProtocol* DataManager::cards_msg_protocol_of_right_player()
{
    if (nullptr != room_msg_protocol_)
    {
        return room_msg_protocol_->mutable_player_cards(right_player_cards_index_);
    }
    return nullptr;
}

inline void DataManager::set_player_self_cards_index(int index)
{
    player_self_cards_index_ = index;
}

inline void DataManager::set_left_player_cards_index(int index)
{
    left_player_cards_index_ = index;
}

inline void DataManager::set_opposite_player_cards_index(int index)
{
    opposite_player_cards_index_ = index;
}

inline void DataManager::set_right_player_cards_index(int index)
{
    right_player_cards_index_ = index;
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
    if (nullptr != room_msg_protocol_)
    {
        return room_msg_protocol_->player_cards(player_self_cards_index_).player_id();
    }
    return 0;
}

inline int DataManager::opposite_player_id() const
{
    if (nullptr != room_msg_protocol_)
    {
        return room_msg_protocol_->player_cards(opposite_player_cards_index_).player_id();
    }
    return 0;
}

inline int DataManager::right_player_id() const
{
    if (nullptr != room_msg_protocol_)
    {
        return room_msg_protocol_->player_cards(right_player_cards_index_).player_id();
    }
    return 0;
}

} // namespace gamer

#endif // CONNOR_GAME_SRC_DATA_MANAGER_H_

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

#include "macros.h"
#include "basic_manager.h"
#include "card_constants.h"
#include "my_login_msg_protocol.pb.h"
#include "create_room_msg_protocol.pb.h"
#include "room_msg_protocol.pb.h"
#include "player_cards_msg_protocol.pb.h"
#include "play_card_msg_protocol.pb.h"
#include "game_end_msg_protocol.pb.h"

namespace gamer
{

class DataManager : public BasicManager<DataManager>
{
public:
    typedef gamer::protocol::MyLoginMsgProtocol     MyLoginMsgProtocol;
    typedef gamer::protocol::CreateRoomMsgProtocol  CreateRoomMsgProtocol;
    typedef gamer::protocol::RoomMsgProtocol        RoomMsgProtocol;
    typedef gamer::protocol::PlayerCardsMsgProtocol PlayerCardsMsgProtocol;
    typedef gamer::protocol::PlayCardMsgProtocol    PlayCardMsgProtocol;
    typedef gamer::protocol::GameEndMsgProtocol     GameEndMsgProtocol;

    DataManager();

    inline MyLoginMsgProtocol* my_login_msg_protocol();

    inline CreateRoomMsgProtocol* create_room_msg_protocol();

    inline RoomMsgProtocol* room_msg_protocol();

    inline PlayCardMsgProtocol* play_card_msg_protocol();

    inline GameEndMsgProtocol* game_end_msg_protocol();

    inline PlayerCardsMsgProtocol* cards_msg_protocol_of_player_self();

    inline PlayerCardsMsgProtocol* cards_msg_protocol_of_left_player();

    inline PlayerCardsMsgProtocol* cards_msg_protocol_of_opposite_player();

    inline PlayerCardsMsgProtocol* cards_msg_protocol_of_right_player();

    inline void set_player_self_cards_index(int index);

    inline void set_left_player_cards_index(int index);

    inline void set_opposite_player_cards_index(int index);

    inline void set_right_player_cards_index(int index);

    inline int self_player_id() const;

    inline int left_player_id() const;

    inline int opposite_player_id() const;

    inline int right_player_id() const;

    void updateCardAfterOperation(PlayCardMsgProtocol* proto);

    void updateCardForDiscardOfPlayerSelf(int discard);

    void updateCardForDiscard(id_t player_id, int discard);

    void updateCardForChi(id_t player_id,
                          int card_of_chi,
                          int card_match_chi_1,
                          int card_match_chi_2);

    void updateCardForPeng(id_t player_id, int card_of_peng);

    void updateCardForPengAndGang(id_t player_id, int card_of_peng_gang);

    void updateCardForMingGang(id_t player_id, int card_of_ming_gang);

    void updateCardForAnGang(id_t player_id, int card_of_an_gang);

    void updateCardForBuhua(id_t player_id);

    void updateCardForHu(id_t player_id);

private:
    typedef google::protobuf::RepeatedField<google::protobuf::int32> RepeatedField;

    PlayerCardsMsgProtocol* getPlayerCardsMsgProtocol(id_t player_id);

    void updateCardForNewCardOfPlayerSelf(int new_card);

    void updateCardForNewCardOfOtherPlayer(id_t player_id);

    void updateCardForDiscardOfOtherPlayer(id_t player_id, int discard);

    int countInvisibleCard(PlayerCardsMsgProtocol* proto, int card) const;

    int countCard(RepeatedField* repeated_field, int card) const;

    void removeInvisibleCards(PlayerCardsMsgProtocol* proto, int card, int num);

    void removeCards(RepeatedField* repeated_field, int card, int num);

    inline bool is_season_or_flower(int card) const;

    inline bool is_season(int card) const;

    inline bool is_flower(int card) const;

    // keep the ownership
    MyLoginMsgProtocol*     my_login_msg_protocol_;
    CreateRoomMsgProtocol*  create_room_msg_protocol_;
    RoomMsgProtocol*        room_msg_protocol_;
    PlayCardMsgProtocol*    play_card_msg_protocol_;
    GameEndMsgProtocol*     game_end_msg_protocol_;

    int player_self_cards_index_;
    int left_player_cards_index_;
    int opposite_player_cards_index_;
    int right_player_cards_index_ = 0;
};

inline DataManager::MyLoginMsgProtocol* DataManager::my_login_msg_protocol()
{
    if (nullptr == my_login_msg_protocol_)
    {
        my_login_msg_protocol_ = new MyLoginMsgProtocol;
    }
    return my_login_msg_protocol_;
}

inline DataManager::CreateRoomMsgProtocol* DataManager::create_room_msg_protocol()
{
    if (nullptr == create_room_msg_protocol_)
    {
        create_room_msg_protocol_ = new CreateRoomMsgProtocol;
    }
    return create_room_msg_protocol_;
}

inline DataManager::RoomMsgProtocol* DataManager::room_msg_protocol()
{
    if (nullptr == room_msg_protocol_)
    {
        room_msg_protocol_ = new RoomMsgProtocol;
    }
    return room_msg_protocol_;
}

inline DataManager::PlayCardMsgProtocol* DataManager::play_card_msg_protocol()
{
    if (nullptr == play_card_msg_protocol_)
    {
        play_card_msg_protocol_ = new PlayCardMsgProtocol;
        // init next operating player id
        if (nullptr != room_msg_protocol_)
        {
            play_card_msg_protocol_->set_next_operate_player_id(room_msg_protocol_->room_owner_id());
        }
    }
    return play_card_msg_protocol_;
}

inline DataManager::GameEndMsgProtocol* DataManager::game_end_msg_protocol()
{
    if (nullptr == game_end_msg_protocol_)
    {
        game_end_msg_protocol_ = new GameEndMsgProtocol;
    }
    return game_end_msg_protocol_;
}

inline DataManager::PlayerCardsMsgProtocol* DataManager::cards_msg_protocol_of_player_self()
{
    if (nullptr != room_msg_protocol_)
    {
        return room_msg_protocol_->mutable_player_cards(player_self_cards_index_);
    }
    return nullptr;
}

inline DataManager::PlayerCardsMsgProtocol* DataManager::cards_msg_protocol_of_left_player()
{
    if (nullptr != room_msg_protocol_)
    {
        return room_msg_protocol_->mutable_player_cards(left_player_cards_index_);
    }
    return nullptr;
}

inline DataManager::PlayerCardsMsgProtocol* DataManager::cards_msg_protocol_of_opposite_player()
{
    if (nullptr != room_msg_protocol_)
    {
        return room_msg_protocol_->mutable_player_cards(opposite_player_cards_index_);
    }
    return nullptr;
}

inline DataManager::PlayerCardsMsgProtocol* DataManager::cards_msg_protocol_of_right_player()
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
        return room_msg_protocol_->player_cards(left_player_cards_index_).player_id();
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

inline bool DataManager::is_season_or_flower(int card) const {
    if (card >= CardConstants::SEASON_SPRING && card <= CardConstants::FLOWER_BAMBOO) {
        return true;
    }
    return false;
}

inline bool DataManager::is_season(int card) const {
    if (card >= CardConstants::SEASON_SPRING && card <= CardConstants::SEASON_WINTER) {
        return true;
    }
    return false;
}

inline bool DataManager::is_flower(int card) const {
    if (card >= CardConstants::FLOWER_PLUM && card <= CardConstants::FLOWER_BAMBOO) {
        return true;
    }
    return false;
}

} // namespace gamer

#endif // CONNOR_GAME_SRC_DATA_MANAGER_H_

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
#include "logic/constant/card_constants.h"

namespace gamer
{

DataManager::DataManager()
    :my_login_msg_protocol_(nullptr)
    ,create_room_msg_protocol_(nullptr)
    ,room_msg_protocol_(nullptr)
    ,play_card_msg_protocol_(nullptr)
    ,player_self_cards_index_(0)
    ,left_player_cards_index_(0)
    ,opposite_player_cards_index_(0)
    ,right_player_cards_index_(0)
{

}

void DataManager::updateCardForDiscard(int discard)
{
    auto proto = this->cards_msg_protocol_of_player_self();
    if (nullptr != proto)
    {
        // remove the discard from invisible hand cards
        auto cards = proto->mutable_invisible_hand_cards();
        auto n = cards->size();
        for (int i = 0; i < n; i++) {
            if (cards->Get(i) == discard) {
                if (i != n - 1) {
                    cards->SwapElements(i, n - 1);
                }
                cards->RemoveLast();
                break;
            }
        }

        // add the discard to discards or season cards or flower cards
        if (discard > CardConstants::INVALID_CARD_VALUE && 
            discard < CardConstants::SEASON_SPRING) 
        {
            proto->add_discards(discard);
        }
        else if (discard >= CardConstants::SEASON_SPRING &&
                 discard <= CardConstants::SEASON_WINTER) 
        {
            proto->add_season_cards(discard);
        }
        else if (discard >= CardConstants::FLOWER_PLUM &&
                 discard <= CardConstants::FLOWER_BAMBOO) {
            proto->add_flower_cards(discard);
        }
    }

    // update remain card
    if (nullptr != room_msg_protocol_)
    {
        auto size = room_msg_protocol_->remain_cards_size();
        if (size > 0) 
        {
            room_msg_protocol_->mutable_remain_cards()->RemoveLast();
        }
    }
}

void DataManager::updateInvisibleHandCard(int new_card)
{
    auto proto = this->cards_msg_protocol_of_player_self();
    if (nullptr != proto)
    {
        if (proto->invisible_hand_cards_size() <= CardConstants::ONE_PLAYER_CARD_NUM) {
            proto->add_invisible_hand_cards(new_card);
        }
    }
}

} // namespace gamer
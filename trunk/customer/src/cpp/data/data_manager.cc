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
    ,cards_msg_proto_of_player_self_(nullptr)
    ,cards_msg_proto_of_left_player_(nullptr)
    ,cards_msg_proto_of_opposite_player_(nullptr)
    ,cards_msg_proto_of_right_player_(nullptr)
{

}

void DataManager::updateCardForDiscard(int discard)
{
    if (nullptr == cards_msg_proto_of_player_self_)
        return;

    // remove the discard from invisible hand cards
    auto cards = cards_msg_proto_of_player_self_->mutable_invisible_hand_cards();
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

    // add the discard to discards
    cards_msg_proto_of_player_self_->add_discards(discard);
}

void DataManager::updateInvisibleHandCard(int new_card)
{
    auto n = cards_msg_proto_of_player_self_->invisible_hand_cards_size();
    if (n <= CardConstants::ONE_PLAYER_CARD_NUM) {
        cards_msg_proto_of_player_self_->add_invisible_hand_cards(new_card);
    }
}


} // namespace gamer
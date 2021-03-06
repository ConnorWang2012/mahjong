﻿/*******************************************************************************
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

#include "macros.h"
#include "data_constants.h"

namespace gamer
{

DataManager::DataManager()
    : my_login_msg_protocol_(nullptr),
	  player_msg_protocol_(nullptr),
	  set_property_msg_protocol_(nullptr),
	  create_room_msg_protocol_(nullptr),
	  room_msg_protocol_(nullptr),
	  play_card_msg_protocol_(nullptr),
	  player_self_cards_index_(0),
	  left_player_cards_index_(0),
	  opposite_player_cards_index_(0),
	  right_player_cards_index_(0)
{

}

void DataManager::updateCardAfterOperation(PlayCardMsgProtocol* proto)
{
    if (nullptr == proto)
        return;

    // update other player cards
    if (proto->player_id() != this->self_player_id())
    {
        switch (proto->operation_id())
        {
        case PlayCardOperationIDs::OPERATION_DISCARD:
        {
            this->updateCardForDiscard(proto->player_id(), proto->discard());
            break;
        }
        case PlayCardOperationIDs::OPERATION_CHI:
        {
            this->updateCardForChi(proto->player_id(), proto->discard(),
                proto->operating_cards(0), proto->operating_cards(1));
            break;
        }
        case PlayCardOperationIDs::OPERATION_PENG:
        {
            this->updateCardForPeng(proto->player_id(), proto->discard());
            break;
        }
        case PlayCardOperationIDs::OPERATION_PENG_GANG:
        {
            this->updateCardForPengAndGang(proto->player_id(), proto->discard());
            break;
        }
        case PlayCardOperationIDs::OPERATION_MING_GANG:
        {
            this->updateCardForMingGang(proto->player_id(), proto->discard());
            break;
        }
        case PlayCardOperationIDs::OPERATION_AN_GANG:
        {
            this->updateCardForAnGang(proto->player_id(), proto->discard());
            break;
        }
        case PlayCardOperationIDs::OPERATION_BU_HUA:
        {
            this->updateCardForBuhua(proto->player_id());
            break;
        }
        case PlayCardOperationIDs::OPERATION_HU:
        {
            this->updateCardForHu(proto->player_id());
            break;
        }
        default:
            break;
        }
    }

    // update new cards and remain cards
    if (proto->next_operate_player_id() == this->self_player_id())
    {
        // 1.update new cards and remain cards for player self
        // player self get one new card
        if (proto->new_card() != CardConstants::INVALID_CARD_VALUE)
        {
            this->updateCardForNewCardOfPlayerSelf(proto->new_card());
			auto table = room_msg_protocol_->mutable_table_list(0);
            auto num = table->remain_cards_num() - 1;
            if (num >= 0)
            {
				table->set_remain_cards_num(num);
            }
        }

        // after buhua, player self get some new cards whose stored in operating_cards
        if (proto->operation_id() == PlayCardOperationIDs::OPERATION_BU_HUA)
        {
            for (int i = 0; i < proto->operating_cards_size(); i++)
            {
                this->updateCardForNewCardOfPlayerSelf(proto->operating_cards(i));
            }
        }
    }
    else if (proto->next_operate_player_id() != 0)
    {
        // 2.update new cards and remain cards for other player
        if (proto->has_next_operate_player_new_card())
        {
            this->updateCardForNewCardOfOtherPlayer(proto->next_operate_player_id());
			auto table = room_msg_protocol_->mutable_table_list(0);
			auto num = table->remain_cards_num() - 1;
            if (num >= 0)
            {
				table->set_remain_cards_num(num);
            }
        }
    }
}

void DataManager::updateCardForDiscardOfPlayerSelf(card_t discard)
{
    if (discard == CardConstants::INVALID_CARD_VALUE)
        return;

    auto proto = this->cards_msg_protocol_of_player_self();
    if (nullptr != proto)
    {
        // remove the discard from invisible hand cards
        auto cards = proto->mutable_invisible_hand_cards();
        auto n = cards->size();
        auto ok = false;
        for (int i = 0; i < n; i++) {
            if (cards->Get(i) == discard) {
                if (i != n - 1) {
                    cards->SwapElements(i, n - 1);
                }
                cards->RemoveLast();
                ok = true;
                break;
            }
        }

        // add the discard to discards and sort invisible hand cards
        if (ok)
        {
            if (discard > CardConstants::INVALID_CARD_VALUE &&
                discard < CardConstants::SEASON_SPRING)
            {
                proto->add_discards(discard);
            }

            auto cards = proto->mutable_invisible_hand_cards();
            std::sort(cards->begin(), cards->end());
        }
    }
}

void DataManager::updateCardForNewCardOfPlayerSelf(card_t new_card)
{
    auto proto = this->cards_msg_protocol_of_player_self();
    if (nullptr != proto)
    {
        if (proto->invisible_hand_cards_size() <= CardConstants::ONE_PLAYER_CARD_NUM) 
        {
            proto->add_invisible_hand_cards(new_card);
        }
    }
}

void DataManager::updateCardForNewCardOfOtherPlayer(player_id_t player_id)
{
    auto proto = this->getPlayerCardsMsgProtocol(player_id);
    if (proto)
    {
        auto size = proto->invisible_hand_cards_num() + 1;
        if (size <= CardConstants::ONE_PLAYER_CARD_NUM2)
        {
            proto->set_invisible_hand_cards_num(size);
        }
    }
}

void DataManager::updateCardForDiscard(player_id_t player_id, card_t discard)
{
    if (player_id == this->self_player_id())
    {
        this->updateCardForDiscardOfPlayerSelf(discard);
    }
    else
    {
        this->updateCardForDiscardOfOtherPlayer(player_id, discard);
    }
}

void DataManager::updateCardForChi(player_id_t player_id, 
                                   int card_of_chi, 
                                   int card_match_chi_1, 
                                   int card_match_chi_2)
{
    auto proto = this->getPlayerCardsMsgProtocol(player_id);
    if (nullptr != proto)
    {
        // add 3 cards to chi cards
        auto min = std::min(std::min(card_of_chi, card_match_chi_1), card_match_chi_2);
        proto->add_chi_cards(min);
        proto->add_chi_cards(min + 1);
        proto->add_chi_cards(min + 2);

        // for player self: remove 2 cards from invisible cards
        // for other player: reduce 2 for invisible_hand_cards_num
        if (this->self_player_id() == player_id)
        {
            if (nullptr != play_card_msg_protocol_)
            {
                auto discard = play_card_msg_protocol_->discard(); // discard is the card of chi
                if (card_of_chi != discard)
                {
                    this->removeInvisibleCards(proto, card_of_chi, 1);
                }
                if (card_match_chi_1 != discard)
                {
                    this->removeInvisibleCards(proto, card_match_chi_1, 1);
                }
                if (card_match_chi_2 != discard)
                {
                    this->removeInvisibleCards(proto, card_match_chi_2, 1);
                }

                auto cards = proto->mutable_invisible_hand_cards();
                std::sort(cards->begin(), cards->end());
            }
        }
        else
        {
            auto size = proto->invisible_hand_cards_num() - 2;
            if (size > 0)
            {
                proto->set_invisible_hand_cards_num(size);
            }
        }
    }
}

void DataManager::updateCardForPeng(player_id_t player_id, card_t card_of_peng)
{
    auto proto = this->getPlayerCardsMsgProtocol(player_id);
    if (nullptr != proto)
    {
        // for player self: add 3 cards to peng cards and remove 2 cards from invisible cards
        // for other player: add 3 cards to peng cards and reduce 2 for invisible_hand_cards_num
        proto->mutable_peng_cards()->Resize(proto->peng_cards_size() + 3, card_of_peng);
        if (this->self_player_id() == player_id)
        {
            this->removeInvisibleCards(proto, card_of_peng, 2);
            auto cards = proto->mutable_invisible_hand_cards();
            std::sort(cards->begin(), cards->end());
        }
        else
        {
            auto size = proto->invisible_hand_cards_num() - 2;
            if (size > 0)
            {
                proto->set_invisible_hand_cards_num(size);
            }
        }
    }
}

void DataManager::updateCardForPengAndGang(player_id_t player_id, card_t card_of_peng_gang)
{
    auto proto = this->getPlayerCardsMsgProtocol(player_id);
    if (nullptr != proto)
    {
        // for player self: add 4 peng cards to ming gang cards and remove 3 cards from invisible cards
        // for other player: add 4 peng cards to ming gang cards and reduce 3 for invisible_hand_cards_num
        proto->mutable_ming_gang_cards()->Resize(proto->ming_gang_cards_size() + 4,
            card_of_peng_gang);
        if (this->self_player_id() == player_id)
        {
            this->removeInvisibleCards(proto, card_of_peng_gang, 3);
            auto cards = proto->mutable_invisible_hand_cards();
            std::sort(cards->begin(), cards->end());
        }
        else
        {
            auto size = proto->invisible_hand_cards_num() - 3;
            if (size > 0)
            {
                proto->set_invisible_hand_cards_num(size);
            }
        }
    }
}

void DataManager::updateCardForMingGang(player_id_t player_id, card_t card_of_ming_gang)
{
    // for player self:
    // 1.remove 4 cards(value equal card_of_ming_gang) from invisible hand cards 
    // and add 4 cards(value equal card_of_ming_gang) to ming gang cards
    // or
    // 2.remove 1 cards(value equal card_of_ming_gang) from invisible hand cards 
    // and remove 3 cards(value equal card_of_ming_gang) from peng cards 
    // and add 4 cards(value equal card_of_ming_gang) to ming gang cards

    // for other player:
    // 1.reduce 1 for invisible_hand_cards_num
    // and remove 3 cards(value equal card_of_ming_gang) from peng cards 
    // and add 4 cards(value equal card_of_ming_gang) to ming gang cards
    // or
    // 2.reduce 4 for invisible_hand_cards_num
    // and add 4 cards(value equal card_of_ming_gang) to ming gang cards

    auto proto = this->getPlayerCardsMsgProtocol(player_id);
    if (nullptr != proto)
    {
        if (this->self_player_id() == player_id)
        {
            if (4 == this->countInvisibleCard(proto, card_of_ming_gang)) 
            {
                this->removeInvisibleCards(proto, card_of_ming_gang, 4);
            }
            else
            {
                this->removeInvisibleCards(proto, card_of_ming_gang, 1);
                this->removeCards(proto->mutable_peng_cards(), card_of_ming_gang, 3);
            }

            auto size = proto->ming_gang_cards_size();
            proto->mutable_ming_gang_cards()->Resize(size + 4, card_of_ming_gang);

            auto cards = proto->mutable_invisible_hand_cards();
            std::sort(cards->begin(), cards->end());
        }
        else
        {
            if (3 == this->countCard(proto->mutable_peng_cards(), card_of_ming_gang))
            {
                auto size = proto->invisible_hand_cards_num() - 1;
                if (size > 0)
                {
                    proto->set_invisible_hand_cards_num(size);
                }
                this->removeCards(proto->mutable_peng_cards(), card_of_ming_gang, 3);
            }
            else
            {
                auto size = proto->invisible_hand_cards_num() - 4;
                if (size > 0)
                {
                    proto->set_invisible_hand_cards_num(size);
                }
            }          

            auto size = proto->ming_gang_cards_size();
            proto->mutable_ming_gang_cards()->Resize(size + 4, card_of_ming_gang);
        }
    }
}

void DataManager::updateCardForAnGang(player_id_t player_id, card_t card_of_an_gang)
{
    auto proto = this->getPlayerCardsMsgProtocol(player_id);
    if (nullptr != proto)
    {
        proto->mutable_an_gang_cards()->Resize(proto->an_gang_cards_size() + 4,
            card_of_an_gang);
        if (this->self_player_id() == player_id)
        {
            this->removeInvisibleCards(proto, card_of_an_gang, 4);
            auto cards = proto->mutable_invisible_hand_cards();
            std::sort(cards->begin(), cards->end());
        }
        else
        {
            auto size = proto->invisible_hand_cards_num() - 4;
            if (size > 0)
            {
                proto->set_invisible_hand_cards_num(size);
            }
        }
    }
}

void DataManager::updateCardForBuhua(player_id_t player_id)
{
    auto proto = this->getPlayerCardsMsgProtocol(player_id);
    if (nullptr != proto)
    {
        if (this->self_player_id() == player_id) 
        {
            // add hua card and remove hua card from invisible cards
            auto player_cards = this->cards_msg_protocol_of_player_self();
            auto size = player_cards->invisible_hand_cards_size();

            for (int i = size - 1; i > -1; i--)
            {
                auto card = player_cards->invisible_hand_cards(i);
                if (this->is_season(card))
                {
                    proto->add_flower_cards(card);
                    this->removeInvisibleCards(proto, card, 1);
                }
                else if (this->is_flower(card))
                {
                    proto->add_season_cards(card);
                    this->removeInvisibleCards(proto, card, 1);
                }
            }

            auto cards = proto->mutable_invisible_hand_cards();
            std::sort(cards->begin(), cards->end());
        } 
        else 
        {
            // add hua card
            auto hua_card_size = this->play_card_msg_protocol()->operating_cards_size();

            for (auto i = 0; i < hua_card_size; i++)
            {
                auto hua_card = this->play_card_msg_protocol()->operating_cards(i);
                if (this->is_season(hua_card))
                {
                    proto->add_flower_cards(hua_card);
                }
                else if (this->is_flower(hua_card))
                {
                    proto->add_season_cards(hua_card);
                }
            }

            // remove hua card from invisible cards
            auto size = proto->invisible_hand_cards_num() - hua_card_size;
            if (size > 0)
            {
                proto->set_invisible_hand_cards_num(size);
            }
        }
    }
}

void DataManager::updateCardForHu(player_id_t player_id)
{
    auto proto = this->play_card_msg_protocol();
    if (nullptr != proto)
    {
        if (proto->invisible_hand_cards_size() > 0)
        {
            auto cards = proto->mutable_invisible_hand_cards();
            std::sort(cards->begin(), cards->end());
        }
    }
}

DataManager::PlayerCardsMsgProtocol* 
DataManager::getPlayerCardsMsgProtocol(player_id_t player_id)
{
    if (player_id == this->self_player_id())
    {
        return this->cards_msg_protocol_of_player_self();
    }
    else if (player_id == this->left_player_id()) 
    {
        return this->cards_msg_protocol_of_left_player();
    }
    else if (player_id == this->opposite_player_id()) 
    {
        return this->cards_msg_protocol_of_opposite_player();
    }
    else if (player_id == this->right_player_id()) 
    {
        return this->cards_msg_protocol_of_right_player();
    }
    return nullptr;
}

void DataManager::updateCardForDiscardOfOtherPlayer(player_id_t player_id, card_t discard)
{
    if (discard == CardConstants::INVALID_CARD_VALUE)
        return;

    auto proto = this->getPlayerCardsMsgProtocol(player_id);
    if (nullptr != proto)
    {
        auto size = proto->invisible_hand_cards_num() - 1;
        if (size > 0)
        {
            proto->set_invisible_hand_cards_num(size);
        }

        if (discard > CardConstants::INVALID_CARD_VALUE &&
            discard < CardConstants::SEASON_SPRING)
        {
            proto->add_discards(discard);
        }
    }
}

int DataManager::countInvisibleCard(PlayerCardsMsgProtocol* proto, card_t card) const
{
    if (nullptr != proto)
    {
        return this->countCard(proto->mutable_invisible_hand_cards(), card);
    }
    return 0;
}

int DataManager::countCard(RepeatedField* repeated_field, card_t card) const
{
    auto count = 0;
    for (int i = 0; i < repeated_field->size(); i++) 
    {
        if (repeated_field->Get(i) == card) 
        {
            count++;
        }
    }
    return count;
}

void DataManager::removeInvisibleCards(PlayerCardsMsgProtocol* proto, card_t card, int num)
{
    if (nullptr != proto)
    {
        this->removeCards(proto->mutable_invisible_hand_cards(), card, num);
    }
}

void DataManager::removeCards(RepeatedField* repeated_field, card_t card, int num)
{
    if (nullptr == repeated_field)
        return;

    auto n = repeated_field->size();
    auto count = 0;
    for (int i = 0; i < n; i++)
    {
        if (repeated_field->Get(i) == card)
        {
            auto index = n - count - 1;
            if (index > -1 && index != i)
            {
                repeated_field->SwapElements(i, index);
            }
            ++count;
        }
        if (count >= num)
        {
            for (auto j = 0; j < num; j++)
            {
                repeated_field->RemoveLast();
            }
            return;
        }
    }
}

} // namespace gamer
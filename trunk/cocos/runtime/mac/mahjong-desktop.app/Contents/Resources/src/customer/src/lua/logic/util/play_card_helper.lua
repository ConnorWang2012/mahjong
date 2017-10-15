--[[
@ copyright(C), 2015-2020, ConnorAndHisFriendsCompany.Inc
@ filename:	   play_card_helper.lua
@ author:	   Connor
@ version:	   1.0.0
@ date:		   2017-05-01
@ description: play card helper.
@ others:
@ history:
1.date:
author:
modification:
--]]

local PlayCardHelper = {}
local MahjongConst   = require "view.constant.mahjong_constants.lua"
local CardConst      = require "logic.constant.card_constants.lua"
PlayCardHelper.directions_ = {}

function PlayCardHelper.setPlayerDirection(player_id, direction)
	PlayCardHelper.directions_[player_id] = direction
end

function PlayCardHelper.getPlayerDirection(player_id)
	return PlayCardHelper.directions_[player_id]
end

function PlayCardHelper.setHasSpecialOperation(has)
	PlayCardHelper.has_special_speration_ = has
end

-- has operation but discard
function PlayCardHelper.hasSpecialOperation()
	return PlayCardHelper.has_special_speration_
end

function PlayCardHelper.iCanDiscard()
	if PlayCardHelper.hasSpecialOperation() then
		print("[PlayCardHelper.iCanDiscard] has special operation")
		return false
	end

	local next_player_id = gamer.data_mgr_:play_card_msg_protocol():next_operate_player_id()
	if next_player_id == gamer.data_mgr_:self_player_id() then
		return true
	end

	return false
end

function PlayCardHelper.isMahongValueValid(mahjong_value)
	if not mahjong_value then
		return false
	end

	if mahjong_value >= CardConst.CardValues.BAMBOO_1 and 
	   mahjong_value <= CardConst.CardValues.FLOWER_BAMBOO then
		return true
	end

	return false
end

function PlayCardHelper.isFlowerOrSeasonCard(mahjong_value)
	if mahjong_value >= CardConst.CardValues.SEASON_SPRING and
	   mahjong_value <= CardConst.CardValues.FLOWER_BAMBOO then
		return true
	end
	return false
end

function PlayCardHelper.getImageNameOfDirectionForOperatingPlayer()
	local player_id = gamer.data_mgr_:play_card_msg_protocol():next_operate_player_id()
	local direction = PlayCardHelper.getPlayerDirection(player_id)

	if direction == MahjongConst.Directions.SELF then
		return "img_direction_cur1"
	elseif direction == MahjongConst.Directions.LEFT then
		return "img_direction_cur4"
	elseif direction == MahjongConst.Directions.OPPOSITE then
		return "img_direction_cur3"
	elseif direction == MahjongConst.Directions.RIGHT then
		return "img_direction_cur2"
	end
	return "img_direction_cur2"
end

function PlayCardHelper.getImageNameOfDirectionAfterPlayerSelf()
	local players_num = gamer.data_mgr_:room_msg_protocol():players_num()
	if 2 == players_num then
		return "img_direction_cur3"
	else
		return "img_direction_cur2"
	end
	return "img_direction_cur2"
end

return PlayCardHelper
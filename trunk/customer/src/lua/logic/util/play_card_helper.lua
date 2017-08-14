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
PlayCardHelper.directions_ = {}

function PlayCardHelper.setPlayerDirection(player_id, direction)
	PlayCardHelper.directions_[player_id] = direction
end

function PlayCardHelper.getPlayerDirection(player_id)
	return PlayCardHelper.directions_[player_id]
end

function PlayCardHelper.setNewCardOfPlayerSelf(new_card)
	PlayCardHelper.new_card_ = new_card
end

function PlayCardHelper.getNewCardOfPlayerSelf()
	return PlayCardHelper.new_card_
end

function PlayCardHelper.getNextPlayerDirectionImageName(players_num, cur_acting_player_id)
	if 4 == players_num then
		if not PlayCardHelper.player_direction_img_name_ then
			PlayCardHelper.player_direction_img_name_ = "img_direction_cur1"
		elseif "img_direction_cur1" == PlayCardHelper.player_direction_img_name_ then
			PlayCardHelper.player_direction_img_name_ = "img_direction_cur2"
		elseif "img_direction_cur2" == PlayCardHelper.player_direction_img_name_ then
			PlayCardHelper.player_direction_img_name_ = "img_direction_cur3"
		elseif "img_direction_cur3" == PlayCardHelper.player_direction_img_name_ then
			PlayCardHelper.player_direction_img_name_ = "img_direction_cur4"
		elseif "img_direction_cur4" == PlayCardHelper.player_direction_img_name_ then
			PlayCardHelper.player_direction_img_name_ = "img_direction_cur1"
		end

	elseif 3 == players_num then
		if not PlayCardHelper.player_direction_img_name_ then
			PlayCardHelper.player_direction_img_name_ = "img_direction_cur1"
		elseif "img_direction_cur1" == PlayCardHelper.player_direction_img_name_ then
			PlayCardHelper.player_direction_img_name_ = "img_direction_cur2"
		elseif "img_direction_cur2" == PlayCardHelper.player_direction_img_name_ then
			PlayCardHelper.player_direction_img_name_ = "img_direction_cur4"
		elseif "img_direction_cur4" == PlayCardHelper.player_direction_img_name_ then
			PlayCardHelper.player_direction_img_name_ = "img_direction_cur1"
		end

	elseif 2 == players_num then
		if not PlayCardHelper.player_direction_img_name_ then
			local direction = PlayCardHelper.getPlayerDirection(cur_acting_player_id)
			if direction == MahjongConst.Directions.SELF then
				PlayCardHelper.player_direction_img_name_ = "img_direction_cur1"
			else
				PlayCardHelper.player_direction_img_name_ = "img_direction_cur3"
			end
		elseif "img_direction_cur1" == PlayCardHelper.player_direction_img_name_ then
			PlayCardHelper.player_direction_img_name_ = "img_direction_cur3"
		elseif "img_direction_cur3" == PlayCardHelper.player_direction_img_name_ then
			PlayCardHelper.player_direction_img_name_ = "img_direction_cur1"
		end
	end

	return PlayCardHelper.player_direction_img_name_ 
end

return PlayCardHelper
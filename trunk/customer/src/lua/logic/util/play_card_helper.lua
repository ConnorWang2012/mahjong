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

function PlayCardHelper.setPlayerDirection(player_id, direction)
	if not PlayCardHelper.directions_ then
		PlayCardHelper.directions_ = {}
	end

	PlayCardHelper.directions_[player_id] = direction
end

function PlayCardHelper.getPlayerDirection(player_id)
	if PlayCardHelper.directions_ then
		return PlayCardHelper.directions_[player_id]
	end
	return nil
end

function PlayCardHelper.setNewCardOfPlayerSelf(new_card)
	PlayCardHelper.new_card_ = new_card
end

function PlayCardHelper.getNewCardOfPlayerSelf()
	return PlayCardHelper.new_card_
end

return PlayCardHelper
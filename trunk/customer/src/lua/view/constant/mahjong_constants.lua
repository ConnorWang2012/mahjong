--[[
@ copyright(C), 2015-2020, ConnorAndHisFriendsCompany.Inc
@ filename:	   mahjong_constants.lua
@ author:	   Connor
@ version:	   1.0.0
@ date:		   2017-06-23
@ description: mahjong constants.
@ others:
@ history:
1.date:
author:
modification:
--]]

local MahjongConstants = {}

MahjongConstants.Directions = { SELF = 1, LEFT = 2, OPPOSITE = 3, RIGHT = 4 }
MahjongConstants.Types	    = { INVISIBLE = 1, INVISIBLE_AN_GANG_1 = 2, INVISIBLE_AN_GANG_2 = 3,
								VISIBLE = 4, VISIBLE_MING_GANG = 5, VISIBLE_DISCARD = 6 }
MahjongConstants.States		= { NORMAL = 1, SELECTED = 2, TOUCH_ENABLE = 3, TOUCH_DISABLE = 4 }

MahjongConstants.CardPngs = {
	{ "bamboo_1.png", "bamboo_2.png", "bamboo_3.png", "bamboo_4.png", "bamboo_5.png", 
	  "bamboo_6.png", "bamboo_7.png", "bamboo_8.png", "bamboo_9.png" },
	{ "character_1.png", "character_2.png", "character_3.png", "character_4.png", 
	  "character_5.png", "character_6.png", "character_7.png", "character_8.png", 
	  "character_9.png" },
	{ "dot_1.png", "dot_2.png", "dot_3.png", "dot_4.png", "dot_5.png", "dot_6.png", 
	  "dot_7.png", "dot_8.png", "dot_9.png" },
	{ "wind_or_dragon_1.png", "wind_or_dragon_2.png", "wind_or_dragon_3.png", 
	  "wind_or_dragon_4.png", "wind_or_dragon_5.png", "wind_or_dragon_6.png", 
	  "wind_or_dragon_7.png" },
	{ "season_or_flower_1.png", "season_or_flower_2.png", "season_or_flower_3.png", 
	  "season_or_flower_4.png", "season_or_flower_5.png", "season_or_flower_6.png", 
	  "season_or_flower_7.png", "season_or_flower_8.png" }
}

return MahjongConstants
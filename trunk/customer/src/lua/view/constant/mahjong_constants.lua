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

MahjongConstants.Sizes = {
	OFFSET_X1		= 110, -- position offset x of player self for first card
	OFFSET_X2		= 180, -- position offset x of player self visible card(ming gang)
	OFFSET_Y1		= 76,  -- position offset y of player self visible card
	OFFSET_Y2		= 78,  -- position offset y of player self visible card(ming gang)
	OFFSET_Y3		= 100, -- position offset y of player self invisible card
	CARD_W1			= 94,  -- width of player self visible card 
	CARD_W2			= 125, -- width of player self invisible card
	CARD_W3			= 282, -- width of player self visible card(ming gang)
	CARD_INTERVAL1	= 110, -- interval of player self visible card and invisible card

	LEFT_CARD_OFFSET_X0	= 350, -- position offset x of left player for first card
	CARD_OFFSET_Y0		= 900, -- position offset y of left player or right player for first card

	CARD_OFFSET_X1		= 15,  -- position offset x of left player or right player visible card
	CARD_OFFSET_X2		= 15,  -- position offset x of left player or right player invisible card
	CARD_OFFSET_X3		= 45,  -- position offset x of left player or right player visible card(ming gang)
	CARD_OFFSET_Y1		= 40, 
	CARD_OFFSET_Y2		= 40, 
	CARD_OFFSET_Y3		= 120, 

	RIGHT_CARD_OFFSET_X0	= 1570, -- position offset x of right player for first card

	OPPOSITE_CARD_OFFSET_X0 = 1350, -- position offset x of opposite player for first card
	OPPOSITE_CARD_OFFSET_Y0 = 950,
	
	OPPOSITE_CARD_OFFSET_X1	= 49,   -- position offset x of opposite player visible card
	OPPOSITE_CARD_OFFSET_X2	= 53,   -- position offset x of opposite player invisible card
	OPPOSITE_CARD_OFFSET_X3	= 147,  -- position offset x of opposite player visible card(ming gang)

	CARD_INTERVAL2 = 25
}

return MahjongConstants
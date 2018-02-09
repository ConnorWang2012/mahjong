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

local M = {}

M.Directions = { SELF = 1, LEFT = 2, OPPOSITE = 3, RIGHT = 4 }
M.Types	     = { INVISIBLE = 1, INVISIBLE_1 = 2, INVISIBLE_2 = 3, INVISIBLE_3 = 4,
				 VISIBLE = 5, VISIBLE_MING_GANG = 6, VISIBLE_DISCARD = 7 }

M.CardPngs = {
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

M.Sizes = {
	-- mahjong position
	OFFSET_X1		= 110, -- position offset x of player self for first card
	OFFSET_X2		= 180, -- position offset x of player self visible card(ming gang)
	OFFSET_X5		= 200, -- position offset x of player self flower card

	OFFSET_Y1		= 76,  -- position offset y of player self visible card
	OFFSET_Y2		= 78,  -- position offset y of player self visible card(ming gang)
	OFFSET_Y3		= 100, -- position offset y of player self invisible card
	OFFSET_Y4		= 150, -- position y of player self invisible card for selected
	OFFSET_Y5		= 250, -- position offset y of player self flower card

	CARD_W1			= 94,  -- width of player self visible card 
	CARD_W2			= 125, -- width of player self invisible card
	CARD_W3			= 282, -- width of player self visible card(ming gang)
	
	CARD_INTERVAL1	= 110, -- interval of player self visible card and invisible card
	CARD_INTERVAL3	= 62, -- interval of invisible card and new card for player self

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

	CARD_INTERVAL2 = 25, -- interval of invisible card and new card for other player

	DISCARD_X1		= 700,  -- first position x of discard for first line(player self)
	DISCARD_Y1		= 460,
	DISCARD_X11		= 1197, -- last position x of discard for first line(player self)
	DISCARD_X2		= 600,  -- first position x of discard for second line(player self)
	DISCARD_Y2		= 385,
	DISCARD_X22		= 1339, -- last position x of discard for second line(player self)
	DISCARD_X3		= 428,  
	DISCARD_Y3		= 310,
	DISCARD_X33		= 1509, 

	DISCARD_OFFSET_X = 68,  -- player self

	LEFT_DISCARD_X1		= 700,  
	LEFT_DISCARD_Y1		= 720,
	LEFT_DISCARD_Y11	= 560, 
	LEFT_DISCARD_X2		= 631,
	LEFT_DISCARD_Y2		= 750,
	LEFT_DISCARD_Y22	= 510, 
	LEFT_DISCARD_X3		= 562,  
	LEFT_DISCARD_Y3		= 789,
	LEFT_DISCARD_Y33	= 469, 
	LEFT_DISCARD_X4		= 495,  
	LEFT_DISCARD_Y4		= 828,
	LEFT_DISCARD_Y44	= 428, 

	LEFT_DISCARD_OFFSET_X = 9,
	LEFT_DISCARD_OFFSET_Y = 40,  

	OPPOSITE_DISCARD_X1		= 1160, 
	OPPOSITE_DISCARD_Y1		= 792,
	OPPOSITE_DISCARD_X11	= 800,  
	OPPOSITE_DISCARD_X2		= 1236, 
	OPPOSITE_DISCARD_Y2		= 847,
	OPPOSITE_DISCARD_X22	= 697, 
	OPPOSITE_DISCARD_X3		= 1310, 
	OPPOSITE_DISCARD_Y3		= 902, 
	OPPOSITE_DISCARD_X33	= 594, 

	OPPOSITE_DISCARD_OFFSET_X = 50, 

	RIGHT_DISCARD_X1		= 1247,  
	RIGHT_DISCARD_Y1		= 560,
	RIGHT_DISCARD_Y11		= 720, 
	RIGHT_DISCARD_X2		= 1330,  
	RIGHT_DISCARD_Y2		= 510,
	RIGHT_DISCARD_Y22		= 750, 
	RIGHT_DISCARD_X3		= 1413,  
	RIGHT_DISCARD_Y3		= 469,
	RIGHT_DISCARD_Y33		= 789, 
	RIGHT_DISCARD_X4		= 1496,  
	RIGHT_DISCARD_Y4		= 428,
	RIGHT_DISCARD_Y44		= 828, 

	RIGHT_DISCARD_OFFSET_X = 9,
	RIGHT_DISCARD_OFFSET_Y = 40, 

	-- animation position
	PLAYER_SELF_OPERATION_ANIM_Y = 350,

	LEFT_PLAYER_OPERATION_ANIM_X = 200,

	OPPOSITE_PLAYER_OPERATION_ANIM_Y = display.top - 350,

	RIGHT_PLAYER_OPERATION_ANIM_X = display.right - 200,
}

M.ZOrders = {
	DISCARD_LINE_1 = 1300, -- left or right player discard zorder for line 1
	DISCARD_LINE_2 = 1200,
	DISCARD_LINE_3 = 1100,
	DISCARD_LINE_4 = 1000,

	FLOWER_CARD_PLAYER_SELF			    = 2000,
	VISIBLE_HAND_CARD_PLAYER_SELF	    = 2001,
	INVISIBLE_AN_GANG_CARD_PLAYER_SELF	= 2001,
	INVISIBLE_HAND_CARD_PLAYER_SELF	    = 2002
}

M.AnimationIDs = {
	ANIMATION_OPERATION1	= 1,
	ANIMATION_OPERATION2	= 2,
	ANIMATION_OPERATION3	= 3,
	ANIMATION_CHI			= 4,
	ANIMATION_PENG			= 5,
	ANIMATION_GANG			= 6,
	ANIMATION_BUHUA			= 7,
	ANIMATION_TING			= 8,
	ANIMATION_HU			= 9,
	ANIMATION_ZIMO			= 10
}

return M
--[[
@ copyright(C), 2015-2020, ConnorAndHisFriendsCompany.Inc
@ filename:	   card_constants.lua
@ author:	   Connor
@ version:	   1.0.0
@ date:		   2017-06-23
@ description:card_constants.
@ others:
@ history:
1.date:
author:
modification:
--]]

local CardConstants = {}

CardConstants.OPERATION_TIMEOUT_MAX = 18 -- s, current operating player is player self(i can discard and do other operation)

CardConstants.OPERATION_TIMEOUT_MAX2 = 5 -- s, current operating player is other player(i can't discard but do other operation)

CardConstants.TOTAL_CARDS_NUM               = 144 -- total cards num
CardConstants.ONE_PLAYER_CARD_NUM           = 13  -- one player card num
CardConstants.ONE_PLAYER_CARD_NUM2          = 14  -- one player card num, including one new card

CardConstants.CardValues =
{
	INVALID_CARD_VALUE  = -1,
	
	BAMBOO_1            = 0,
    BAMBOO_2            = 1,
    BAMBOO_3            = 2,
    BAMBOO_4            = 3,
    BAMBOO_5            = 4,
    BAMBOO_6            = 5,
    BAMBOO_7            = 6,
    BAMBOO_8            = 7,
    BAMBOO_9            = 8,

    CHARACTER_1         = 9,
    CHARACTER_2         = 10,
    CHARACTER_3         = 11,
    CHARACTER_4         = 12,
    CHARACTER_5         = 13,
    CHARACTER_6         = 14,
    CHARACTER_7         = 15,
    CHARACTER_8         = 16,
    CHARACTER_9         = 17,

    DOT_1               = 18,
    DOT_2               = 19,
    DOT_3               = 20,
    DOT_4               = 21,
    DOT_5               = 22,
    DOT_6               = 23,
    DOT_7               = 24,
    DOT_8               = 25,
    DOT_9               = 26,

    WIND_EAST           = 27, 
    WIND_SOUTH          = 28, 
    WIND_WEST           = 29, 
    WIND_NORTH          = 30, 
    DRAGON_GREEN        = 31, 
    DRAGON_RED          = 32, 
    DRAGON_WHITE        = 33,

    SEASON_SPRING       = 34,
    SEASON_SUMMER       = 35,
    SEASON_AUTUMN       = 36,
    SEASON_WINTER       = 37,
    FLOWER_PLUM         = 38,
    FLOWER_ORCHID       = 39,
    FLOWER_CHRYSANTHEMUM = 40,
    FLOWER_BAMBOO        = 41
}

CardConstants.OperationIDs = 
{
	OPERATION_UNKNOW		= -1,
    OPERATION_DISCARD		= 0,
    OPERATION_NONE			= 1, -- just a new card, no operation(only server to client)
    OPERATION_CHI			= 2, -- chi
    OPERATION_PENG			= 3, -- peng
	OPERATION_CHI_OR_PENG   = 4, -- chi or peng(only server to client)
	OPERATION_CHI_OR_PENG_OR_GANG = 5,	-- chi or peng or gang(only server to client)
    OPERATION_PENG_GANG		= 6, -- peng + gang
    OPERATION_MING_GANG		= 7, -- ming gang
    OPERATION_AN_GANG		= 8, -- an gang
    OPERATION_BU_HUA		= 9, -- bu hua
	OPERATION_TING          = 10, -- ting
    OPERATION_HU			= 11, -- hu
    OPERATION_ZI_MO			= 12, -- zi mo
	OPERATION_GIVE_UP		= 13, -- give up
}

return CardConstants
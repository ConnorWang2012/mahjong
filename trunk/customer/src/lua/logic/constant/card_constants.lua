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

CardConstants.CardValues =
{
	INVALID_CARD_VALUE            = -1,
}

CardConstants.OperationIDs = 
{
    OPERATION_DISCARD		= 0,
    OPERATION_NONE			= 1, -- just a new card, no operation(only server to client)
    OPERATION_CHI			= 2, -- chi
    OPERATION_PENG			= 3, -- peng
    OPERATION_PENG_GANG		= 4, -- peng + gang
    OPERATION_MING_GANG		= 5, -- ming gang
    OPERATION_AN_GANG		= 6, -- an gang
    OPERATION_BU_HUA		= 7, -- bu hua
    OPERATION_HU			= 8, -- hu
    OPERATION_ZI_MO			= 9, -- zi mo
	OPERATION_GIVE_UP		= 10, -- give up
}

return CardConstants
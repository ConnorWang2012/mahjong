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
	INVALID_CARD_VALUE           = -1,
	INVALID_PLAYER_ID            = 0
}

CardConstants.OperationIDs = 
{
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
    OPERATION_HU			= 10, -- hu
    OPERATION_ZI_MO			= 11, -- zi mo
	OPERATION_GIVE_UP		= 12, -- give up
}

return CardConstants
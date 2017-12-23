--[[
@ copyright(C), 2015-2020, ConnorAndHisFriendsCompany.Inc
@ filename:	   msg_type.lua
@ author:	   Connor
@ version:	   1.0.0
@ date:		   2017-06-08
@ description: msg type.
@ others:
@ history:
1.date:
author:
modification:
--]]

gamer.MsgTypes =
{
	-- client to server
	C2S_MSG_TYPE_LOGIN				= 1,
	C2S_MSG_TYPE_PROPERTY			= 2,
	C2S_MSG_TYPE_ROOM				= 3,

	-- server to client
	S2C_MSG_TYPE_LOGIN				= 1,
	S2C_MSG_TYPE_PROPERTY			= 2,
	S2C_MSG_TYPE_ROOM				= 3
}
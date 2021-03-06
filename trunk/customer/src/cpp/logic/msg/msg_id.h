﻿/*******************************************************************************
@ copyright(C), 2015-2020, ConnorAndHisFriendsCompany.Inc
@ filename:	    msg_id.h
@ author:	    Connor
@ version:	    1.0.0
@ date:		    2017-05-01
@ description:  msg id.
@ others:
@ history:
1.date:
author:
modification:
********************************************************************************/

#ifndef CONNOR_GAME_SRC_MSG_ID_H_
#define CONNOR_GAME_SRC_MSG_ID_H_

namespace gamer 
{

enum class MsgIDs 
{
	MSG_ID_UNKNOW					= 0,

	// login
	// c2s, s2c
	MSG_ID_LOGIN_3RD_PARTY			= 1001,
	MSG_ID_LOGIN_MY					= 1002,

	// room
	// c2s, s2c
	MSG_ID_ROOM_CREATE				= 2001,
	MSG_ID_ROOM_PLAYER_JOIN			= 2002,
	MSG_ID_ROOM_PLAYER_LEAVE		= 2003,
	MSG_ID_ROOM_DISSOLVE			= 2004,
	MSG_ID_ROOM_START_GAME			= 2005,
	MSG_ID_ROOM_PLAY_CARD			= 2006,
	MSG_ID_ROOM_GAME_END			= 2007, // game end for one round
	MSG_ID_ROOM_FINAL_GAME_END		= 2008,
	MSG_ID_ROOM_GET_ROOM_LIST		= 2009,

	// property
	// c2s, s2c
	MSG_ID_PROPERTY_SET				= 3001,

	// s2c
	MSG_ID_PROPERTY_CHANGED			= 4001,

	// c2s, s2c
	MSG_ID_PROPERTY_GET_PLAYER_INFO = 5001

};

}

#endif // CONNOR_GAME_SRC_MSG_ID_H_
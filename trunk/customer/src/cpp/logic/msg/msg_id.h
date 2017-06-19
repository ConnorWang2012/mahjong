/*******************************************************************************
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
    MSG_ID_LOGIN_3RD_PARTY          = 1,
    MSG_ID_LOGIN_MY                 = 2,
    MSG_ID_ROOM_CREATE              = 3,
    MSG_ID_ROOM_START_GAME          = 4,
};

}

#endif // CONNOR_GAME_SRC_MSG_ID_H_
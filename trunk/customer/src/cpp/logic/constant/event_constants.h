/*******************************************************************************
  @ copyright(C), 2015-2020, ConnorAndHisFriendsCompany.Inc
  @ filename:	  event_constant.h
  @ author:		  Connor
  @ version:	  1.0.0
  @ date:		  2015-01-18
  @ description:  define all events id here.
  @ others:  
  @ history: 
     1.date:
       author:
       modification:
********************************************************************************/

#ifndef CONNOR_GAME_SRC_EVENT_DEFINE_H_
#define CONNOR_GAME_SRC_EVENT_DEFINE_H_

namespace gamer 
{

enum class EventIDs 
{
	EVENT_ID_INVALID,
    EVENT_ID_SOCKET_CONNECTED,
    EVENT_ID_SOCKET_DISCONNECTED,
	EVENT_ID_LOGIN_SUCCESS,
	EVENT_ID_LOGIN_FAILED
};

} // namespace gamer

#endif // CONNOR_GAME_SRC_EVENT_DEFINE_H_
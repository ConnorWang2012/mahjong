/*******************************************************************************
@ copyright(C), 2015-2020, ConnorAndHisFriendsCompany.Inc
@ filename:	     lua_bind_register.h
@ author:		 Connor
@ version:	     1.0.0
@ date:		     2017-05-20
@ description:   register all my lua binds.
@ others:
@ history:
1.date:
author:
modification:
********************************************************************************/

#ifndef CONNOR_GAME_SRC_LUA_BIND_REGISTER_H_
#define CONNOR_GAME_SRC_LUA_BIND_REGISTER_H_

extern "C"
{
#include "lua.h"
#include "tolua++.h"
}

TOLUA_API int tolua_event_listener_open(lua_State*);
TOLUA_API int tolua_event_manager_open(lua_State*);
TOLUA_API int tolua_command_manager_open(lua_State*);
TOLUA_API int tolua_data_manager_open(lua_State*);
TOLUA_API int tolua_msg_open(lua_State*);
TOLUA_API int tolua_msg_manager_open(lua_State*);
TOLUA_API int tolua_network_manager_open(lua_State*);
TOLUA_API int tolua_my_login_msg_protocol_open(lua_State*);
TOLUA_API int tolua_create_room_msg_protocol_open(lua_State*);
TOLUA_API int tolua_game_start_msg_protocol_open(lua_State*);
TOLUA_API int tolua_player_cards_msg_protocol_open(lua_State*);
TOLUA_API int tolua_player_msg_protocol_open(lua_State*);

namespace gamer
{
    int lua_bind_register(lua_State* L);
} // namespace gamer

#endif // CONNOR_GAME_SRC_LUA_BIND_REGISTER_H_
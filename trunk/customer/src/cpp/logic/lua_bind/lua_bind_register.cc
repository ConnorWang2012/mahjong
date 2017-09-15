/*******************************************************************************
@ copyright(C), 2015-2020, ConnorAndHisFriendsCompany.Inc
@ filename:	     lua_bind_register.cc
@ author:		 Connor
@ version:	     1.0.0
@ date:		     2017-05-20
@ description:   see the header.
@ others:
@ history:
1.date:
author:
modification:
********************************************************************************/

#include "lua_bind_register.h"

namespace gamer
{

int lua_bind_register(lua_State* L)
{
    tolua_command_manager_open(L);
    tolua_data_manager_open(L);
    tolua_event_listener_open(L);
    tolua_event_manager_open(L);
    tolua_network_manager_open(L);
    tolua_mylog_open(L);
    tolua_msg_open(L);
    tolua_msg_manager_open(L);
    tolua_my_login_msg_protocol_open(L);
    tolua_create_room_msg_protocol_open(L);
    tolua_room_operation_msg_protocol_open(L);
    tolua_room_msg_protocol_open(L);
    tolua_play_card_msg_protocol_open(L);
    tolua_ting_card_msg_protocol_open(L);
    tolua_player_cards_msg_protocol_open(L);
    tolua_player_msg_protocol_open(L);

    return 0;
}

} // namespace gamer

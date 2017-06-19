/*
** Lua binding: game_start_msg_protocol
** Generated automatically by tolua++-1.0.92 on 06/17/17 14:56:29.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_game_start_msg_protocol_open (lua_State* tolua_S);

#include "msg/protocol/game_start_msg_protocol.pb.h"
#include "msg/protocol/player_cards_msg_protocol.pb.h"
#include <string>
#include <google/protobuf/stubs/common.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/unknown_field_set.h>

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_gamer__protocol__GameStartMsgProtocol (lua_State* tolua_S)
{
 gamer::protocol::GameStartMsgProtocol* self = (gamer::protocol::GameStartMsgProtocol*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"gamer::protocol::GameStartMsgProtocol");
 tolua_usertype(tolua_S,"gamer::protocol::PlayerCardsMsgProtocol");
 tolua_usertype(tolua_S,"google::protobuf::Message");
}

/* method: new of class  gamer::protocol::GameStartMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_game_start_msg_protocol_gamer_protocol_GameStartMsgProtocol_new00
static int tolua_game_start_msg_protocol_gamer_protocol_GameStartMsgProtocol_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"gamer::protocol::GameStartMsgProtocol",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   gamer::protocol::GameStartMsgProtocol* tolua_ret = (gamer::protocol::GameStartMsgProtocol*)  Mtolua_new((gamer::protocol::GameStartMsgProtocol)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"gamer::protocol::GameStartMsgProtocol");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  gamer::protocol::GameStartMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_game_start_msg_protocol_gamer_protocol_GameStartMsgProtocol_new00_local
static int tolua_game_start_msg_protocol_gamer_protocol_GameStartMsgProtocol_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"gamer::protocol::GameStartMsgProtocol",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   gamer::protocol::GameStartMsgProtocol* tolua_ret = (gamer::protocol::GameStartMsgProtocol*)  Mtolua_new((gamer::protocol::GameStartMsgProtocol)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"gamer::protocol::GameStartMsgProtocol");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ByteSize of class  gamer::protocol::GameStartMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_game_start_msg_protocol_gamer_protocol_GameStartMsgProtocol_ByteSize00
static int tolua_game_start_msg_protocol_gamer_protocol_GameStartMsgProtocol_ByteSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const gamer::protocol::GameStartMsgProtocol",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const gamer::protocol::GameStartMsgProtocol* self = (const gamer::protocol::GameStartMsgProtocol*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ByteSize'", NULL);
#endif
  {
   int tolua_ret = (int)  self->ByteSize();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ByteSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: set_room_id of class  gamer::protocol::GameStartMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_game_start_msg_protocol_gamer_protocol_GameStartMsgProtocol_set_room_id00
static int tolua_game_start_msg_protocol_gamer_protocol_GameStartMsgProtocol_set_room_id00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"gamer::protocol::GameStartMsgProtocol",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  gamer::protocol::GameStartMsgProtocol* self = (gamer::protocol::GameStartMsgProtocol*)  tolua_tousertype(tolua_S,1,0);
  int value = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'set_room_id'", NULL);
#endif
  {
   self->set_room_id(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'set_room_id'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: room_id of class  gamer::protocol::GameStartMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_game_start_msg_protocol_gamer_protocol_GameStartMsgProtocol_room_id00
static int tolua_game_start_msg_protocol_gamer_protocol_GameStartMsgProtocol_room_id00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const gamer::protocol::GameStartMsgProtocol",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const gamer::protocol::GameStartMsgProtocol* self = (const gamer::protocol::GameStartMsgProtocol*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'room_id'", NULL);
#endif
  {
   int tolua_ret = (int)  self->room_id();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'room_id'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: set_room_owner_id of class  gamer::protocol::GameStartMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_game_start_msg_protocol_gamer_protocol_GameStartMsgProtocol_set_room_owner_id00
static int tolua_game_start_msg_protocol_gamer_protocol_GameStartMsgProtocol_set_room_owner_id00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"gamer::protocol::GameStartMsgProtocol",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  gamer::protocol::GameStartMsgProtocol* self = (gamer::protocol::GameStartMsgProtocol*)  tolua_tousertype(tolua_S,1,0);
  int value = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'set_room_owner_id'", NULL);
#endif
  {
   self->set_room_owner_id(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'set_room_owner_id'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: room_owner_id of class  gamer::protocol::GameStartMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_game_start_msg_protocol_gamer_protocol_GameStartMsgProtocol_room_owner_id00
static int tolua_game_start_msg_protocol_gamer_protocol_GameStartMsgProtocol_room_owner_id00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const gamer::protocol::GameStartMsgProtocol",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const gamer::protocol::GameStartMsgProtocol* self = (const gamer::protocol::GameStartMsgProtocol*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'room_owner_id'", NULL);
#endif
  {
   int tolua_ret = (int)  self->room_owner_id();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'room_owner_id'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: players_num of class  gamer::protocol::GameStartMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_game_start_msg_protocol_gamer_protocol_GameStartMsgProtocol_players_num00
static int tolua_game_start_msg_protocol_gamer_protocol_GameStartMsgProtocol_players_num00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const gamer::protocol::GameStartMsgProtocol",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const gamer::protocol::GameStartMsgProtocol* self = (const gamer::protocol::GameStartMsgProtocol*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'players_num'", NULL);
#endif
  {
   int tolua_ret = (int)  self->players_num();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'players_num'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: cur_round of class  gamer::protocol::GameStartMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_game_start_msg_protocol_gamer_protocol_GameStartMsgProtocol_cur_round00
static int tolua_game_start_msg_protocol_gamer_protocol_GameStartMsgProtocol_cur_round00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const gamer::protocol::GameStartMsgProtocol",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const gamer::protocol::GameStartMsgProtocol* self = (const gamer::protocol::GameStartMsgProtocol*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'cur_round'", NULL);
#endif
  {
   int tolua_ret = (int)  self->cur_round();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'cur_round'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: total_round of class  gamer::protocol::GameStartMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_game_start_msg_protocol_gamer_protocol_GameStartMsgProtocol_total_round00
static int tolua_game_start_msg_protocol_gamer_protocol_GameStartMsgProtocol_total_round00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const gamer::protocol::GameStartMsgProtocol",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const gamer::protocol::GameStartMsgProtocol* self = (const gamer::protocol::GameStartMsgProtocol*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'total_round'", NULL);
#endif
  {
   int tolua_ret = (int)  self->total_round();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'total_round'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: remain_cards_num of class  gamer::protocol::GameStartMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_game_start_msg_protocol_gamer_protocol_GameStartMsgProtocol_remain_cards_num00
static int tolua_game_start_msg_protocol_gamer_protocol_GameStartMsgProtocol_remain_cards_num00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const gamer::protocol::GameStartMsgProtocol",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const gamer::protocol::GameStartMsgProtocol* self = (const gamer::protocol::GameStartMsgProtocol*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'remain_cards_num'", NULL);
#endif
  {
   int tolua_ret = (int)  self->remain_cards_num();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'remain_cards_num'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: cur_acting_player_id of class  gamer::protocol::GameStartMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_game_start_msg_protocol_gamer_protocol_GameStartMsgProtocol_cur_acting_player_id00
static int tolua_game_start_msg_protocol_gamer_protocol_GameStartMsgProtocol_cur_acting_player_id00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const gamer::protocol::GameStartMsgProtocol",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const gamer::protocol::GameStartMsgProtocol* self = (const gamer::protocol::GameStartMsgProtocol*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'cur_acting_player_id'", NULL);
#endif
  {
   int tolua_ret = (int)  self->cur_acting_player_id();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'cur_acting_player_id'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: cur_action_id of class  gamer::protocol::GameStartMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_game_start_msg_protocol_gamer_protocol_GameStartMsgProtocol_cur_action_id00
static int tolua_game_start_msg_protocol_gamer_protocol_GameStartMsgProtocol_cur_action_id00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const gamer::protocol::GameStartMsgProtocol",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const gamer::protocol::GameStartMsgProtocol* self = (const gamer::protocol::GameStartMsgProtocol*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'cur_action_id'", NULL);
#endif
  {
   int tolua_ret = (int)  self->cur_action_id();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'cur_action_id'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: banker_id of class  gamer::protocol::GameStartMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_game_start_msg_protocol_gamer_protocol_GameStartMsgProtocol_banker_id00
static int tolua_game_start_msg_protocol_gamer_protocol_GameStartMsgProtocol_banker_id00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const gamer::protocol::GameStartMsgProtocol",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const gamer::protocol::GameStartMsgProtocol* self = (const gamer::protocol::GameStartMsgProtocol*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'banker_id'", NULL);
#endif
  {
   int tolua_ret = (int)  self->banker_id();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'banker_id'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: banker_is_same_time of class  gamer::protocol::GameStartMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_game_start_msg_protocol_gamer_protocol_GameStartMsgProtocol_banker_is_same_time00
static int tolua_game_start_msg_protocol_gamer_protocol_GameStartMsgProtocol_banker_is_same_time00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const gamer::protocol::GameStartMsgProtocol",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const gamer::protocol::GameStartMsgProtocol* self = (const gamer::protocol::GameStartMsgProtocol*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'banker_is_same_time'", NULL);
#endif
  {
   int tolua_ret = (int)  self->banker_is_same_time();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'banker_is_same_time'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: player_cards_size of class  gamer::protocol::GameStartMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_game_start_msg_protocol_gamer_protocol_GameStartMsgProtocol_player_cards_size00
static int tolua_game_start_msg_protocol_gamer_protocol_GameStartMsgProtocol_player_cards_size00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const gamer::protocol::GameStartMsgProtocol",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const gamer::protocol::GameStartMsgProtocol* self = (const gamer::protocol::GameStartMsgProtocol*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'player_cards_size'", NULL);
#endif
  {
   int tolua_ret = (int)  self->player_cards_size();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'player_cards_size'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: player_cards of class  gamer::protocol::GameStartMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_game_start_msg_protocol_gamer_protocol_GameStartMsgProtocol_player_cards00
static int tolua_game_start_msg_protocol_gamer_protocol_GameStartMsgProtocol_player_cards00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const gamer::protocol::GameStartMsgProtocol",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const gamer::protocol::GameStartMsgProtocol* self = (const gamer::protocol::GameStartMsgProtocol*)  tolua_tousertype(tolua_S,1,0);
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'player_cards'", NULL);
#endif
  {
   const gamer::protocol::PlayerCardsMsgProtocol& tolua_ret = (const gamer::protocol::PlayerCardsMsgProtocol&)  self->player_cards(index);
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const gamer::protocol::PlayerCardsMsgProtocol");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'player_cards'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_game_start_msg_protocol_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  tolua_module(tolua_S,"gamer",0);
  tolua_beginmodule(tolua_S,"gamer");
   tolua_module(tolua_S,"protocol",0);
   tolua_beginmodule(tolua_S,"protocol");
    #ifdef __cplusplus
    tolua_cclass(tolua_S,"GameStartMsgProtocol","gamer::protocol::GameStartMsgProtocol","google::protobuf::Message",tolua_collect_gamer__protocol__GameStartMsgProtocol);
    #else
    tolua_cclass(tolua_S,"GameStartMsgProtocol","gamer::protocol::GameStartMsgProtocol","google::protobuf::Message",NULL);
    #endif
    tolua_beginmodule(tolua_S,"GameStartMsgProtocol");
     tolua_function(tolua_S,"new",tolua_game_start_msg_protocol_gamer_protocol_GameStartMsgProtocol_new00);
     tolua_function(tolua_S,"new_local",tolua_game_start_msg_protocol_gamer_protocol_GameStartMsgProtocol_new00_local);
     tolua_function(tolua_S,".call",tolua_game_start_msg_protocol_gamer_protocol_GameStartMsgProtocol_new00_local);
     tolua_function(tolua_S,"ByteSize",tolua_game_start_msg_protocol_gamer_protocol_GameStartMsgProtocol_ByteSize00);
     tolua_function(tolua_S,"set_room_id",tolua_game_start_msg_protocol_gamer_protocol_GameStartMsgProtocol_set_room_id00);
     tolua_function(tolua_S,"room_id",tolua_game_start_msg_protocol_gamer_protocol_GameStartMsgProtocol_room_id00);
     tolua_function(tolua_S,"set_room_owner_id",tolua_game_start_msg_protocol_gamer_protocol_GameStartMsgProtocol_set_room_owner_id00);
     tolua_function(tolua_S,"room_owner_id",tolua_game_start_msg_protocol_gamer_protocol_GameStartMsgProtocol_room_owner_id00);
     tolua_function(tolua_S,"players_num",tolua_game_start_msg_protocol_gamer_protocol_GameStartMsgProtocol_players_num00);
     tolua_function(tolua_S,"cur_round",tolua_game_start_msg_protocol_gamer_protocol_GameStartMsgProtocol_cur_round00);
     tolua_function(tolua_S,"total_round",tolua_game_start_msg_protocol_gamer_protocol_GameStartMsgProtocol_total_round00);
     tolua_function(tolua_S,"remain_cards_num",tolua_game_start_msg_protocol_gamer_protocol_GameStartMsgProtocol_remain_cards_num00);
     tolua_function(tolua_S,"cur_acting_player_id",tolua_game_start_msg_protocol_gamer_protocol_GameStartMsgProtocol_cur_acting_player_id00);
     tolua_function(tolua_S,"cur_action_id",tolua_game_start_msg_protocol_gamer_protocol_GameStartMsgProtocol_cur_action_id00);
     tolua_function(tolua_S,"banker_id",tolua_game_start_msg_protocol_gamer_protocol_GameStartMsgProtocol_banker_id00);
     tolua_function(tolua_S,"banker_is_same_time",tolua_game_start_msg_protocol_gamer_protocol_GameStartMsgProtocol_banker_is_same_time00);
     tolua_function(tolua_S,"player_cards_size",tolua_game_start_msg_protocol_gamer_protocol_GameStartMsgProtocol_player_cards_size00);
     tolua_function(tolua_S,"player_cards",tolua_game_start_msg_protocol_gamer_protocol_GameStartMsgProtocol_player_cards00);
    tolua_endmodule(tolua_S);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_game_start_msg_protocol (lua_State* tolua_S) {
 return tolua_game_start_msg_protocol_open(tolua_S);
};
#endif

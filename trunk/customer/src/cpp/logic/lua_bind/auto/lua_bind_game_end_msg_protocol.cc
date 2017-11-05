/*
** Lua binding: game_end_msg_protocol
** Generated automatically by tolua++-1.0.92 on 11/05/17 13:15:03.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_game_end_msg_protocol_open (lua_State* tolua_S);

#include "msg/protocol/game_end_msg_protocol.pb.h"
#include <string>
#include <google/protobuf/stubs/common.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/unknown_field_set.h>

/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"google::protobuf::Message");
 tolua_usertype(tolua_S,"gamer::protocol::PlayerCardsMsgProtocol");
 tolua_usertype(tolua_S,"gamer::protocol::GameEndMsgProtocol");
 tolua_usertype(tolua_S,"gamer::protocol::GameEndDataMsgProtocol");
}

/* method: ByteSize of class  gamer::protocol::GameEndDataMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_game_end_msg_protocol_gamer_protocol_GameEndDataMsgProtocol_ByteSize00
static int tolua_game_end_msg_protocol_gamer_protocol_GameEndDataMsgProtocol_ByteSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const gamer::protocol::GameEndDataMsgProtocol",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const gamer::protocol::GameEndDataMsgProtocol* self = (const gamer::protocol::GameEndDataMsgProtocol*)  tolua_tousertype(tolua_S,1,0);
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

/* method: player_id of class  gamer::protocol::GameEndDataMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_game_end_msg_protocol_gamer_protocol_GameEndDataMsgProtocol_player_id00
static int tolua_game_end_msg_protocol_gamer_protocol_GameEndDataMsgProtocol_player_id00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const gamer::protocol::GameEndDataMsgProtocol",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const gamer::protocol::GameEndDataMsgProtocol* self = (const gamer::protocol::GameEndDataMsgProtocol*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'player_id'", NULL);
#endif
  {
   unsigned int tolua_ret = (unsigned int)  self->player_id();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'player_id'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: nick_name of class  gamer::protocol::GameEndDataMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_game_end_msg_protocol_gamer_protocol_GameEndDataMsgProtocol_nick_name00
static int tolua_game_end_msg_protocol_gamer_protocol_GameEndDataMsgProtocol_nick_name00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const gamer::protocol::GameEndDataMsgProtocol",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const gamer::protocol::GameEndDataMsgProtocol* self = (const gamer::protocol::GameEndDataMsgProtocol*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'nick_name'", NULL);
#endif
  {
   std::string tolua_ret = (std::string)  self->nick_name();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'nick_name'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: diff_score_gold of class  gamer::protocol::GameEndDataMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_game_end_msg_protocol_gamer_protocol_GameEndDataMsgProtocol_diff_score_gold00
static int tolua_game_end_msg_protocol_gamer_protocol_GameEndDataMsgProtocol_diff_score_gold00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const gamer::protocol::GameEndDataMsgProtocol",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const gamer::protocol::GameEndDataMsgProtocol* self = (const gamer::protocol::GameEndDataMsgProtocol*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'diff_score_gold'", NULL);
#endif
  {
   int tolua_ret = (int)  self->diff_score_gold();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'diff_score_gold'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: diff_score_diamond of class  gamer::protocol::GameEndDataMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_game_end_msg_protocol_gamer_protocol_GameEndDataMsgProtocol_diff_score_diamond00
static int tolua_game_end_msg_protocol_gamer_protocol_GameEndDataMsgProtocol_diff_score_diamond00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const gamer::protocol::GameEndDataMsgProtocol",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const gamer::protocol::GameEndDataMsgProtocol* self = (const gamer::protocol::GameEndDataMsgProtocol*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'diff_score_diamond'", NULL);
#endif
  {
   int tolua_ret = (int)  self->diff_score_diamond();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'diff_score_diamond'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: total_score_gold of class  gamer::protocol::GameEndDataMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_game_end_msg_protocol_gamer_protocol_GameEndDataMsgProtocol_total_score_gold00
static int tolua_game_end_msg_protocol_gamer_protocol_GameEndDataMsgProtocol_total_score_gold00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const gamer::protocol::GameEndDataMsgProtocol",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const gamer::protocol::GameEndDataMsgProtocol* self = (const gamer::protocol::GameEndDataMsgProtocol*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'total_score_gold'", NULL);
#endif
  {
   unsigned int tolua_ret = (unsigned int)  self->total_score_gold();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'total_score_gold'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: total_score_diamond of class  gamer::protocol::GameEndDataMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_game_end_msg_protocol_gamer_protocol_GameEndDataMsgProtocol_total_score_diamond00
static int tolua_game_end_msg_protocol_gamer_protocol_GameEndDataMsgProtocol_total_score_diamond00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const gamer::protocol::GameEndDataMsgProtocol",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const gamer::protocol::GameEndDataMsgProtocol* self = (const gamer::protocol::GameEndDataMsgProtocol*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'total_score_diamond'", NULL);
#endif
  {
   unsigned int tolua_ret = (unsigned int)  self->total_score_diamond();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'total_score_diamond'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: rate_winning of class  gamer::protocol::GameEndDataMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_game_end_msg_protocol_gamer_protocol_GameEndDataMsgProtocol_rate_winning00
static int tolua_game_end_msg_protocol_gamer_protocol_GameEndDataMsgProtocol_rate_winning00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const gamer::protocol::GameEndDataMsgProtocol",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const gamer::protocol::GameEndDataMsgProtocol* self = (const gamer::protocol::GameEndDataMsgProtocol*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'rate_winning'", NULL);
#endif
  {
   float tolua_ret = (float)  self->rate_winning();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'rate_winning'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: num_ming_gang of class  gamer::protocol::GameEndDataMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_game_end_msg_protocol_gamer_protocol_GameEndDataMsgProtocol_num_ming_gang00
static int tolua_game_end_msg_protocol_gamer_protocol_GameEndDataMsgProtocol_num_ming_gang00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const gamer::protocol::GameEndDataMsgProtocol",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const gamer::protocol::GameEndDataMsgProtocol* self = (const gamer::protocol::GameEndDataMsgProtocol*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'num_ming_gang'", NULL);
#endif
  {
   unsigned int tolua_ret = (unsigned int)  self->num_ming_gang();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'num_ming_gang'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: num_an_gang of class  gamer::protocol::GameEndDataMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_game_end_msg_protocol_gamer_protocol_GameEndDataMsgProtocol_num_an_gang00
static int tolua_game_end_msg_protocol_gamer_protocol_GameEndDataMsgProtocol_num_an_gang00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const gamer::protocol::GameEndDataMsgProtocol",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const gamer::protocol::GameEndDataMsgProtocol* self = (const gamer::protocol::GameEndDataMsgProtocol*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'num_an_gang'", NULL);
#endif
  {
   unsigned int tolua_ret = (unsigned int)  self->num_an_gang();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'num_an_gang'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: player_cards of class  gamer::protocol::GameEndDataMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_game_end_msg_protocol_gamer_protocol_GameEndDataMsgProtocol_player_cards00
static int tolua_game_end_msg_protocol_gamer_protocol_GameEndDataMsgProtocol_player_cards00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const gamer::protocol::GameEndDataMsgProtocol",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const gamer::protocol::GameEndDataMsgProtocol* self = (const gamer::protocol::GameEndDataMsgProtocol*)  tolua_tousertype(tolua_S,1,0);
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

/* method: ByteSize of class  gamer::protocol::GameEndMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_game_end_msg_protocol_gamer_protocol_GameEndMsgProtocol_ByteSize00
static int tolua_game_end_msg_protocol_gamer_protocol_GameEndMsgProtocol_ByteSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const gamer::protocol::GameEndMsgProtocol",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const gamer::protocol::GameEndMsgProtocol* self = (const gamer::protocol::GameEndMsgProtocol*)  tolua_tousertype(tolua_S,1,0);
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

/* method: room_id of class  gamer::protocol::GameEndMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_game_end_msg_protocol_gamer_protocol_GameEndMsgProtocol_room_id00
static int tolua_game_end_msg_protocol_gamer_protocol_GameEndMsgProtocol_room_id00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const gamer::protocol::GameEndMsgProtocol",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const gamer::protocol::GameEndMsgProtocol* self = (const gamer::protocol::GameEndMsgProtocol*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'room_id'", NULL);
#endif
  {
   unsigned int tolua_ret = (unsigned int)  self->room_id();
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

/* method: room_owner_id of class  gamer::protocol::GameEndMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_game_end_msg_protocol_gamer_protocol_GameEndMsgProtocol_room_owner_id00
static int tolua_game_end_msg_protocol_gamer_protocol_GameEndMsgProtocol_room_owner_id00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const gamer::protocol::GameEndMsgProtocol",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const gamer::protocol::GameEndMsgProtocol* self = (const gamer::protocol::GameEndMsgProtocol*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'room_owner_id'", NULL);
#endif
  {
   unsigned int tolua_ret = (unsigned int)  self->room_owner_id();
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

/* method: players_num of class  gamer::protocol::GameEndMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_game_end_msg_protocol_gamer_protocol_GameEndMsgProtocol_players_num00
static int tolua_game_end_msg_protocol_gamer_protocol_GameEndMsgProtocol_players_num00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const gamer::protocol::GameEndMsgProtocol",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const gamer::protocol::GameEndMsgProtocol* self = (const gamer::protocol::GameEndMsgProtocol*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'players_num'", NULL);
#endif
  {
   unsigned int tolua_ret = (unsigned int)  self->players_num();
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

/* method: cur_round of class  gamer::protocol::GameEndMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_game_end_msg_protocol_gamer_protocol_GameEndMsgProtocol_cur_round00
static int tolua_game_end_msg_protocol_gamer_protocol_GameEndMsgProtocol_cur_round00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const gamer::protocol::GameEndMsgProtocol",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const gamer::protocol::GameEndMsgProtocol* self = (const gamer::protocol::GameEndMsgProtocol*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'cur_round'", NULL);
#endif
  {
   unsigned int tolua_ret = (unsigned int)  self->cur_round();
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

/* method: total_round of class  gamer::protocol::GameEndMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_game_end_msg_protocol_gamer_protocol_GameEndMsgProtocol_total_round00
static int tolua_game_end_msg_protocol_gamer_protocol_GameEndMsgProtocol_total_round00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const gamer::protocol::GameEndMsgProtocol",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const gamer::protocol::GameEndMsgProtocol* self = (const gamer::protocol::GameEndMsgProtocol*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'total_round'", NULL);
#endif
  {
   unsigned int tolua_ret = (unsigned int)  self->total_round();
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

/* method: banker_id of class  gamer::protocol::GameEndMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_game_end_msg_protocol_gamer_protocol_GameEndMsgProtocol_banker_id00
static int tolua_game_end_msg_protocol_gamer_protocol_GameEndMsgProtocol_banker_id00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const gamer::protocol::GameEndMsgProtocol",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const gamer::protocol::GameEndMsgProtocol* self = (const gamer::protocol::GameEndMsgProtocol*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'banker_id'", NULL);
#endif
  {
   unsigned int tolua_ret = (unsigned int)  self->banker_id();
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

/* method: game_end_data of class  gamer::protocol::GameEndMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_game_end_msg_protocol_gamer_protocol_GameEndMsgProtocol_game_end_data00
static int tolua_game_end_msg_protocol_gamer_protocol_GameEndMsgProtocol_game_end_data00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const gamer::protocol::GameEndMsgProtocol",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const gamer::protocol::GameEndMsgProtocol* self = (const gamer::protocol::GameEndMsgProtocol*)  tolua_tousertype(tolua_S,1,0);
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'game_end_data'", NULL);
#endif
  {
   const gamer::protocol::GameEndDataMsgProtocol& tolua_ret = (const gamer::protocol::GameEndDataMsgProtocol&)  self->game_end_data(index);
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const gamer::protocol::GameEndDataMsgProtocol");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'game_end_data'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_game_end_msg_protocol_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  tolua_module(tolua_S,"gamer",0);
  tolua_beginmodule(tolua_S,"gamer");
   tolua_module(tolua_S,"protocol",0);
   tolua_beginmodule(tolua_S,"protocol");
    tolua_cclass(tolua_S,"GameEndDataMsgProtocol","gamer::protocol::GameEndDataMsgProtocol","google::protobuf::Message",NULL);
    tolua_beginmodule(tolua_S,"GameEndDataMsgProtocol");
     tolua_function(tolua_S,"ByteSize",tolua_game_end_msg_protocol_gamer_protocol_GameEndDataMsgProtocol_ByteSize00);
     tolua_function(tolua_S,"player_id",tolua_game_end_msg_protocol_gamer_protocol_GameEndDataMsgProtocol_player_id00);
     tolua_function(tolua_S,"nick_name",tolua_game_end_msg_protocol_gamer_protocol_GameEndDataMsgProtocol_nick_name00);
     tolua_function(tolua_S,"diff_score_gold",tolua_game_end_msg_protocol_gamer_protocol_GameEndDataMsgProtocol_diff_score_gold00);
     tolua_function(tolua_S,"diff_score_diamond",tolua_game_end_msg_protocol_gamer_protocol_GameEndDataMsgProtocol_diff_score_diamond00);
     tolua_function(tolua_S,"total_score_gold",tolua_game_end_msg_protocol_gamer_protocol_GameEndDataMsgProtocol_total_score_gold00);
     tolua_function(tolua_S,"total_score_diamond",tolua_game_end_msg_protocol_gamer_protocol_GameEndDataMsgProtocol_total_score_diamond00);
     tolua_function(tolua_S,"rate_winning",tolua_game_end_msg_protocol_gamer_protocol_GameEndDataMsgProtocol_rate_winning00);
     tolua_function(tolua_S,"num_ming_gang",tolua_game_end_msg_protocol_gamer_protocol_GameEndDataMsgProtocol_num_ming_gang00);
     tolua_function(tolua_S,"num_an_gang",tolua_game_end_msg_protocol_gamer_protocol_GameEndDataMsgProtocol_num_an_gang00);
     tolua_function(tolua_S,"player_cards",tolua_game_end_msg_protocol_gamer_protocol_GameEndDataMsgProtocol_player_cards00);
    tolua_endmodule(tolua_S);
    tolua_cclass(tolua_S,"GameEndMsgProtocol","gamer::protocol::GameEndMsgProtocol","google::protobuf::Message",NULL);
    tolua_beginmodule(tolua_S,"GameEndMsgProtocol");
     tolua_function(tolua_S,"ByteSize",tolua_game_end_msg_protocol_gamer_protocol_GameEndMsgProtocol_ByteSize00);
     tolua_function(tolua_S,"room_id",tolua_game_end_msg_protocol_gamer_protocol_GameEndMsgProtocol_room_id00);
     tolua_function(tolua_S,"room_owner_id",tolua_game_end_msg_protocol_gamer_protocol_GameEndMsgProtocol_room_owner_id00);
     tolua_function(tolua_S,"players_num",tolua_game_end_msg_protocol_gamer_protocol_GameEndMsgProtocol_players_num00);
     tolua_function(tolua_S,"cur_round",tolua_game_end_msg_protocol_gamer_protocol_GameEndMsgProtocol_cur_round00);
     tolua_function(tolua_S,"total_round",tolua_game_end_msg_protocol_gamer_protocol_GameEndMsgProtocol_total_round00);
     tolua_function(tolua_S,"banker_id",tolua_game_end_msg_protocol_gamer_protocol_GameEndMsgProtocol_banker_id00);
     tolua_function(tolua_S,"game_end_data",tolua_game_end_msg_protocol_gamer_protocol_GameEndMsgProtocol_game_end_data00);
    tolua_endmodule(tolua_S);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_game_end_msg_protocol (lua_State* tolua_S) {
 return tolua_game_end_msg_protocol_open(tolua_S);
};
#endif


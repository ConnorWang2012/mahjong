/*
** Lua binding: play_card_msg_protocol
** Generated automatically by tolua++-1.0.92 on 09/14/17 04:03:33.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_play_card_msg_protocol_open (lua_State* tolua_S);

#include "msg/protocol/play_card_msg_protocol.pb.h"
#include "msg/protocol/ting_card_msg_protocol.pb.h"
#include <string>
#include <google/protobuf/stubs/common.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/unknown_field_set.h>

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_gamer__protocol__PlayCardMsgProtocol (lua_State* tolua_S)
{
 gamer::protocol::PlayCardMsgProtocol* self = (gamer::protocol::PlayCardMsgProtocol*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"gamer::protocol::PlayCardMsgProtocol");
 tolua_usertype(tolua_S,"gamer::protocol::TingCardMsgProtocol");
 tolua_usertype(tolua_S,"google::protobuf::Message");
}

/* method: new of class  gamer::protocol::PlayCardMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_play_card_msg_protocol_gamer_protocol_PlayCardMsgProtocol_new00
static int tolua_play_card_msg_protocol_gamer_protocol_PlayCardMsgProtocol_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"gamer::protocol::PlayCardMsgProtocol",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   gamer::protocol::PlayCardMsgProtocol* tolua_ret = (gamer::protocol::PlayCardMsgProtocol*)  Mtolua_new((gamer::protocol::PlayCardMsgProtocol)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"gamer::protocol::PlayCardMsgProtocol");
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

/* method: new_local of class  gamer::protocol::PlayCardMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_play_card_msg_protocol_gamer_protocol_PlayCardMsgProtocol_new00_local
static int tolua_play_card_msg_protocol_gamer_protocol_PlayCardMsgProtocol_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"gamer::protocol::PlayCardMsgProtocol",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   gamer::protocol::PlayCardMsgProtocol* tolua_ret = (gamer::protocol::PlayCardMsgProtocol*)  Mtolua_new((gamer::protocol::PlayCardMsgProtocol)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"gamer::protocol::PlayCardMsgProtocol");
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

/* method: ByteSize of class  gamer::protocol::PlayCardMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_play_card_msg_protocol_gamer_protocol_PlayCardMsgProtocol_ByteSize00
static int tolua_play_card_msg_protocol_gamer_protocol_PlayCardMsgProtocol_ByteSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const gamer::protocol::PlayCardMsgProtocol",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const gamer::protocol::PlayCardMsgProtocol* self = (const gamer::protocol::PlayCardMsgProtocol*)  tolua_tousertype(tolua_S,1,0);
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

/* method: set_player_id of class  gamer::protocol::PlayCardMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_play_card_msg_protocol_gamer_protocol_PlayCardMsgProtocol_set_player_id00
static int tolua_play_card_msg_protocol_gamer_protocol_PlayCardMsgProtocol_set_player_id00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"gamer::protocol::PlayCardMsgProtocol",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  gamer::protocol::PlayCardMsgProtocol* self = (gamer::protocol::PlayCardMsgProtocol*)  tolua_tousertype(tolua_S,1,0);
  int value = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'set_player_id'", NULL);
#endif
  {
   self->set_player_id(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'set_player_id'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: player_id of class  gamer::protocol::PlayCardMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_play_card_msg_protocol_gamer_protocol_PlayCardMsgProtocol_player_id00
static int tolua_play_card_msg_protocol_gamer_protocol_PlayCardMsgProtocol_player_id00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const gamer::protocol::PlayCardMsgProtocol",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const gamer::protocol::PlayCardMsgProtocol* self = (const gamer::protocol::PlayCardMsgProtocol*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'player_id'", NULL);
#endif
  {
   int tolua_ret = (int)  self->player_id();
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

/* method: set_room_id of class  gamer::protocol::PlayCardMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_play_card_msg_protocol_gamer_protocol_PlayCardMsgProtocol_set_room_id00
static int tolua_play_card_msg_protocol_gamer_protocol_PlayCardMsgProtocol_set_room_id00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"gamer::protocol::PlayCardMsgProtocol",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  gamer::protocol::PlayCardMsgProtocol* self = (gamer::protocol::PlayCardMsgProtocol*)  tolua_tousertype(tolua_S,1,0);
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

/* method: room_id of class  gamer::protocol::PlayCardMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_play_card_msg_protocol_gamer_protocol_PlayCardMsgProtocol_room_id00
static int tolua_play_card_msg_protocol_gamer_protocol_PlayCardMsgProtocol_room_id00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const gamer::protocol::PlayCardMsgProtocol",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const gamer::protocol::PlayCardMsgProtocol* self = (const gamer::protocol::PlayCardMsgProtocol*)  tolua_tousertype(tolua_S,1,0);
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

/* method: set_cur_round of class  gamer::protocol::PlayCardMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_play_card_msg_protocol_gamer_protocol_PlayCardMsgProtocol_set_cur_round00
static int tolua_play_card_msg_protocol_gamer_protocol_PlayCardMsgProtocol_set_cur_round00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"gamer::protocol::PlayCardMsgProtocol",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  gamer::protocol::PlayCardMsgProtocol* self = (gamer::protocol::PlayCardMsgProtocol*)  tolua_tousertype(tolua_S,1,0);
  int value = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'set_cur_round'", NULL);
#endif
  {
   self->set_cur_round(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'set_cur_round'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: cur_round of class  gamer::protocol::PlayCardMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_play_card_msg_protocol_gamer_protocol_PlayCardMsgProtocol_cur_round00
static int tolua_play_card_msg_protocol_gamer_protocol_PlayCardMsgProtocol_cur_round00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const gamer::protocol::PlayCardMsgProtocol",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const gamer::protocol::PlayCardMsgProtocol* self = (const gamer::protocol::PlayCardMsgProtocol*)  tolua_tousertype(tolua_S,1,0);
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

/* method: set_operation_id of class  gamer::protocol::PlayCardMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_play_card_msg_protocol_gamer_protocol_PlayCardMsgProtocol_set_operation_id00
static int tolua_play_card_msg_protocol_gamer_protocol_PlayCardMsgProtocol_set_operation_id00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"gamer::protocol::PlayCardMsgProtocol",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  gamer::protocol::PlayCardMsgProtocol* self = (gamer::protocol::PlayCardMsgProtocol*)  tolua_tousertype(tolua_S,1,0);
  int value = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'set_operation_id'", NULL);
#endif
  {
   self->set_operation_id(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'set_operation_id'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operation_id of class  gamer::protocol::PlayCardMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_play_card_msg_protocol_gamer_protocol_PlayCardMsgProtocol_operation_id00
static int tolua_play_card_msg_protocol_gamer_protocol_PlayCardMsgProtocol_operation_id00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const gamer::protocol::PlayCardMsgProtocol",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const gamer::protocol::PlayCardMsgProtocol* self = (const gamer::protocol::PlayCardMsgProtocol*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operation_id'", NULL);
#endif
  {
   int tolua_ret = (int)  self->operation_id();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'operation_id'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: set_discard of class  gamer::protocol::PlayCardMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_play_card_msg_protocol_gamer_protocol_PlayCardMsgProtocol_set_discard00
static int tolua_play_card_msg_protocol_gamer_protocol_PlayCardMsgProtocol_set_discard00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"gamer::protocol::PlayCardMsgProtocol",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  gamer::protocol::PlayCardMsgProtocol* self = (gamer::protocol::PlayCardMsgProtocol*)  tolua_tousertype(tolua_S,1,0);
  int value = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'set_discard'", NULL);
#endif
  {
   self->set_discard(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'set_discard'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: discard of class  gamer::protocol::PlayCardMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_play_card_msg_protocol_gamer_protocol_PlayCardMsgProtocol_discard00
static int tolua_play_card_msg_protocol_gamer_protocol_PlayCardMsgProtocol_discard00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const gamer::protocol::PlayCardMsgProtocol",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const gamer::protocol::PlayCardMsgProtocol* self = (const gamer::protocol::PlayCardMsgProtocol*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'discard'", NULL);
#endif
  {
   int tolua_ret = (int)  self->discard();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'discard'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: set_new_card of class  gamer::protocol::PlayCardMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_play_card_msg_protocol_gamer_protocol_PlayCardMsgProtocol_set_new_card00
static int tolua_play_card_msg_protocol_gamer_protocol_PlayCardMsgProtocol_set_new_card00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"gamer::protocol::PlayCardMsgProtocol",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  gamer::protocol::PlayCardMsgProtocol* self = (gamer::protocol::PlayCardMsgProtocol*)  tolua_tousertype(tolua_S,1,0);
  int value = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'set_new_card'", NULL);
#endif
  {
   self->set_new_card(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'set_new_card'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_card of class  gamer::protocol::PlayCardMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_play_card_msg_protocol_gamer_protocol_PlayCardMsgProtocol_new_card00
static int tolua_play_card_msg_protocol_gamer_protocol_PlayCardMsgProtocol_new_card00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const gamer::protocol::PlayCardMsgProtocol",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const gamer::protocol::PlayCardMsgProtocol* self = (const gamer::protocol::PlayCardMsgProtocol*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'new_card'", NULL);
#endif
  {
   int tolua_ret = (int)  self->new_card();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new_card'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: next_operate_player_id of class  gamer::protocol::PlayCardMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_play_card_msg_protocol_gamer_protocol_PlayCardMsgProtocol_next_operate_player_id00
static int tolua_play_card_msg_protocol_gamer_protocol_PlayCardMsgProtocol_next_operate_player_id00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const gamer::protocol::PlayCardMsgProtocol",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const gamer::protocol::PlayCardMsgProtocol* self = (const gamer::protocol::PlayCardMsgProtocol*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'next_operate_player_id'", NULL);
#endif
  {
   int tolua_ret = (int)  self->next_operate_player_id();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'next_operate_player_id'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: set_next_operate_player_id of class  gamer::protocol::PlayCardMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_play_card_msg_protocol_gamer_protocol_PlayCardMsgProtocol_set_next_operate_player_id00
static int tolua_play_card_msg_protocol_gamer_protocol_PlayCardMsgProtocol_set_next_operate_player_id00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"gamer::protocol::PlayCardMsgProtocol",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  gamer::protocol::PlayCardMsgProtocol* self = (gamer::protocol::PlayCardMsgProtocol*)  tolua_tousertype(tolua_S,1,0);
  int value = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'set_next_operate_player_id'", NULL);
#endif
  {
   self->set_next_operate_player_id(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'set_next_operate_player_id'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: has_next_operate_player_new_card of class  gamer::protocol::PlayCardMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_play_card_msg_protocol_gamer_protocol_PlayCardMsgProtocol_has_next_operate_player_new_card00
static int tolua_play_card_msg_protocol_gamer_protocol_PlayCardMsgProtocol_has_next_operate_player_new_card00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const gamer::protocol::PlayCardMsgProtocol",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const gamer::protocol::PlayCardMsgProtocol* self = (const gamer::protocol::PlayCardMsgProtocol*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'has_next_operate_player_new_card'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->has_next_operate_player_new_card();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'has_next_operate_player_new_card'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: my_available_operation_id of class  gamer::protocol::PlayCardMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_play_card_msg_protocol_gamer_protocol_PlayCardMsgProtocol_my_available_operation_id00
static int tolua_play_card_msg_protocol_gamer_protocol_PlayCardMsgProtocol_my_available_operation_id00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const gamer::protocol::PlayCardMsgProtocol",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const gamer::protocol::PlayCardMsgProtocol* self = (const gamer::protocol::PlayCardMsgProtocol*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'my_available_operation_id'", NULL);
#endif
  {
   int tolua_ret = (int)  self->my_available_operation_id();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'my_available_operation_id'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operating_cards_size of class  gamer::protocol::PlayCardMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_play_card_msg_protocol_gamer_protocol_PlayCardMsgProtocol_operating_cards_size00
static int tolua_play_card_msg_protocol_gamer_protocol_PlayCardMsgProtocol_operating_cards_size00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const gamer::protocol::PlayCardMsgProtocol",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const gamer::protocol::PlayCardMsgProtocol* self = (const gamer::protocol::PlayCardMsgProtocol*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operating_cards_size'", NULL);
#endif
  {
   int tolua_ret = (int)  self->operating_cards_size();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'operating_cards_size'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operating_cards of class  gamer::protocol::PlayCardMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_play_card_msg_protocol_gamer_protocol_PlayCardMsgProtocol_operating_cards00
static int tolua_play_card_msg_protocol_gamer_protocol_PlayCardMsgProtocol_operating_cards00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const gamer::protocol::PlayCardMsgProtocol",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const gamer::protocol::PlayCardMsgProtocol* self = (const gamer::protocol::PlayCardMsgProtocol*)  tolua_tousertype(tolua_S,1,0);
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operating_cards'", NULL);
#endif
  {
   int tolua_ret = (int)  self->operating_cards(index);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'operating_cards'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: add_operating_cards of class  gamer::protocol::PlayCardMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_play_card_msg_protocol_gamer_protocol_PlayCardMsgProtocol_add_operating_cards00
static int tolua_play_card_msg_protocol_gamer_protocol_PlayCardMsgProtocol_add_operating_cards00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"gamer::protocol::PlayCardMsgProtocol",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  gamer::protocol::PlayCardMsgProtocol* self = (gamer::protocol::PlayCardMsgProtocol*)  tolua_tousertype(tolua_S,1,0);
  int value = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'add_operating_cards'", NULL);
#endif
  {
   self->add_operating_cards(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'add_operating_cards'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: invisible_hand_cards_size of class  gamer::protocol::PlayCardMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_play_card_msg_protocol_gamer_protocol_PlayCardMsgProtocol_invisible_hand_cards_size00
static int tolua_play_card_msg_protocol_gamer_protocol_PlayCardMsgProtocol_invisible_hand_cards_size00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const gamer::protocol::PlayCardMsgProtocol",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const gamer::protocol::PlayCardMsgProtocol* self = (const gamer::protocol::PlayCardMsgProtocol*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'invisible_hand_cards_size'", NULL);
#endif
  {
   int tolua_ret = (int)  self->invisible_hand_cards_size();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'invisible_hand_cards_size'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: invisible_hand_cards of class  gamer::protocol::PlayCardMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_play_card_msg_protocol_gamer_protocol_PlayCardMsgProtocol_invisible_hand_cards00
static int tolua_play_card_msg_protocol_gamer_protocol_PlayCardMsgProtocol_invisible_hand_cards00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const gamer::protocol::PlayCardMsgProtocol",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const gamer::protocol::PlayCardMsgProtocol* self = (const gamer::protocol::PlayCardMsgProtocol*)  tolua_tousertype(tolua_S,1,0);
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'invisible_hand_cards'", NULL);
#endif
  {
   int tolua_ret = (int)  self->invisible_hand_cards(index);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'invisible_hand_cards'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ting_cards_size of class  gamer::protocol::PlayCardMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_play_card_msg_protocol_gamer_protocol_PlayCardMsgProtocol_ting_cards_size00
static int tolua_play_card_msg_protocol_gamer_protocol_PlayCardMsgProtocol_ting_cards_size00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const gamer::protocol::PlayCardMsgProtocol",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const gamer::protocol::PlayCardMsgProtocol* self = (const gamer::protocol::PlayCardMsgProtocol*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ting_cards_size'", NULL);
#endif
  {
   int tolua_ret = (int)  self->ting_cards_size();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ting_cards_size'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ting_cards of class  gamer::protocol::PlayCardMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_play_card_msg_protocol_gamer_protocol_PlayCardMsgProtocol_ting_cards00
static int tolua_play_card_msg_protocol_gamer_protocol_PlayCardMsgProtocol_ting_cards00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const gamer::protocol::PlayCardMsgProtocol",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const gamer::protocol::PlayCardMsgProtocol* self = (const gamer::protocol::PlayCardMsgProtocol*)  tolua_tousertype(tolua_S,1,0);
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ting_cards'", NULL);
#endif
  {
   const gamer::protocol::TingCardMsgProtocol& tolua_ret = (const gamer::protocol::TingCardMsgProtocol&)  self->ting_cards(index);
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const gamer::protocol::TingCardMsgProtocol");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ting_cards'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_play_card_msg_protocol_open (lua_State* tolua_S)
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
    tolua_cclass(tolua_S,"PlayCardMsgProtocol","gamer::protocol::PlayCardMsgProtocol","google::protobuf::Message",tolua_collect_gamer__protocol__PlayCardMsgProtocol);
    #else
    tolua_cclass(tolua_S,"PlayCardMsgProtocol","gamer::protocol::PlayCardMsgProtocol","google::protobuf::Message",NULL);
    #endif
    tolua_beginmodule(tolua_S,"PlayCardMsgProtocol");
     tolua_function(tolua_S,"new",tolua_play_card_msg_protocol_gamer_protocol_PlayCardMsgProtocol_new00);
     tolua_function(tolua_S,"new_local",tolua_play_card_msg_protocol_gamer_protocol_PlayCardMsgProtocol_new00_local);
     tolua_function(tolua_S,".call",tolua_play_card_msg_protocol_gamer_protocol_PlayCardMsgProtocol_new00_local);
     tolua_function(tolua_S,"ByteSize",tolua_play_card_msg_protocol_gamer_protocol_PlayCardMsgProtocol_ByteSize00);
     tolua_function(tolua_S,"set_player_id",tolua_play_card_msg_protocol_gamer_protocol_PlayCardMsgProtocol_set_player_id00);
     tolua_function(tolua_S,"player_id",tolua_play_card_msg_protocol_gamer_protocol_PlayCardMsgProtocol_player_id00);
     tolua_function(tolua_S,"set_room_id",tolua_play_card_msg_protocol_gamer_protocol_PlayCardMsgProtocol_set_room_id00);
     tolua_function(tolua_S,"room_id",tolua_play_card_msg_protocol_gamer_protocol_PlayCardMsgProtocol_room_id00);
     tolua_function(tolua_S,"set_cur_round",tolua_play_card_msg_protocol_gamer_protocol_PlayCardMsgProtocol_set_cur_round00);
     tolua_function(tolua_S,"cur_round",tolua_play_card_msg_protocol_gamer_protocol_PlayCardMsgProtocol_cur_round00);
     tolua_function(tolua_S,"set_operation_id",tolua_play_card_msg_protocol_gamer_protocol_PlayCardMsgProtocol_set_operation_id00);
     tolua_function(tolua_S,"operation_id",tolua_play_card_msg_protocol_gamer_protocol_PlayCardMsgProtocol_operation_id00);
     tolua_function(tolua_S,"set_discard",tolua_play_card_msg_protocol_gamer_protocol_PlayCardMsgProtocol_set_discard00);
     tolua_function(tolua_S,"discard",tolua_play_card_msg_protocol_gamer_protocol_PlayCardMsgProtocol_discard00);
     tolua_function(tolua_S,"set_new_card",tolua_play_card_msg_protocol_gamer_protocol_PlayCardMsgProtocol_set_new_card00);
     tolua_function(tolua_S,"new_card",tolua_play_card_msg_protocol_gamer_protocol_PlayCardMsgProtocol_new_card00);
     tolua_function(tolua_S,"next_operate_player_id",tolua_play_card_msg_protocol_gamer_protocol_PlayCardMsgProtocol_next_operate_player_id00);
     tolua_function(tolua_S,"set_next_operate_player_id",tolua_play_card_msg_protocol_gamer_protocol_PlayCardMsgProtocol_set_next_operate_player_id00);
     tolua_function(tolua_S,"has_next_operate_player_new_card",tolua_play_card_msg_protocol_gamer_protocol_PlayCardMsgProtocol_has_next_operate_player_new_card00);
     tolua_function(tolua_S,"my_available_operation_id",tolua_play_card_msg_protocol_gamer_protocol_PlayCardMsgProtocol_my_available_operation_id00);
     tolua_function(tolua_S,"operating_cards_size",tolua_play_card_msg_protocol_gamer_protocol_PlayCardMsgProtocol_operating_cards_size00);
     tolua_function(tolua_S,"operating_cards",tolua_play_card_msg_protocol_gamer_protocol_PlayCardMsgProtocol_operating_cards00);
     tolua_function(tolua_S,"add_operating_cards",tolua_play_card_msg_protocol_gamer_protocol_PlayCardMsgProtocol_add_operating_cards00);
     tolua_function(tolua_S,"invisible_hand_cards_size",tolua_play_card_msg_protocol_gamer_protocol_PlayCardMsgProtocol_invisible_hand_cards_size00);
     tolua_function(tolua_S,"invisible_hand_cards",tolua_play_card_msg_protocol_gamer_protocol_PlayCardMsgProtocol_invisible_hand_cards00);
     tolua_function(tolua_S,"ting_cards_size",tolua_play_card_msg_protocol_gamer_protocol_PlayCardMsgProtocol_ting_cards_size00);
     tolua_function(tolua_S,"ting_cards",tolua_play_card_msg_protocol_gamer_protocol_PlayCardMsgProtocol_ting_cards00);
    tolua_endmodule(tolua_S);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_play_card_msg_protocol (lua_State* tolua_S) {
 return tolua_play_card_msg_protocol_open(tolua_S);
};
#endif


/*
** Lua binding: player_cards_msg_protocol
** Generated automatically by tolua++-1.0.92 on 07/22/17 18:11:12.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_player_cards_msg_protocol_open (lua_State* tolua_S);

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

static int tolua_collect_gamer__protocol__PlayerCardsMsgProtocol (lua_State* tolua_S)
{
 gamer::protocol::PlayerCardsMsgProtocol* self = (gamer::protocol::PlayerCardsMsgProtocol*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"google::protobuf::Message");
 tolua_usertype(tolua_S,"gamer::protocol::PlayerCardsMsgProtocol");
}

/* method: new of class  gamer::protocol::PlayerCardsMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_player_cards_msg_protocol_gamer_protocol_PlayerCardsMsgProtocol_new00
static int tolua_player_cards_msg_protocol_gamer_protocol_PlayerCardsMsgProtocol_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"gamer::protocol::PlayerCardsMsgProtocol",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   gamer::protocol::PlayerCardsMsgProtocol* tolua_ret = (gamer::protocol::PlayerCardsMsgProtocol*)  Mtolua_new((gamer::protocol::PlayerCardsMsgProtocol)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"gamer::protocol::PlayerCardsMsgProtocol");
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

/* method: new_local of class  gamer::protocol::PlayerCardsMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_player_cards_msg_protocol_gamer_protocol_PlayerCardsMsgProtocol_new00_local
static int tolua_player_cards_msg_protocol_gamer_protocol_PlayerCardsMsgProtocol_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"gamer::protocol::PlayerCardsMsgProtocol",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   gamer::protocol::PlayerCardsMsgProtocol* tolua_ret = (gamer::protocol::PlayerCardsMsgProtocol*)  Mtolua_new((gamer::protocol::PlayerCardsMsgProtocol)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"gamer::protocol::PlayerCardsMsgProtocol");
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

/* method: ByteSize of class  gamer::protocol::PlayerCardsMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_player_cards_msg_protocol_gamer_protocol_PlayerCardsMsgProtocol_ByteSize00
static int tolua_player_cards_msg_protocol_gamer_protocol_PlayerCardsMsgProtocol_ByteSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const gamer::protocol::PlayerCardsMsgProtocol",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const gamer::protocol::PlayerCardsMsgProtocol* self = (const gamer::protocol::PlayerCardsMsgProtocol*)  tolua_tousertype(tolua_S,1,0);
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

/* method: player_id of class  gamer::protocol::PlayerCardsMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_player_cards_msg_protocol_gamer_protocol_PlayerCardsMsgProtocol_player_id00
static int tolua_player_cards_msg_protocol_gamer_protocol_PlayerCardsMsgProtocol_player_id00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const gamer::protocol::PlayerCardsMsgProtocol",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const gamer::protocol::PlayerCardsMsgProtocol* self = (const gamer::protocol::PlayerCardsMsgProtocol*)  tolua_tousertype(tolua_S,1,0);
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

/* method: visible_hand_cards_size of class  gamer::protocol::PlayerCardsMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_player_cards_msg_protocol_gamer_protocol_PlayerCardsMsgProtocol_visible_hand_cards_size00
static int tolua_player_cards_msg_protocol_gamer_protocol_PlayerCardsMsgProtocol_visible_hand_cards_size00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const gamer::protocol::PlayerCardsMsgProtocol",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const gamer::protocol::PlayerCardsMsgProtocol* self = (const gamer::protocol::PlayerCardsMsgProtocol*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'visible_hand_cards_size'", NULL);
#endif
  {
   int tolua_ret = (int)  self->visible_hand_cards_size();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'visible_hand_cards_size'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: visible_hand_cards of class  gamer::protocol::PlayerCardsMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_player_cards_msg_protocol_gamer_protocol_PlayerCardsMsgProtocol_visible_hand_cards00
static int tolua_player_cards_msg_protocol_gamer_protocol_PlayerCardsMsgProtocol_visible_hand_cards00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const gamer::protocol::PlayerCardsMsgProtocol",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const gamer::protocol::PlayerCardsMsgProtocol* self = (const gamer::protocol::PlayerCardsMsgProtocol*)  tolua_tousertype(tolua_S,1,0);
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'visible_hand_cards'", NULL);
#endif
  {
   int tolua_ret = (int)  self->visible_hand_cards(index);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'visible_hand_cards'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: add_visible_hand_cards of class  gamer::protocol::PlayerCardsMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_player_cards_msg_protocol_gamer_protocol_PlayerCardsMsgProtocol_add_visible_hand_cards00
static int tolua_player_cards_msg_protocol_gamer_protocol_PlayerCardsMsgProtocol_add_visible_hand_cards00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"gamer::protocol::PlayerCardsMsgProtocol",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  gamer::protocol::PlayerCardsMsgProtocol* self = (gamer::protocol::PlayerCardsMsgProtocol*)  tolua_tousertype(tolua_S,1,0);
  int value = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'add_visible_hand_cards'", NULL);
#endif
  {
   self->add_visible_hand_cards(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'add_visible_hand_cards'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: invisible_hand_cards_size of class  gamer::protocol::PlayerCardsMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_player_cards_msg_protocol_gamer_protocol_PlayerCardsMsgProtocol_invisible_hand_cards_size00
static int tolua_player_cards_msg_protocol_gamer_protocol_PlayerCardsMsgProtocol_invisible_hand_cards_size00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const gamer::protocol::PlayerCardsMsgProtocol",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const gamer::protocol::PlayerCardsMsgProtocol* self = (const gamer::protocol::PlayerCardsMsgProtocol*)  tolua_tousertype(tolua_S,1,0);
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

/* method: invisible_hand_cards of class  gamer::protocol::PlayerCardsMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_player_cards_msg_protocol_gamer_protocol_PlayerCardsMsgProtocol_invisible_hand_cards00
static int tolua_player_cards_msg_protocol_gamer_protocol_PlayerCardsMsgProtocol_invisible_hand_cards00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const gamer::protocol::PlayerCardsMsgProtocol",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const gamer::protocol::PlayerCardsMsgProtocol* self = (const gamer::protocol::PlayerCardsMsgProtocol*)  tolua_tousertype(tolua_S,1,0);
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

/* method: add_invisible_hand_cards of class  gamer::protocol::PlayerCardsMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_player_cards_msg_protocol_gamer_protocol_PlayerCardsMsgProtocol_add_invisible_hand_cards00
static int tolua_player_cards_msg_protocol_gamer_protocol_PlayerCardsMsgProtocol_add_invisible_hand_cards00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"gamer::protocol::PlayerCardsMsgProtocol",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  gamer::protocol::PlayerCardsMsgProtocol* self = (gamer::protocol::PlayerCardsMsgProtocol*)  tolua_tousertype(tolua_S,1,0);
  int value = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'add_invisible_hand_cards'", NULL);
#endif
  {
   self->add_invisible_hand_cards(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'add_invisible_hand_cards'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: flower_cards_size of class  gamer::protocol::PlayerCardsMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_player_cards_msg_protocol_gamer_protocol_PlayerCardsMsgProtocol_flower_cards_size00
static int tolua_player_cards_msg_protocol_gamer_protocol_PlayerCardsMsgProtocol_flower_cards_size00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const gamer::protocol::PlayerCardsMsgProtocol",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const gamer::protocol::PlayerCardsMsgProtocol* self = (const gamer::protocol::PlayerCardsMsgProtocol*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'flower_cards_size'", NULL);
#endif
  {
   int tolua_ret = (int)  self->flower_cards_size();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'flower_cards_size'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: flower_cards of class  gamer::protocol::PlayerCardsMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_player_cards_msg_protocol_gamer_protocol_PlayerCardsMsgProtocol_flower_cards00
static int tolua_player_cards_msg_protocol_gamer_protocol_PlayerCardsMsgProtocol_flower_cards00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const gamer::protocol::PlayerCardsMsgProtocol",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const gamer::protocol::PlayerCardsMsgProtocol* self = (const gamer::protocol::PlayerCardsMsgProtocol*)  tolua_tousertype(tolua_S,1,0);
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'flower_cards'", NULL);
#endif
  {
   int tolua_ret = (int)  self->flower_cards(index);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'flower_cards'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: add_flower_cards of class  gamer::protocol::PlayerCardsMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_player_cards_msg_protocol_gamer_protocol_PlayerCardsMsgProtocol_add_flower_cards00
static int tolua_player_cards_msg_protocol_gamer_protocol_PlayerCardsMsgProtocol_add_flower_cards00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"gamer::protocol::PlayerCardsMsgProtocol",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  gamer::protocol::PlayerCardsMsgProtocol* self = (gamer::protocol::PlayerCardsMsgProtocol*)  tolua_tousertype(tolua_S,1,0);
  int value = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'add_flower_cards'", NULL);
#endif
  {
   self->add_flower_cards(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'add_flower_cards'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: season_cards_size of class  gamer::protocol::PlayerCardsMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_player_cards_msg_protocol_gamer_protocol_PlayerCardsMsgProtocol_season_cards_size00
static int tolua_player_cards_msg_protocol_gamer_protocol_PlayerCardsMsgProtocol_season_cards_size00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const gamer::protocol::PlayerCardsMsgProtocol",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const gamer::protocol::PlayerCardsMsgProtocol* self = (const gamer::protocol::PlayerCardsMsgProtocol*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'season_cards_size'", NULL);
#endif
  {
   int tolua_ret = (int)  self->season_cards_size();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'season_cards_size'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: season_cards of class  gamer::protocol::PlayerCardsMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_player_cards_msg_protocol_gamer_protocol_PlayerCardsMsgProtocol_season_cards00
static int tolua_player_cards_msg_protocol_gamer_protocol_PlayerCardsMsgProtocol_season_cards00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const gamer::protocol::PlayerCardsMsgProtocol",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const gamer::protocol::PlayerCardsMsgProtocol* self = (const gamer::protocol::PlayerCardsMsgProtocol*)  tolua_tousertype(tolua_S,1,0);
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'season_cards'", NULL);
#endif
  {
   int tolua_ret = (int)  self->season_cards(index);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'season_cards'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: add_season_cards of class  gamer::protocol::PlayerCardsMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_player_cards_msg_protocol_gamer_protocol_PlayerCardsMsgProtocol_add_season_cards00
static int tolua_player_cards_msg_protocol_gamer_protocol_PlayerCardsMsgProtocol_add_season_cards00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"gamer::protocol::PlayerCardsMsgProtocol",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  gamer::protocol::PlayerCardsMsgProtocol* self = (gamer::protocol::PlayerCardsMsgProtocol*)  tolua_tousertype(tolua_S,1,0);
  int value = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'add_season_cards'", NULL);
#endif
  {
   self->add_season_cards(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'add_season_cards'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: waiting_cards_size of class  gamer::protocol::PlayerCardsMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_player_cards_msg_protocol_gamer_protocol_PlayerCardsMsgProtocol_waiting_cards_size00
static int tolua_player_cards_msg_protocol_gamer_protocol_PlayerCardsMsgProtocol_waiting_cards_size00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const gamer::protocol::PlayerCardsMsgProtocol",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const gamer::protocol::PlayerCardsMsgProtocol* self = (const gamer::protocol::PlayerCardsMsgProtocol*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'waiting_cards_size'", NULL);
#endif
  {
   int tolua_ret = (int)  self->waiting_cards_size();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'waiting_cards_size'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: waiting_cards of class  gamer::protocol::PlayerCardsMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_player_cards_msg_protocol_gamer_protocol_PlayerCardsMsgProtocol_waiting_cards00
static int tolua_player_cards_msg_protocol_gamer_protocol_PlayerCardsMsgProtocol_waiting_cards00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const gamer::protocol::PlayerCardsMsgProtocol",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const gamer::protocol::PlayerCardsMsgProtocol* self = (const gamer::protocol::PlayerCardsMsgProtocol*)  tolua_tousertype(tolua_S,1,0);
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'waiting_cards'", NULL);
#endif
  {
   int tolua_ret = (int)  self->waiting_cards(index);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'waiting_cards'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: add_waiting_cards of class  gamer::protocol::PlayerCardsMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_player_cards_msg_protocol_gamer_protocol_PlayerCardsMsgProtocol_add_waiting_cards00
static int tolua_player_cards_msg_protocol_gamer_protocol_PlayerCardsMsgProtocol_add_waiting_cards00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"gamer::protocol::PlayerCardsMsgProtocol",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  gamer::protocol::PlayerCardsMsgProtocol* self = (gamer::protocol::PlayerCardsMsgProtocol*)  tolua_tousertype(tolua_S,1,0);
  int value = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'add_waiting_cards'", NULL);
#endif
  {
   self->add_waiting_cards(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'add_waiting_cards'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_player_cards_msg_protocol_open (lua_State* tolua_S)
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
    tolua_cclass(tolua_S,"PlayerCardsMsgProtocol","gamer::protocol::PlayerCardsMsgProtocol","google::protobuf::Message",tolua_collect_gamer__protocol__PlayerCardsMsgProtocol);
    #else
    tolua_cclass(tolua_S,"PlayerCardsMsgProtocol","gamer::protocol::PlayerCardsMsgProtocol","google::protobuf::Message",NULL);
    #endif
    tolua_beginmodule(tolua_S,"PlayerCardsMsgProtocol");
     tolua_function(tolua_S,"new",tolua_player_cards_msg_protocol_gamer_protocol_PlayerCardsMsgProtocol_new00);
     tolua_function(tolua_S,"new_local",tolua_player_cards_msg_protocol_gamer_protocol_PlayerCardsMsgProtocol_new00_local);
     tolua_function(tolua_S,".call",tolua_player_cards_msg_protocol_gamer_protocol_PlayerCardsMsgProtocol_new00_local);
     tolua_function(tolua_S,"ByteSize",tolua_player_cards_msg_protocol_gamer_protocol_PlayerCardsMsgProtocol_ByteSize00);
     tolua_function(tolua_S,"player_id",tolua_player_cards_msg_protocol_gamer_protocol_PlayerCardsMsgProtocol_player_id00);
     tolua_function(tolua_S,"visible_hand_cards_size",tolua_player_cards_msg_protocol_gamer_protocol_PlayerCardsMsgProtocol_visible_hand_cards_size00);
     tolua_function(tolua_S,"visible_hand_cards",tolua_player_cards_msg_protocol_gamer_protocol_PlayerCardsMsgProtocol_visible_hand_cards00);
     tolua_function(tolua_S,"add_visible_hand_cards",tolua_player_cards_msg_protocol_gamer_protocol_PlayerCardsMsgProtocol_add_visible_hand_cards00);
     tolua_function(tolua_S,"invisible_hand_cards_size",tolua_player_cards_msg_protocol_gamer_protocol_PlayerCardsMsgProtocol_invisible_hand_cards_size00);
     tolua_function(tolua_S,"invisible_hand_cards",tolua_player_cards_msg_protocol_gamer_protocol_PlayerCardsMsgProtocol_invisible_hand_cards00);
     tolua_function(tolua_S,"add_invisible_hand_cards",tolua_player_cards_msg_protocol_gamer_protocol_PlayerCardsMsgProtocol_add_invisible_hand_cards00);
     tolua_function(tolua_S,"flower_cards_size",tolua_player_cards_msg_protocol_gamer_protocol_PlayerCardsMsgProtocol_flower_cards_size00);
     tolua_function(tolua_S,"flower_cards",tolua_player_cards_msg_protocol_gamer_protocol_PlayerCardsMsgProtocol_flower_cards00);
     tolua_function(tolua_S,"add_flower_cards",tolua_player_cards_msg_protocol_gamer_protocol_PlayerCardsMsgProtocol_add_flower_cards00);
     tolua_function(tolua_S,"season_cards_size",tolua_player_cards_msg_protocol_gamer_protocol_PlayerCardsMsgProtocol_season_cards_size00);
     tolua_function(tolua_S,"season_cards",tolua_player_cards_msg_protocol_gamer_protocol_PlayerCardsMsgProtocol_season_cards00);
     tolua_function(tolua_S,"add_season_cards",tolua_player_cards_msg_protocol_gamer_protocol_PlayerCardsMsgProtocol_add_season_cards00);
     tolua_function(tolua_S,"waiting_cards_size",tolua_player_cards_msg_protocol_gamer_protocol_PlayerCardsMsgProtocol_waiting_cards_size00);
     tolua_function(tolua_S,"waiting_cards",tolua_player_cards_msg_protocol_gamer_protocol_PlayerCardsMsgProtocol_waiting_cards00);
     tolua_function(tolua_S,"add_waiting_cards",tolua_player_cards_msg_protocol_gamer_protocol_PlayerCardsMsgProtocol_add_waiting_cards00);
    tolua_endmodule(tolua_S);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_player_cards_msg_protocol (lua_State* tolua_S) {
 return tolua_player_cards_msg_protocol_open(tolua_S);
};
#endif


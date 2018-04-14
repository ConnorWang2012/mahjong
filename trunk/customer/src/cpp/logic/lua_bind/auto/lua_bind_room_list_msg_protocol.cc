/*
** Lua binding: room_list_msg_protocol
** Generated automatically by tolua++-1.0.92 on 04/14/18 21:43:12.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_room_list_msg_protocol_open (lua_State* tolua_S);

#include "msg/protocol/room_list_msg_protocol.pb.h"
#include <string>
#include <google/protobuf/stubs/common.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/unknown_field_set.h>

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_gamer__protocol__RoomListMsgProtocol (lua_State* tolua_S)
{
 gamer::protocol::RoomListMsgProtocol* self = (gamer::protocol::RoomListMsgProtocol*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_gamer__protocol__RoomItemMsgProtocol (lua_State* tolua_S)
{
 gamer::protocol::RoomItemMsgProtocol* self = (gamer::protocol::RoomItemMsgProtocol*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"gamer::protocol::RoomItemMsgProtocol");
 tolua_usertype(tolua_S,"gamer::protocol::RoomListMsgProtocol");
 tolua_usertype(tolua_S,"google::protobuf::Message");
}

/* method: new of class  gamer::protocol::RoomItemMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_room_list_msg_protocol_gamer_protocol_RoomItemMsgProtocol_new00
static int tolua_room_list_msg_protocol_gamer_protocol_RoomItemMsgProtocol_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"gamer::protocol::RoomItemMsgProtocol",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   gamer::protocol::RoomItemMsgProtocol* tolua_ret = (gamer::protocol::RoomItemMsgProtocol*)  Mtolua_new((gamer::protocol::RoomItemMsgProtocol)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"gamer::protocol::RoomItemMsgProtocol");
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

/* method: new_local of class  gamer::protocol::RoomItemMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_room_list_msg_protocol_gamer_protocol_RoomItemMsgProtocol_new00_local
static int tolua_room_list_msg_protocol_gamer_protocol_RoomItemMsgProtocol_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"gamer::protocol::RoomItemMsgProtocol",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   gamer::protocol::RoomItemMsgProtocol* tolua_ret = (gamer::protocol::RoomItemMsgProtocol*)  Mtolua_new((gamer::protocol::RoomItemMsgProtocol)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"gamer::protocol::RoomItemMsgProtocol");
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

/* method: ByteSize of class  gamer::protocol::RoomItemMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_room_list_msg_protocol_gamer_protocol_RoomItemMsgProtocol_ByteSize00
static int tolua_room_list_msg_protocol_gamer_protocol_RoomItemMsgProtocol_ByteSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const gamer::protocol::RoomItemMsgProtocol",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const gamer::protocol::RoomItemMsgProtocol* self = (const gamer::protocol::RoomItemMsgProtocol*)  tolua_tousertype(tolua_S,1,0);
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

/* method: set_room_id of class  gamer::protocol::RoomItemMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_room_list_msg_protocol_gamer_protocol_RoomItemMsgProtocol_set_room_id00
static int tolua_room_list_msg_protocol_gamer_protocol_RoomItemMsgProtocol_set_room_id00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"gamer::protocol::RoomItemMsgProtocol",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  gamer::protocol::RoomItemMsgProtocol* self = (gamer::protocol::RoomItemMsgProtocol*)  tolua_tousertype(tolua_S,1,0);
  unsigned int value = ((unsigned int)  tolua_tonumber(tolua_S,2,0));
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

/* method: room_id of class  gamer::protocol::RoomItemMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_room_list_msg_protocol_gamer_protocol_RoomItemMsgProtocol_room_id00
static int tolua_room_list_msg_protocol_gamer_protocol_RoomItemMsgProtocol_room_id00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const gamer::protocol::RoomItemMsgProtocol",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const gamer::protocol::RoomItemMsgProtocol* self = (const gamer::protocol::RoomItemMsgProtocol*)  tolua_tousertype(tolua_S,1,0);
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

/* method: set_room_type of class  gamer::protocol::RoomItemMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_room_list_msg_protocol_gamer_protocol_RoomItemMsgProtocol_set_room_type00
static int tolua_room_list_msg_protocol_gamer_protocol_RoomItemMsgProtocol_set_room_type00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"gamer::protocol::RoomItemMsgProtocol",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  gamer::protocol::RoomItemMsgProtocol* self = (gamer::protocol::RoomItemMsgProtocol*)  tolua_tousertype(tolua_S,1,0);
  unsigned int value = ((unsigned int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'set_room_type'", NULL);
#endif
  {
   self->set_room_type(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'set_room_type'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: room_type of class  gamer::protocol::RoomItemMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_room_list_msg_protocol_gamer_protocol_RoomItemMsgProtocol_room_type00
static int tolua_room_list_msg_protocol_gamer_protocol_RoomItemMsgProtocol_room_type00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const gamer::protocol::RoomItemMsgProtocol",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const gamer::protocol::RoomItemMsgProtocol* self = (const gamer::protocol::RoomItemMsgProtocol*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'room_type'", NULL);
#endif
  {
   unsigned int tolua_ret = (unsigned int)  self->room_type();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'room_type'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: set_sub_room_type of class  gamer::protocol::RoomItemMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_room_list_msg_protocol_gamer_protocol_RoomItemMsgProtocol_set_sub_room_type00
static int tolua_room_list_msg_protocol_gamer_protocol_RoomItemMsgProtocol_set_sub_room_type00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"gamer::protocol::RoomItemMsgProtocol",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  gamer::protocol::RoomItemMsgProtocol* self = (gamer::protocol::RoomItemMsgProtocol*)  tolua_tousertype(tolua_S,1,0);
  unsigned int value = ((unsigned int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'set_sub_room_type'", NULL);
#endif
  {
   self->set_sub_room_type(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'set_sub_room_type'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: sub_room_type of class  gamer::protocol::RoomItemMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_room_list_msg_protocol_gamer_protocol_RoomItemMsgProtocol_sub_room_type00
static int tolua_room_list_msg_protocol_gamer_protocol_RoomItemMsgProtocol_sub_room_type00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const gamer::protocol::RoomItemMsgProtocol",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const gamer::protocol::RoomItemMsgProtocol* self = (const gamer::protocol::RoomItemMsgProtocol*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'sub_room_type'", NULL);
#endif
  {
   unsigned int tolua_ret = (unsigned int)  self->sub_room_type();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'sub_room_type'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: set_score_type of class  gamer::protocol::RoomItemMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_room_list_msg_protocol_gamer_protocol_RoomItemMsgProtocol_set_score_type00
static int tolua_room_list_msg_protocol_gamer_protocol_RoomItemMsgProtocol_set_score_type00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"gamer::protocol::RoomItemMsgProtocol",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  gamer::protocol::RoomItemMsgProtocol* self = (gamer::protocol::RoomItemMsgProtocol*)  tolua_tousertype(tolua_S,1,0);
  unsigned int value = ((unsigned int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'set_score_type'", NULL);
#endif
  {
   self->set_score_type(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'set_score_type'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: score_type of class  gamer::protocol::RoomItemMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_room_list_msg_protocol_gamer_protocol_RoomItemMsgProtocol_score_type00
static int tolua_room_list_msg_protocol_gamer_protocol_RoomItemMsgProtocol_score_type00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const gamer::protocol::RoomItemMsgProtocol",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const gamer::protocol::RoomItemMsgProtocol* self = (const gamer::protocol::RoomItemMsgProtocol*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'score_type'", NULL);
#endif
  {
   unsigned int tolua_ret = (unsigned int)  self->score_type();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'score_type'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: set_cost_score of class  gamer::protocol::RoomItemMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_room_list_msg_protocol_gamer_protocol_RoomItemMsgProtocol_set_cost_score00
static int tolua_room_list_msg_protocol_gamer_protocol_RoomItemMsgProtocol_set_cost_score00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"gamer::protocol::RoomItemMsgProtocol",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  gamer::protocol::RoomItemMsgProtocol* self = (gamer::protocol::RoomItemMsgProtocol*)  tolua_tousertype(tolua_S,1,0);
  unsigned int value = ((unsigned int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'set_cost_score'", NULL);
#endif
  {
   self->set_cost_score(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'set_cost_score'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: cost_score of class  gamer::protocol::RoomItemMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_room_list_msg_protocol_gamer_protocol_RoomItemMsgProtocol_cost_score00
static int tolua_room_list_msg_protocol_gamer_protocol_RoomItemMsgProtocol_cost_score00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const gamer::protocol::RoomItemMsgProtocol",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const gamer::protocol::RoomItemMsgProtocol* self = (const gamer::protocol::RoomItemMsgProtocol*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'cost_score'", NULL);
#endif
  {
   unsigned int tolua_ret = (unsigned int)  self->cost_score();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'cost_score'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: set_min_score of class  gamer::protocol::RoomItemMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_room_list_msg_protocol_gamer_protocol_RoomItemMsgProtocol_set_min_score00
static int tolua_room_list_msg_protocol_gamer_protocol_RoomItemMsgProtocol_set_min_score00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"gamer::protocol::RoomItemMsgProtocol",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  gamer::protocol::RoomItemMsgProtocol* self = (gamer::protocol::RoomItemMsgProtocol*)  tolua_tousertype(tolua_S,1,0);
  unsigned int value = ((unsigned int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'set_min_score'", NULL);
#endif
  {
   self->set_min_score(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'set_min_score'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: min_score of class  gamer::protocol::RoomItemMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_room_list_msg_protocol_gamer_protocol_RoomItemMsgProtocol_min_score00
static int tolua_room_list_msg_protocol_gamer_protocol_RoomItemMsgProtocol_min_score00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const gamer::protocol::RoomItemMsgProtocol",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const gamer::protocol::RoomItemMsgProtocol* self = (const gamer::protocol::RoomItemMsgProtocol*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'min_score'", NULL);
#endif
  {
   unsigned int tolua_ret = (unsigned int)  self->min_score();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'min_score'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: set_base_score of class  gamer::protocol::RoomItemMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_room_list_msg_protocol_gamer_protocol_RoomItemMsgProtocol_set_base_score00
static int tolua_room_list_msg_protocol_gamer_protocol_RoomItemMsgProtocol_set_base_score00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"gamer::protocol::RoomItemMsgProtocol",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  gamer::protocol::RoomItemMsgProtocol* self = (gamer::protocol::RoomItemMsgProtocol*)  tolua_tousertype(tolua_S,1,0);
  unsigned int value = ((unsigned int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'set_base_score'", NULL);
#endif
  {
   self->set_base_score(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'set_base_score'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: base_score of class  gamer::protocol::RoomItemMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_room_list_msg_protocol_gamer_protocol_RoomItemMsgProtocol_base_score00
static int tolua_room_list_msg_protocol_gamer_protocol_RoomItemMsgProtocol_base_score00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const gamer::protocol::RoomItemMsgProtocol",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const gamer::protocol::RoomItemMsgProtocol* self = (const gamer::protocol::RoomItemMsgProtocol*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'base_score'", NULL);
#endif
  {
   unsigned int tolua_ret = (unsigned int)  self->base_score();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'base_score'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: set_cur_players_num of class  gamer::protocol::RoomItemMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_room_list_msg_protocol_gamer_protocol_RoomItemMsgProtocol_set_cur_players_num00
static int tolua_room_list_msg_protocol_gamer_protocol_RoomItemMsgProtocol_set_cur_players_num00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"gamer::protocol::RoomItemMsgProtocol",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  gamer::protocol::RoomItemMsgProtocol* self = (gamer::protocol::RoomItemMsgProtocol*)  tolua_tousertype(tolua_S,1,0);
  unsigned int value = ((unsigned int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'set_cur_players_num'", NULL);
#endif
  {
   self->set_cur_players_num(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'set_cur_players_num'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: cur_players_num of class  gamer::protocol::RoomItemMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_room_list_msg_protocol_gamer_protocol_RoomItemMsgProtocol_cur_players_num00
static int tolua_room_list_msg_protocol_gamer_protocol_RoomItemMsgProtocol_cur_players_num00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const gamer::protocol::RoomItemMsgProtocol",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const gamer::protocol::RoomItemMsgProtocol* self = (const gamer::protocol::RoomItemMsgProtocol*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'cur_players_num'", NULL);
#endif
  {
   unsigned int tolua_ret = (unsigned int)  self->cur_players_num();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'cur_players_num'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  gamer::protocol::RoomListMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_room_list_msg_protocol_gamer_protocol_RoomListMsgProtocol_new00
static int tolua_room_list_msg_protocol_gamer_protocol_RoomListMsgProtocol_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"gamer::protocol::RoomListMsgProtocol",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   gamer::protocol::RoomListMsgProtocol* tolua_ret = (gamer::protocol::RoomListMsgProtocol*)  Mtolua_new((gamer::protocol::RoomListMsgProtocol)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"gamer::protocol::RoomListMsgProtocol");
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

/* method: new_local of class  gamer::protocol::RoomListMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_room_list_msg_protocol_gamer_protocol_RoomListMsgProtocol_new00_local
static int tolua_room_list_msg_protocol_gamer_protocol_RoomListMsgProtocol_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"gamer::protocol::RoomListMsgProtocol",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   gamer::protocol::RoomListMsgProtocol* tolua_ret = (gamer::protocol::RoomListMsgProtocol*)  Mtolua_new((gamer::protocol::RoomListMsgProtocol)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"gamer::protocol::RoomListMsgProtocol");
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

/* method: ByteSize of class  gamer::protocol::RoomListMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_room_list_msg_protocol_gamer_protocol_RoomListMsgProtocol_ByteSize00
static int tolua_room_list_msg_protocol_gamer_protocol_RoomListMsgProtocol_ByteSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const gamer::protocol::RoomListMsgProtocol",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const gamer::protocol::RoomListMsgProtocol* self = (const gamer::protocol::RoomListMsgProtocol*)  tolua_tousertype(tolua_S,1,0);
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

/* method: set_player_id of class  gamer::protocol::RoomListMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_room_list_msg_protocol_gamer_protocol_RoomListMsgProtocol_set_player_id00
static int tolua_room_list_msg_protocol_gamer_protocol_RoomListMsgProtocol_set_player_id00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"gamer::protocol::RoomListMsgProtocol",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  gamer::protocol::RoomListMsgProtocol* self = (gamer::protocol::RoomListMsgProtocol*)  tolua_tousertype(tolua_S,1,0);
  unsigned int value = ((unsigned int)  tolua_tonumber(tolua_S,2,0));
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

/* method: player_id of class  gamer::protocol::RoomListMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_room_list_msg_protocol_gamer_protocol_RoomListMsgProtocol_player_id00
static int tolua_room_list_msg_protocol_gamer_protocol_RoomListMsgProtocol_player_id00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const gamer::protocol::RoomListMsgProtocol",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const gamer::protocol::RoomListMsgProtocol* self = (const gamer::protocol::RoomListMsgProtocol*)  tolua_tousertype(tolua_S,1,0);
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

/* method: room_items_size of class  gamer::protocol::RoomListMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_room_list_msg_protocol_gamer_protocol_RoomListMsgProtocol_room_items_size00
static int tolua_room_list_msg_protocol_gamer_protocol_RoomListMsgProtocol_room_items_size00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const gamer::protocol::RoomListMsgProtocol",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const gamer::protocol::RoomListMsgProtocol* self = (const gamer::protocol::RoomListMsgProtocol*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'room_items_size'", NULL);
#endif
  {
   unsigned int tolua_ret = (unsigned int)  self->room_items_size();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'room_items_size'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: room_items of class  gamer::protocol::RoomListMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_room_list_msg_protocol_gamer_protocol_RoomListMsgProtocol_room_items00
static int tolua_room_list_msg_protocol_gamer_protocol_RoomListMsgProtocol_room_items00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const gamer::protocol::RoomListMsgProtocol",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const gamer::protocol::RoomListMsgProtocol* self = (const gamer::protocol::RoomListMsgProtocol*)  tolua_tousertype(tolua_S,1,0);
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'room_items'", NULL);
#endif
  {
   const gamer::protocol::RoomItemMsgProtocol& tolua_ret = (const gamer::protocol::RoomItemMsgProtocol&)  self->room_items(index);
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const gamer::protocol::RoomItemMsgProtocol");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'room_items'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_room_list_msg_protocol_open (lua_State* tolua_S)
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
    tolua_cclass(tolua_S,"RoomItemMsgProtocol","gamer::protocol::RoomItemMsgProtocol","google::protobuf::Message",tolua_collect_gamer__protocol__RoomItemMsgProtocol);
    #else
    tolua_cclass(tolua_S,"RoomItemMsgProtocol","gamer::protocol::RoomItemMsgProtocol","google::protobuf::Message",NULL);
    #endif
    tolua_beginmodule(tolua_S,"RoomItemMsgProtocol");
     tolua_function(tolua_S,"new",tolua_room_list_msg_protocol_gamer_protocol_RoomItemMsgProtocol_new00);
     tolua_function(tolua_S,"new_local",tolua_room_list_msg_protocol_gamer_protocol_RoomItemMsgProtocol_new00_local);
     tolua_function(tolua_S,".call",tolua_room_list_msg_protocol_gamer_protocol_RoomItemMsgProtocol_new00_local);
     tolua_function(tolua_S,"ByteSize",tolua_room_list_msg_protocol_gamer_protocol_RoomItemMsgProtocol_ByteSize00);
     tolua_function(tolua_S,"set_room_id",tolua_room_list_msg_protocol_gamer_protocol_RoomItemMsgProtocol_set_room_id00);
     tolua_function(tolua_S,"room_id",tolua_room_list_msg_protocol_gamer_protocol_RoomItemMsgProtocol_room_id00);
     tolua_function(tolua_S,"set_room_type",tolua_room_list_msg_protocol_gamer_protocol_RoomItemMsgProtocol_set_room_type00);
     tolua_function(tolua_S,"room_type",tolua_room_list_msg_protocol_gamer_protocol_RoomItemMsgProtocol_room_type00);
     tolua_function(tolua_S,"set_sub_room_type",tolua_room_list_msg_protocol_gamer_protocol_RoomItemMsgProtocol_set_sub_room_type00);
     tolua_function(tolua_S,"sub_room_type",tolua_room_list_msg_protocol_gamer_protocol_RoomItemMsgProtocol_sub_room_type00);
     tolua_function(tolua_S,"set_score_type",tolua_room_list_msg_protocol_gamer_protocol_RoomItemMsgProtocol_set_score_type00);
     tolua_function(tolua_S,"score_type",tolua_room_list_msg_protocol_gamer_protocol_RoomItemMsgProtocol_score_type00);
     tolua_function(tolua_S,"set_cost_score",tolua_room_list_msg_protocol_gamer_protocol_RoomItemMsgProtocol_set_cost_score00);
     tolua_function(tolua_S,"cost_score",tolua_room_list_msg_protocol_gamer_protocol_RoomItemMsgProtocol_cost_score00);
     tolua_function(tolua_S,"set_min_score",tolua_room_list_msg_protocol_gamer_protocol_RoomItemMsgProtocol_set_min_score00);
     tolua_function(tolua_S,"min_score",tolua_room_list_msg_protocol_gamer_protocol_RoomItemMsgProtocol_min_score00);
     tolua_function(tolua_S,"set_base_score",tolua_room_list_msg_protocol_gamer_protocol_RoomItemMsgProtocol_set_base_score00);
     tolua_function(tolua_S,"base_score",tolua_room_list_msg_protocol_gamer_protocol_RoomItemMsgProtocol_base_score00);
     tolua_function(tolua_S,"set_cur_players_num",tolua_room_list_msg_protocol_gamer_protocol_RoomItemMsgProtocol_set_cur_players_num00);
     tolua_function(tolua_S,"cur_players_num",tolua_room_list_msg_protocol_gamer_protocol_RoomItemMsgProtocol_cur_players_num00);
    tolua_endmodule(tolua_S);
    #ifdef __cplusplus
    tolua_cclass(tolua_S,"RoomListMsgProtocol","gamer::protocol::RoomListMsgProtocol","google::protobuf::Message",tolua_collect_gamer__protocol__RoomListMsgProtocol);
    #else
    tolua_cclass(tolua_S,"RoomListMsgProtocol","gamer::protocol::RoomListMsgProtocol","google::protobuf::Message",NULL);
    #endif
    tolua_beginmodule(tolua_S,"RoomListMsgProtocol");
     tolua_function(tolua_S,"new",tolua_room_list_msg_protocol_gamer_protocol_RoomListMsgProtocol_new00);
     tolua_function(tolua_S,"new_local",tolua_room_list_msg_protocol_gamer_protocol_RoomListMsgProtocol_new00_local);
     tolua_function(tolua_S,".call",tolua_room_list_msg_protocol_gamer_protocol_RoomListMsgProtocol_new00_local);
     tolua_function(tolua_S,"ByteSize",tolua_room_list_msg_protocol_gamer_protocol_RoomListMsgProtocol_ByteSize00);
     tolua_function(tolua_S,"set_player_id",tolua_room_list_msg_protocol_gamer_protocol_RoomListMsgProtocol_set_player_id00);
     tolua_function(tolua_S,"player_id",tolua_room_list_msg_protocol_gamer_protocol_RoomListMsgProtocol_player_id00);
     tolua_function(tolua_S,"room_items_size",tolua_room_list_msg_protocol_gamer_protocol_RoomListMsgProtocol_room_items_size00);
     tolua_function(tolua_S,"room_items",tolua_room_list_msg_protocol_gamer_protocol_RoomListMsgProtocol_room_items00);
    tolua_endmodule(tolua_S);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_room_list_msg_protocol (lua_State* tolua_S) {
 return tolua_room_list_msg_protocol_open(tolua_S);
};
#endif


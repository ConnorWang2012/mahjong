/*
** Lua binding: create_room_msg_protocol
** Generated automatically by tolua++-1.0.92 on 06/16/17 21:12:38.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_create_room_msg_protocol_open (lua_State* tolua_S);

#include "create_room_msg_protocol.pb.h"
#include <string>
#include <google/protobuf/stubs/common.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/unknown_field_set.h>

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_gamer__protocol__CreateRoomMsgProtocol (lua_State* tolua_S)
{
 gamer::protocol::CreateRoomMsgProtocol* self = (gamer::protocol::CreateRoomMsgProtocol*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"google::protobuf::Message");
 tolua_usertype(tolua_S,"gamer::protocol::CreateRoomMsgProtocol");
}

/* method: new of class  gamer::protocol::CreateRoomMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_create_room_msg_protocol_gamer_protocol_CreateRoomMsgProtocol_new00
static int tolua_create_room_msg_protocol_gamer_protocol_CreateRoomMsgProtocol_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"gamer::protocol::CreateRoomMsgProtocol",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   gamer::protocol::CreateRoomMsgProtocol* tolua_ret = (gamer::protocol::CreateRoomMsgProtocol*)  Mtolua_new((gamer::protocol::CreateRoomMsgProtocol)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"gamer::protocol::CreateRoomMsgProtocol");
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

/* method: new_local of class  gamer::protocol::CreateRoomMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_create_room_msg_protocol_gamer_protocol_CreateRoomMsgProtocol_new00_local
static int tolua_create_room_msg_protocol_gamer_protocol_CreateRoomMsgProtocol_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"gamer::protocol::CreateRoomMsgProtocol",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   gamer::protocol::CreateRoomMsgProtocol* tolua_ret = (gamer::protocol::CreateRoomMsgProtocol*)  Mtolua_new((gamer::protocol::CreateRoomMsgProtocol)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"gamer::protocol::CreateRoomMsgProtocol");
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

/* method: ByteSize of class  gamer::protocol::CreateRoomMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_create_room_msg_protocol_gamer_protocol_CreateRoomMsgProtocol_ByteSize00
static int tolua_create_room_msg_protocol_gamer_protocol_CreateRoomMsgProtocol_ByteSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const gamer::protocol::CreateRoomMsgProtocol",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const gamer::protocol::CreateRoomMsgProtocol* self = (const gamer::protocol::CreateRoomMsgProtocol*)  tolua_tousertype(tolua_S,1,0);
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

/* method: set_room_owner_id of class  gamer::protocol::CreateRoomMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_create_room_msg_protocol_gamer_protocol_CreateRoomMsgProtocol_set_room_owner_id00
static int tolua_create_room_msg_protocol_gamer_protocol_CreateRoomMsgProtocol_set_room_owner_id00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"gamer::protocol::CreateRoomMsgProtocol",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  gamer::protocol::CreateRoomMsgProtocol* self = (gamer::protocol::CreateRoomMsgProtocol*)  tolua_tousertype(tolua_S,1,0);
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

/* method: room_owner_id of class  gamer::protocol::CreateRoomMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_create_room_msg_protocol_gamer_protocol_CreateRoomMsgProtocol_room_owner_id00
static int tolua_create_room_msg_protocol_gamer_protocol_CreateRoomMsgProtocol_room_owner_id00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const gamer::protocol::CreateRoomMsgProtocol",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const gamer::protocol::CreateRoomMsgProtocol* self = (const gamer::protocol::CreateRoomMsgProtocol*)  tolua_tousertype(tolua_S,1,0);
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

/* method: set_rounds_num of class  gamer::protocol::CreateRoomMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_create_room_msg_protocol_gamer_protocol_CreateRoomMsgProtocol_set_rounds_num00
static int tolua_create_room_msg_protocol_gamer_protocol_CreateRoomMsgProtocol_set_rounds_num00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"gamer::protocol::CreateRoomMsgProtocol",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  gamer::protocol::CreateRoomMsgProtocol* self = (gamer::protocol::CreateRoomMsgProtocol*)  tolua_tousertype(tolua_S,1,0);
  int value = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'set_rounds_num'", NULL);
#endif
  {
   self->set_rounds_num(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'set_rounds_num'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: rounds_num of class  gamer::protocol::CreateRoomMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_create_room_msg_protocol_gamer_protocol_CreateRoomMsgProtocol_rounds_num00
static int tolua_create_room_msg_protocol_gamer_protocol_CreateRoomMsgProtocol_rounds_num00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const gamer::protocol::CreateRoomMsgProtocol",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const gamer::protocol::CreateRoomMsgProtocol* self = (const gamer::protocol::CreateRoomMsgProtocol*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'rounds_num'", NULL);
#endif
  {
   int tolua_ret = (int)  self->rounds_num();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'rounds_num'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: set_players_num of class  gamer::protocol::CreateRoomMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_create_room_msg_protocol_gamer_protocol_CreateRoomMsgProtocol_set_players_num00
static int tolua_create_room_msg_protocol_gamer_protocol_CreateRoomMsgProtocol_set_players_num00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"gamer::protocol::CreateRoomMsgProtocol",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  gamer::protocol::CreateRoomMsgProtocol* self = (gamer::protocol::CreateRoomMsgProtocol*)  tolua_tousertype(tolua_S,1,0);
  int value = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'set_players_num'", NULL);
#endif
  {
   self->set_players_num(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'set_players_num'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: players_num of class  gamer::protocol::CreateRoomMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_create_room_msg_protocol_gamer_protocol_CreateRoomMsgProtocol_players_num00
static int tolua_create_room_msg_protocol_gamer_protocol_CreateRoomMsgProtocol_players_num00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const gamer::protocol::CreateRoomMsgProtocol",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const gamer::protocol::CreateRoomMsgProtocol* self = (const gamer::protocol::CreateRoomMsgProtocol*)  tolua_tousertype(tolua_S,1,0);
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

/* method: set_room_cards_num of class  gamer::protocol::CreateRoomMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_create_room_msg_protocol_gamer_protocol_CreateRoomMsgProtocol_set_room_cards_num00
static int tolua_create_room_msg_protocol_gamer_protocol_CreateRoomMsgProtocol_set_room_cards_num00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"gamer::protocol::CreateRoomMsgProtocol",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  gamer::protocol::CreateRoomMsgProtocol* self = (gamer::protocol::CreateRoomMsgProtocol*)  tolua_tousertype(tolua_S,1,0);
  int value = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'set_room_cards_num'", NULL);
#endif
  {
   self->set_room_cards_num(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'set_room_cards_num'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: room_cards_num of class  gamer::protocol::CreateRoomMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_create_room_msg_protocol_gamer_protocol_CreateRoomMsgProtocol_room_cards_num00
static int tolua_create_room_msg_protocol_gamer_protocol_CreateRoomMsgProtocol_room_cards_num00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const gamer::protocol::CreateRoomMsgProtocol",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const gamer::protocol::CreateRoomMsgProtocol* self = (const gamer::protocol::CreateRoomMsgProtocol*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'room_cards_num'", NULL);
#endif
  {
   int tolua_ret = (int)  self->room_cards_num();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'room_cards_num'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: room_id of class  gamer::protocol::CreateRoomMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_create_room_msg_protocol_gamer_protocol_CreateRoomMsgProtocol_room_id00
static int tolua_create_room_msg_protocol_gamer_protocol_CreateRoomMsgProtocol_room_id00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const gamer::protocol::CreateRoomMsgProtocol",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const gamer::protocol::CreateRoomMsgProtocol* self = (const gamer::protocol::CreateRoomMsgProtocol*)  tolua_tousertype(tolua_S,1,0);
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

/* method: room_owner_id of class  gamer::protocol::CreateRoomMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_create_room_msg_protocol_gamer_protocol_CreateRoomMsgProtocol_room_owner_id01
static int tolua_create_room_msg_protocol_gamer_protocol_CreateRoomMsgProtocol_room_owner_id01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const gamer::protocol::CreateRoomMsgProtocol",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const gamer::protocol::CreateRoomMsgProtocol* self = (const gamer::protocol::CreateRoomMsgProtocol*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'room_owner_id'", NULL);
#endif
  {
   int tolua_ret = (int)  self->room_owner_id();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
tolua_lerror:
 return tolua_create_room_msg_protocol_gamer_protocol_CreateRoomMsgProtocol_room_owner_id00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_create_room_msg_protocol_open (lua_State* tolua_S)
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
    tolua_cclass(tolua_S,"CreateRoomMsgProtocol","gamer::protocol::CreateRoomMsgProtocol","google::protobuf::Message",tolua_collect_gamer__protocol__CreateRoomMsgProtocol);
    #else
    tolua_cclass(tolua_S,"CreateRoomMsgProtocol","gamer::protocol::CreateRoomMsgProtocol","google::protobuf::Message",NULL);
    #endif
    tolua_beginmodule(tolua_S,"CreateRoomMsgProtocol");
     tolua_function(tolua_S,"new",tolua_create_room_msg_protocol_gamer_protocol_CreateRoomMsgProtocol_new00);
     tolua_function(tolua_S,"new_local",tolua_create_room_msg_protocol_gamer_protocol_CreateRoomMsgProtocol_new00_local);
     tolua_function(tolua_S,".call",tolua_create_room_msg_protocol_gamer_protocol_CreateRoomMsgProtocol_new00_local);
     tolua_function(tolua_S,"ByteSize",tolua_create_room_msg_protocol_gamer_protocol_CreateRoomMsgProtocol_ByteSize00);
     tolua_function(tolua_S,"set_room_owner_id",tolua_create_room_msg_protocol_gamer_protocol_CreateRoomMsgProtocol_set_room_owner_id00);
     tolua_function(tolua_S,"room_owner_id",tolua_create_room_msg_protocol_gamer_protocol_CreateRoomMsgProtocol_room_owner_id00);
     tolua_function(tolua_S,"set_rounds_num",tolua_create_room_msg_protocol_gamer_protocol_CreateRoomMsgProtocol_set_rounds_num00);
     tolua_function(tolua_S,"rounds_num",tolua_create_room_msg_protocol_gamer_protocol_CreateRoomMsgProtocol_rounds_num00);
     tolua_function(tolua_S,"set_players_num",tolua_create_room_msg_protocol_gamer_protocol_CreateRoomMsgProtocol_set_players_num00);
     tolua_function(tolua_S,"players_num",tolua_create_room_msg_protocol_gamer_protocol_CreateRoomMsgProtocol_players_num00);
     tolua_function(tolua_S,"set_room_cards_num",tolua_create_room_msg_protocol_gamer_protocol_CreateRoomMsgProtocol_set_room_cards_num00);
     tolua_function(tolua_S,"room_cards_num",tolua_create_room_msg_protocol_gamer_protocol_CreateRoomMsgProtocol_room_cards_num00);
     tolua_function(tolua_S,"room_id",tolua_create_room_msg_protocol_gamer_protocol_CreateRoomMsgProtocol_room_id00);
     tolua_function(tolua_S,"room_owner_id",tolua_create_room_msg_protocol_gamer_protocol_CreateRoomMsgProtocol_room_owner_id01);
    tolua_endmodule(tolua_S);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_create_room_msg_protocol (lua_State* tolua_S) {
 return tolua_create_room_msg_protocol_open(tolua_S);
};
#endif


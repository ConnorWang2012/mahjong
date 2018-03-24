﻿/*
** Lua binding: personal_head_portrait_msg_protocol
** Generated automatically by tolua++-1.0.92 on 02/10/18 17:01:08.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_personal_head_portrait_msg_protocol_open (lua_State* tolua_S);

#include "msg/protocol/personal_head_portrait_msg_protocol.pb.h"
#include <string>
#include <google/protobuf/stubs/common.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/unknown_field_set.h>

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_gamer__protocol__PersonalHeadPortraitMsgProtocol (lua_State* tolua_S)
{
 gamer::protocol::PersonalHeadPortraitMsgProtocol* self = (gamer::protocol::PersonalHeadPortraitMsgProtocol*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"google::protobuf::Message");
 tolua_usertype(tolua_S,"gamer::protocol::PersonalHeadPortraitMsgProtocol");
}

/* method: new of class  gamer::protocol::PersonalHeadPortraitMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_personal_head_portrait_msg_protocol_gamer_protocol_PersonalHeadPortraitMsgProtocol_new00
static int tolua_personal_head_portrait_msg_protocol_gamer_protocol_PersonalHeadPortraitMsgProtocol_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"gamer::protocol::PersonalHeadPortraitMsgProtocol",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   gamer::protocol::PersonalHeadPortraitMsgProtocol* tolua_ret = (gamer::protocol::PersonalHeadPortraitMsgProtocol*)  Mtolua_new((gamer::protocol::PersonalHeadPortraitMsgProtocol)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"gamer::protocol::PersonalHeadPortraitMsgProtocol");
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

/* method: new_local of class  gamer::protocol::PersonalHeadPortraitMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_personal_head_portrait_msg_protocol_gamer_protocol_PersonalHeadPortraitMsgProtocol_new00_local
static int tolua_personal_head_portrait_msg_protocol_gamer_protocol_PersonalHeadPortraitMsgProtocol_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"gamer::protocol::PersonalHeadPortraitMsgProtocol",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   gamer::protocol::PersonalHeadPortraitMsgProtocol* tolua_ret = (gamer::protocol::PersonalHeadPortraitMsgProtocol*)  Mtolua_new((gamer::protocol::PersonalHeadPortraitMsgProtocol)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"gamer::protocol::PersonalHeadPortraitMsgProtocol");
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

/* method: ByteSize of class  gamer::protocol::PersonalHeadPortraitMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_personal_head_portrait_msg_protocol_gamer_protocol_PersonalHeadPortraitMsgProtocol_ByteSize00
static int tolua_personal_head_portrait_msg_protocol_gamer_protocol_PersonalHeadPortraitMsgProtocol_ByteSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const gamer::protocol::PersonalHeadPortraitMsgProtocol",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const gamer::protocol::PersonalHeadPortraitMsgProtocol* self = (const gamer::protocol::PersonalHeadPortraitMsgProtocol*)  tolua_tousertype(tolua_S,1,0);
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

/* method: set_player_id of class  gamer::protocol::PersonalHeadPortraitMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_personal_head_portrait_msg_protocol_gamer_protocol_PersonalHeadPortraitMsgProtocol_set_player_id00
static int tolua_personal_head_portrait_msg_protocol_gamer_protocol_PersonalHeadPortraitMsgProtocol_set_player_id00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"gamer::protocol::PersonalHeadPortraitMsgProtocol",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  gamer::protocol::PersonalHeadPortraitMsgProtocol* self = (gamer::protocol::PersonalHeadPortraitMsgProtocol*)  tolua_tousertype(tolua_S,1,0);
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

/* method: player_id of class  gamer::protocol::PersonalHeadPortraitMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_personal_head_portrait_msg_protocol_gamer_protocol_PersonalHeadPortraitMsgProtocol_player_id00
static int tolua_personal_head_portrait_msg_protocol_gamer_protocol_PersonalHeadPortraitMsgProtocol_player_id00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const gamer::protocol::PersonalHeadPortraitMsgProtocol",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const gamer::protocol::PersonalHeadPortraitMsgProtocol* self = (const gamer::protocol::PersonalHeadPortraitMsgProtocol*)  tolua_tousertype(tolua_S,1,0);
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

/* method: head_portrait of class  gamer::protocol::PersonalHeadPortraitMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_personal_head_portrait_msg_protocol_gamer_protocol_PersonalHeadPortraitMsgProtocol_head_portrait00
static int tolua_personal_head_portrait_msg_protocol_gamer_protocol_PersonalHeadPortraitMsgProtocol_head_portrait00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const gamer::protocol::PersonalHeadPortraitMsgProtocol",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const gamer::protocol::PersonalHeadPortraitMsgProtocol* self = (const gamer::protocol::PersonalHeadPortraitMsgProtocol*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'head_portrait'", NULL);
#endif
  {
   const std::string tolua_ret = (const std::string)  self->head_portrait();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'head_portrait'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_personal_head_portrait_msg_protocol_open (lua_State* tolua_S)
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
    tolua_cclass(tolua_S,"PersonalHeadPortraitMsgProtocol","gamer::protocol::PersonalHeadPortraitMsgProtocol","google::protobuf::Message",tolua_collect_gamer__protocol__PersonalHeadPortraitMsgProtocol);
    #else
    tolua_cclass(tolua_S,"PersonalHeadPortraitMsgProtocol","gamer::protocol::PersonalHeadPortraitMsgProtocol","google::protobuf::Message",NULL);
    #endif
    tolua_beginmodule(tolua_S,"PersonalHeadPortraitMsgProtocol");
     tolua_function(tolua_S,"new",tolua_personal_head_portrait_msg_protocol_gamer_protocol_PersonalHeadPortraitMsgProtocol_new00);
     tolua_function(tolua_S,"new_local",tolua_personal_head_portrait_msg_protocol_gamer_protocol_PersonalHeadPortraitMsgProtocol_new00_local);
     tolua_function(tolua_S,".call",tolua_personal_head_portrait_msg_protocol_gamer_protocol_PersonalHeadPortraitMsgProtocol_new00_local);
     tolua_function(tolua_S,"ByteSize",tolua_personal_head_portrait_msg_protocol_gamer_protocol_PersonalHeadPortraitMsgProtocol_ByteSize00);
     tolua_function(tolua_S,"set_player_id",tolua_personal_head_portrait_msg_protocol_gamer_protocol_PersonalHeadPortraitMsgProtocol_set_player_id00);
     tolua_function(tolua_S,"player_id",tolua_personal_head_portrait_msg_protocol_gamer_protocol_PersonalHeadPortraitMsgProtocol_player_id00);
     tolua_function(tolua_S,"head_portrait",tolua_personal_head_portrait_msg_protocol_gamer_protocol_PersonalHeadPortraitMsgProtocol_head_portrait00);
    tolua_endmodule(tolua_S);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_personal_head_portrait_msg_protocol (lua_State* tolua_S) {
 return tolua_personal_head_portrait_msg_protocol_open(tolua_S);
};
#endif


/*
** Lua binding: set_property_msg_protocol
** Generated automatically by tolua++-1.0.92 on 12/17/17 15:46:06.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_set_property_msg_protocol_open (lua_State* tolua_S);

#include "msg/protocol/set_property_msg_protocol.pb.h"
#include <string>
#include <google/protobuf/stubs/common.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/unknown_field_set.h>

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_gamer__protocol__SetPropertyMsgProtocol (lua_State* tolua_S)
{
 gamer::protocol::SetPropertyMsgProtocol* self = (gamer::protocol::SetPropertyMsgProtocol*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"google::protobuf::Message");
 tolua_usertype(tolua_S,"gamer::protocol::SetPropertyMsgProtocol");
}

/* method: new of class  gamer::protocol::SetPropertyMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_set_property_msg_protocol_gamer_protocol_SetPropertyMsgProtocol_new00
static int tolua_set_property_msg_protocol_gamer_protocol_SetPropertyMsgProtocol_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"gamer::protocol::SetPropertyMsgProtocol",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   gamer::protocol::SetPropertyMsgProtocol* tolua_ret = (gamer::protocol::SetPropertyMsgProtocol*)  Mtolua_new((gamer::protocol::SetPropertyMsgProtocol)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"gamer::protocol::SetPropertyMsgProtocol");
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

/* method: new_local of class  gamer::protocol::SetPropertyMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_set_property_msg_protocol_gamer_protocol_SetPropertyMsgProtocol_new00_local
static int tolua_set_property_msg_protocol_gamer_protocol_SetPropertyMsgProtocol_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"gamer::protocol::SetPropertyMsgProtocol",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   gamer::protocol::SetPropertyMsgProtocol* tolua_ret = (gamer::protocol::SetPropertyMsgProtocol*)  Mtolua_new((gamer::protocol::SetPropertyMsgProtocol)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"gamer::protocol::SetPropertyMsgProtocol");
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

/* method: ByteSize of class  gamer::protocol::SetPropertyMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_set_property_msg_protocol_gamer_protocol_SetPropertyMsgProtocol_ByteSize00
static int tolua_set_property_msg_protocol_gamer_protocol_SetPropertyMsgProtocol_ByteSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const gamer::protocol::SetPropertyMsgProtocol",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const gamer::protocol::SetPropertyMsgProtocol* self = (const gamer::protocol::SetPropertyMsgProtocol*)  tolua_tousertype(tolua_S,1,0);
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

/* method: set_player_id of class  gamer::protocol::SetPropertyMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_set_property_msg_protocol_gamer_protocol_SetPropertyMsgProtocol_set_player_id00
static int tolua_set_property_msg_protocol_gamer_protocol_SetPropertyMsgProtocol_set_player_id00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"gamer::protocol::SetPropertyMsgProtocol",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  gamer::protocol::SetPropertyMsgProtocol* self = (gamer::protocol::SetPropertyMsgProtocol*)  tolua_tousertype(tolua_S,1,0);
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

/* method: player_id of class  gamer::protocol::SetPropertyMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_set_property_msg_protocol_gamer_protocol_SetPropertyMsgProtocol_player_id00
static int tolua_set_property_msg_protocol_gamer_protocol_SetPropertyMsgProtocol_player_id00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const gamer::protocol::SetPropertyMsgProtocol",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const gamer::protocol::SetPropertyMsgProtocol* self = (const gamer::protocol::SetPropertyMsgProtocol*)  tolua_tousertype(tolua_S,1,0);
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

/* method: property_ids_size of class  gamer::protocol::SetPropertyMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_set_property_msg_protocol_gamer_protocol_SetPropertyMsgProtocol_property_ids_size00
static int tolua_set_property_msg_protocol_gamer_protocol_SetPropertyMsgProtocol_property_ids_size00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const gamer::protocol::SetPropertyMsgProtocol",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const gamer::protocol::SetPropertyMsgProtocol* self = (const gamer::protocol::SetPropertyMsgProtocol*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'property_ids_size'", NULL);
#endif
  {
   int tolua_ret = (int)  self->property_ids_size();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'property_ids_size'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: property_ids of class  gamer::protocol::SetPropertyMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_set_property_msg_protocol_gamer_protocol_SetPropertyMsgProtocol_property_ids00
static int tolua_set_property_msg_protocol_gamer_protocol_SetPropertyMsgProtocol_property_ids00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const gamer::protocol::SetPropertyMsgProtocol",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const gamer::protocol::SetPropertyMsgProtocol* self = (const gamer::protocol::SetPropertyMsgProtocol*)  tolua_tousertype(tolua_S,1,0);
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'property_ids'", NULL);
#endif
  {
   unsigned int tolua_ret = (unsigned int)  self->property_ids(index);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'property_ids'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: set_property_ids of class  gamer::protocol::SetPropertyMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_set_property_msg_protocol_gamer_protocol_SetPropertyMsgProtocol_set_property_ids00
static int tolua_set_property_msg_protocol_gamer_protocol_SetPropertyMsgProtocol_set_property_ids00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"gamer::protocol::SetPropertyMsgProtocol",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  gamer::protocol::SetPropertyMsgProtocol* self = (gamer::protocol::SetPropertyMsgProtocol*)  tolua_tousertype(tolua_S,1,0);
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
  unsigned int value = ((unsigned int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'set_property_ids'", NULL);
#endif
  {
   self->set_property_ids(index,value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'set_property_ids'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: add_property_ids of class  gamer::protocol::SetPropertyMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_set_property_msg_protocol_gamer_protocol_SetPropertyMsgProtocol_add_property_ids00
static int tolua_set_property_msg_protocol_gamer_protocol_SetPropertyMsgProtocol_add_property_ids00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"gamer::protocol::SetPropertyMsgProtocol",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  gamer::protocol::SetPropertyMsgProtocol* self = (gamer::protocol::SetPropertyMsgProtocol*)  tolua_tousertype(tolua_S,1,0);
  unsigned int value = ((unsigned int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'add_property_ids'", NULL);
#endif
  {
   self->add_property_ids(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'add_property_ids'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_properties_size of class  gamer::protocol::SetPropertyMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_set_property_msg_protocol_gamer_protocol_SetPropertyMsgProtocol_new_properties_size00
static int tolua_set_property_msg_protocol_gamer_protocol_SetPropertyMsgProtocol_new_properties_size00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const gamer::protocol::SetPropertyMsgProtocol",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const gamer::protocol::SetPropertyMsgProtocol* self = (const gamer::protocol::SetPropertyMsgProtocol*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'new_properties_size'", NULL);
#endif
  {
   int tolua_ret = (int)  self->new_properties_size();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new_properties_size'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_properties of class  gamer::protocol::SetPropertyMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_set_property_msg_protocol_gamer_protocol_SetPropertyMsgProtocol_new_properties00
static int tolua_set_property_msg_protocol_gamer_protocol_SetPropertyMsgProtocol_new_properties00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const gamer::protocol::SetPropertyMsgProtocol",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const gamer::protocol::SetPropertyMsgProtocol* self = (const gamer::protocol::SetPropertyMsgProtocol*)  tolua_tousertype(tolua_S,1,0);
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'new_properties'", NULL);
#endif
  {
   const std::string tolua_ret = (const std::string)  self->new_properties(index);
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new_properties'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: set_new_properties of class  gamer::protocol::SetPropertyMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_set_property_msg_protocol_gamer_protocol_SetPropertyMsgProtocol_set_new_properties00
static int tolua_set_property_msg_protocol_gamer_protocol_SetPropertyMsgProtocol_set_new_properties00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"gamer::protocol::SetPropertyMsgProtocol",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  gamer::protocol::SetPropertyMsgProtocol* self = (gamer::protocol::SetPropertyMsgProtocol*)  tolua_tousertype(tolua_S,1,0);
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
  const std::string value = ((const std::string)  tolua_tocppstring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'set_new_properties'", NULL);
#endif
  {
   self->set_new_properties(index,value);
   tolua_pushcppstring(tolua_S,(const char*)value);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'set_new_properties'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: add_new_properties of class  gamer::protocol::SetPropertyMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_set_property_msg_protocol_gamer_protocol_SetPropertyMsgProtocol_add_new_properties00
static int tolua_set_property_msg_protocol_gamer_protocol_SetPropertyMsgProtocol_add_new_properties00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"gamer::protocol::SetPropertyMsgProtocol",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  gamer::protocol::SetPropertyMsgProtocol* self = (gamer::protocol::SetPropertyMsgProtocol*)  tolua_tousertype(tolua_S,1,0);
  const std::string value = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'add_new_properties'", NULL);
#endif
  {
   self->add_new_properties(value);
   tolua_pushcppstring(tolua_S,(const char*)value);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'add_new_properties'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_set_property_msg_protocol_open (lua_State* tolua_S)
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
    tolua_cclass(tolua_S,"SetPropertyMsgProtocol","gamer::protocol::SetPropertyMsgProtocol","google::protobuf::Message",tolua_collect_gamer__protocol__SetPropertyMsgProtocol);
    #else
    tolua_cclass(tolua_S,"SetPropertyMsgProtocol","gamer::protocol::SetPropertyMsgProtocol","google::protobuf::Message",NULL);
    #endif
    tolua_beginmodule(tolua_S,"SetPropertyMsgProtocol");
     tolua_function(tolua_S,"new",tolua_set_property_msg_protocol_gamer_protocol_SetPropertyMsgProtocol_new00);
     tolua_function(tolua_S,"new_local",tolua_set_property_msg_protocol_gamer_protocol_SetPropertyMsgProtocol_new00_local);
     tolua_function(tolua_S,".call",tolua_set_property_msg_protocol_gamer_protocol_SetPropertyMsgProtocol_new00_local);
     tolua_function(tolua_S,"ByteSize",tolua_set_property_msg_protocol_gamer_protocol_SetPropertyMsgProtocol_ByteSize00);
     tolua_function(tolua_S,"set_player_id",tolua_set_property_msg_protocol_gamer_protocol_SetPropertyMsgProtocol_set_player_id00);
     tolua_function(tolua_S,"player_id",tolua_set_property_msg_protocol_gamer_protocol_SetPropertyMsgProtocol_player_id00);
     tolua_function(tolua_S,"property_ids_size",tolua_set_property_msg_protocol_gamer_protocol_SetPropertyMsgProtocol_property_ids_size00);
     tolua_function(tolua_S,"property_ids",tolua_set_property_msg_protocol_gamer_protocol_SetPropertyMsgProtocol_property_ids00);
     tolua_function(tolua_S,"set_property_ids",tolua_set_property_msg_protocol_gamer_protocol_SetPropertyMsgProtocol_set_property_ids00);
     tolua_function(tolua_S,"add_property_ids",tolua_set_property_msg_protocol_gamer_protocol_SetPropertyMsgProtocol_add_property_ids00);
     tolua_function(tolua_S,"new_properties_size",tolua_set_property_msg_protocol_gamer_protocol_SetPropertyMsgProtocol_new_properties_size00);
     tolua_function(tolua_S,"new_properties",tolua_set_property_msg_protocol_gamer_protocol_SetPropertyMsgProtocol_new_properties00);
     tolua_function(tolua_S,"set_new_properties",tolua_set_property_msg_protocol_gamer_protocol_SetPropertyMsgProtocol_set_new_properties00);
     tolua_function(tolua_S,"add_new_properties",tolua_set_property_msg_protocol_gamer_protocol_SetPropertyMsgProtocol_add_new_properties00);
    tolua_endmodule(tolua_S);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_set_property_msg_protocol (lua_State* tolua_S) {
 return tolua_set_property_msg_protocol_open(tolua_S);
};
#endif


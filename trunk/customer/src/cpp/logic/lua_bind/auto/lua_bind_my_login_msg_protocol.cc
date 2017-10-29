/*
** Lua binding: my_login_msg_protocol
** Generated automatically by tolua++-1.0.92 on 10/29/17 21:18:14.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_my_login_msg_protocol_open (lua_State* tolua_S);

#include "msg/protocol/my_login_msg_protocol.pb.h"
#include <string>
#include <google/protobuf/stubs/common.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/unknown_field_set.h>

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_gamer__protocol__MyLoginMsgProtocol (lua_State* tolua_S)
{
 gamer::protocol::MyLoginMsgProtocol* self = (gamer::protocol::MyLoginMsgProtocol*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"gamer::protocol::PlayerMsgProtocol");
 tolua_usertype(tolua_S,"gamer::protocol::MyLoginMsgProtocol");
 tolua_usertype(tolua_S,"google::protobuf::Message");
}

/* method: new of class  gamer::protocol::MyLoginMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_my_login_msg_protocol_gamer_protocol_MyLoginMsgProtocol_new00
static int tolua_my_login_msg_protocol_gamer_protocol_MyLoginMsgProtocol_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"gamer::protocol::MyLoginMsgProtocol",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   gamer::protocol::MyLoginMsgProtocol* tolua_ret = (gamer::protocol::MyLoginMsgProtocol*)  Mtolua_new((gamer::protocol::MyLoginMsgProtocol)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"gamer::protocol::MyLoginMsgProtocol");
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

/* method: new_local of class  gamer::protocol::MyLoginMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_my_login_msg_protocol_gamer_protocol_MyLoginMsgProtocol_new00_local
static int tolua_my_login_msg_protocol_gamer_protocol_MyLoginMsgProtocol_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"gamer::protocol::MyLoginMsgProtocol",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   gamer::protocol::MyLoginMsgProtocol* tolua_ret = (gamer::protocol::MyLoginMsgProtocol*)  Mtolua_new((gamer::protocol::MyLoginMsgProtocol)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"gamer::protocol::MyLoginMsgProtocol");
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

/* method: ByteSize of class  gamer::protocol::MyLoginMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_my_login_msg_protocol_gamer_protocol_MyLoginMsgProtocol_ByteSize00
static int tolua_my_login_msg_protocol_gamer_protocol_MyLoginMsgProtocol_ByteSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const gamer::protocol::MyLoginMsgProtocol",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const gamer::protocol::MyLoginMsgProtocol* self = (const gamer::protocol::MyLoginMsgProtocol*)  tolua_tousertype(tolua_S,1,0);
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

/* method: set_account of class  gamer::protocol::MyLoginMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_my_login_msg_protocol_gamer_protocol_MyLoginMsgProtocol_set_account00
static int tolua_my_login_msg_protocol_gamer_protocol_MyLoginMsgProtocol_set_account00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"gamer::protocol::MyLoginMsgProtocol",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  gamer::protocol::MyLoginMsgProtocol* self = (gamer::protocol::MyLoginMsgProtocol*)  tolua_tousertype(tolua_S,1,0);
  const char* value = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'set_account'", NULL);
#endif
  {
   self->set_account(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'set_account'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: account of class  gamer::protocol::MyLoginMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_my_login_msg_protocol_gamer_protocol_MyLoginMsgProtocol_account00
static int tolua_my_login_msg_protocol_gamer_protocol_MyLoginMsgProtocol_account00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const gamer::protocol::MyLoginMsgProtocol",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const gamer::protocol::MyLoginMsgProtocol* self = (const gamer::protocol::MyLoginMsgProtocol*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'account'", NULL);
#endif
  {
   const std::string tolua_ret = (const std::string)  self->account();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'account'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: set_password of class  gamer::protocol::MyLoginMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_my_login_msg_protocol_gamer_protocol_MyLoginMsgProtocol_set_password00
static int tolua_my_login_msg_protocol_gamer_protocol_MyLoginMsgProtocol_set_password00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"gamer::protocol::MyLoginMsgProtocol",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  gamer::protocol::MyLoginMsgProtocol* self = (gamer::protocol::MyLoginMsgProtocol*)  tolua_tousertype(tolua_S,1,0);
  const char* value = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'set_password'", NULL);
#endif
  {
   self->set_password(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'set_password'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: password of class  gamer::protocol::MyLoginMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_my_login_msg_protocol_gamer_protocol_MyLoginMsgProtocol_password00
static int tolua_my_login_msg_protocol_gamer_protocol_MyLoginMsgProtocol_password00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const gamer::protocol::MyLoginMsgProtocol",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const gamer::protocol::MyLoginMsgProtocol* self = (const gamer::protocol::MyLoginMsgProtocol*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'password'", NULL);
#endif
  {
   const std::string tolua_ret = (const std::string)  self->password();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'password'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: player of class  gamer::protocol::MyLoginMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_my_login_msg_protocol_gamer_protocol_MyLoginMsgProtocol_player00
static int tolua_my_login_msg_protocol_gamer_protocol_MyLoginMsgProtocol_player00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const gamer::protocol::MyLoginMsgProtocol",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const gamer::protocol::MyLoginMsgProtocol* self = (const gamer::protocol::MyLoginMsgProtocol*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'player'", NULL);
#endif
  {
   const gamer::protocol::PlayerMsgProtocol& tolua_ret = (const gamer::protocol::PlayerMsgProtocol&)  self->player();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const gamer::protocol::PlayerMsgProtocol");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'player'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_my_login_msg_protocol_open (lua_State* tolua_S)
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
    tolua_cclass(tolua_S,"MyLoginMsgProtocol","gamer::protocol::MyLoginMsgProtocol","google::protobuf::Message",tolua_collect_gamer__protocol__MyLoginMsgProtocol);
    #else
    tolua_cclass(tolua_S,"MyLoginMsgProtocol","gamer::protocol::MyLoginMsgProtocol","google::protobuf::Message",NULL);
    #endif
    tolua_beginmodule(tolua_S,"MyLoginMsgProtocol");
     tolua_function(tolua_S,"new",tolua_my_login_msg_protocol_gamer_protocol_MyLoginMsgProtocol_new00);
     tolua_function(tolua_S,"new_local",tolua_my_login_msg_protocol_gamer_protocol_MyLoginMsgProtocol_new00_local);
     tolua_function(tolua_S,".call",tolua_my_login_msg_protocol_gamer_protocol_MyLoginMsgProtocol_new00_local);
     tolua_function(tolua_S,"ByteSize",tolua_my_login_msg_protocol_gamer_protocol_MyLoginMsgProtocol_ByteSize00);
     tolua_function(tolua_S,"set_account",tolua_my_login_msg_protocol_gamer_protocol_MyLoginMsgProtocol_set_account00);
     tolua_function(tolua_S,"account",tolua_my_login_msg_protocol_gamer_protocol_MyLoginMsgProtocol_account00);
     tolua_function(tolua_S,"set_password",tolua_my_login_msg_protocol_gamer_protocol_MyLoginMsgProtocol_set_password00);
     tolua_function(tolua_S,"password",tolua_my_login_msg_protocol_gamer_protocol_MyLoginMsgProtocol_password00);
     tolua_function(tolua_S,"player",tolua_my_login_msg_protocol_gamer_protocol_MyLoginMsgProtocol_player00);
    tolua_endmodule(tolua_S);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_my_login_msg_protocol (lua_State* tolua_S) {
 return tolua_my_login_msg_protocol_open(tolua_S);
};
#endif


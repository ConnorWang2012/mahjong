/*
** Lua binding: network_manager
** Generated automatically by tolua++-1.0.92 on 05/22/17 23:01:24.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_network_manager_open (lua_State* tolua_S);

#include "network_manager.h"
#include <functional>
#include <string>
#include <thread>
//#include <bufferevent.h>
//#include <event.h>
#include "msg.h"

/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"gamer::NetworkManager");
 tolua_usertype(tolua_S,"size_t");
}

/* method: getInstance of class  gamer::NetworkManager */
#ifndef TOLUA_DISABLE_tolua_network_manager_gamer_NetworkManager_getInstance00
static int tolua_network_manager_gamer_NetworkManager_getInstance00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"gamer::NetworkManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   gamer::NetworkManager* tolua_ret = (gamer::NetworkManager*)  gamer::NetworkManager::getInstance();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"gamer::NetworkManager");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getInstance'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: connect of class  gamer::NetworkManager */
#ifndef TOLUA_DISABLE_tolua_network_manager_gamer_NetworkManager_connect00
static int tolua_network_manager_gamer_NetworkManager_connect00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"gamer::NetworkManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  gamer::NetworkManager* self = (gamer::NetworkManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'connect'", NULL);
#endif
  {
   self->connect();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'connect'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: disconnect of class  gamer::NetworkManager */
#ifndef TOLUA_DISABLE_tolua_network_manager_gamer_NetworkManager_disconnect00
static int tolua_network_manager_gamer_NetworkManager_disconnect00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"gamer::NetworkManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  gamer::NetworkManager* self = (gamer::NetworkManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'disconnect'", NULL);
#endif
  {
   self->disconnect();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'disconnect'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: send of class  gamer::NetworkManager */
#ifndef TOLUA_DISABLE_tolua_network_manager_gamer_NetworkManager_send00
static int tolua_network_manager_gamer_NetworkManager_send00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"gamer::NetworkManager",0,&tolua_err) ||
     !tolua_isuserdata(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"size_t",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  gamer::NetworkManager* self = (gamer::NetworkManager*)  tolua_tousertype(tolua_S,1,0);
  void* ctx = ((void*)  tolua_touserdata(tolua_S,2,0));
  size_t ctxlen = *((size_t*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'send'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->send(ctx,ctxlen);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'send'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: set_ip of class  gamer::NetworkManager */
#ifndef TOLUA_DISABLE_tolua_network_manager_gamer_NetworkManager_set_ip00
static int tolua_network_manager_gamer_NetworkManager_set_ip00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"gamer::NetworkManager",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  gamer::NetworkManager* self = (gamer::NetworkManager*)  tolua_tousertype(tolua_S,1,0);
  const std::string ip = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'set_ip'", NULL);
#endif
  {
   self->set_ip(ip);
   tolua_pushcppstring(tolua_S,(const char*)ip);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'set_ip'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ip of class  gamer::NetworkManager */
#ifndef TOLUA_DISABLE_tolua_network_manager_gamer_NetworkManager_ip00
static int tolua_network_manager_gamer_NetworkManager_ip00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const gamer::NetworkManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const gamer::NetworkManager* self = (const gamer::NetworkManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ip'", NULL);
#endif
  {
   const std::string tolua_ret = (const std::string)  self->ip();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ip'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: set_port of class  gamer::NetworkManager */
#ifndef TOLUA_DISABLE_tolua_network_manager_gamer_NetworkManager_set_port00
static int tolua_network_manager_gamer_NetworkManager_set_port00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"gamer::NetworkManager",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  gamer::NetworkManager* self = (gamer::NetworkManager*)  tolua_tousertype(tolua_S,1,0);
  int port = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'set_port'", NULL);
#endif
  {
   self->set_port(port);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'set_port'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: port of class  gamer::NetworkManager */
#ifndef TOLUA_DISABLE_tolua_network_manager_gamer_NetworkManager_port00
static int tolua_network_manager_gamer_NetworkManager_port00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const gamer::NetworkManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const gamer::NetworkManager* self = (const gamer::NetworkManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'port'", NULL);
#endif
  {
   int tolua_ret = (int)  self->port();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'port'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: is_connected of class  gamer::NetworkManager */
#ifndef TOLUA_DISABLE_tolua_network_manager_gamer_NetworkManager_is_connected00
static int tolua_network_manager_gamer_NetworkManager_is_connected00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const gamer::NetworkManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const gamer::NetworkManager* self = (const gamer::NetworkManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'is_connected'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->is_connected();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'is_connected'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_network_manager_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  tolua_module(tolua_S,"gamer",0);
  tolua_beginmodule(tolua_S,"gamer");
   tolua_cclass(tolua_S,"NetworkManager","gamer::NetworkManager","",NULL);
   tolua_beginmodule(tolua_S,"NetworkManager");
    tolua_function(tolua_S,"getInstance",tolua_network_manager_gamer_NetworkManager_getInstance00);
    tolua_function(tolua_S,"connect",tolua_network_manager_gamer_NetworkManager_connect00);
    tolua_function(tolua_S,"disconnect",tolua_network_manager_gamer_NetworkManager_disconnect00);
    tolua_function(tolua_S,"send",tolua_network_manager_gamer_NetworkManager_send00);
    tolua_function(tolua_S,"set_ip",tolua_network_manager_gamer_NetworkManager_set_ip00);
    tolua_function(tolua_S,"ip",tolua_network_manager_gamer_NetworkManager_ip00);
    tolua_function(tolua_S,"set_port",tolua_network_manager_gamer_NetworkManager_set_port00);
    tolua_function(tolua_S,"port",tolua_network_manager_gamer_NetworkManager_port00);
    tolua_function(tolua_S,"is_connected",tolua_network_manager_gamer_NetworkManager_is_connected00);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_network_manager (lua_State* tolua_S) {
 return tolua_network_manager_open(tolua_S);
};
#endif


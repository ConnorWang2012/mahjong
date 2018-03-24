/*
** Lua binding: command_listener
** Generated automatically by tolua++-1.0.92 on 11/17/17 11:39:31.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_command_listener_open (lua_State* tolua_S);

#include "command_listener.h"
#include <functional>
#include <string>
#include "base/macros.h"
#include "event_listener.h"

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_id_t (lua_State* tolua_S)
{
 id_t* self = (id_t*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_gamer__Listener__LuaFunction (lua_State* tolua_S)
{
 gamer::Listener::LuaFunction* self = (gamer::Listener::LuaFunction*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_gamer__CommandListener (lua_State* tolua_S)
{
 gamer::CommandListener* self = (gamer::CommandListener*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"id_t");
 tolua_usertype(tolua_S,"gamer::CommandListener");
 tolua_usertype(tolua_S,"gamer::Listener::LuaFunction");
}

/* method: delete of class  gamer::CommandListener */
#ifndef TOLUA_DISABLE_tolua_command_listener_gamer_CommandListener_delete00
static int tolua_command_listener_gamer_CommandListener_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"gamer::CommandListener",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  gamer::CommandListener* self = (gamer::CommandListener*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  gamer::CommandListener */
#ifndef TOLUA_DISABLE_tolua_command_listener_gamer_CommandListener_create00
static int tolua_command_listener_gamer_CommandListener_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"gamer::CommandListener",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"id_t",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"gamer::Listener::LuaFunction",0,&tolua_err)) ||
     !tolua_iscppstring(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  id_t cmd_id = *((id_t*)  tolua_tousertype(tolua_S,2,0));
  gamer::Listener::LuaFunction command_callback = *((gamer::Listener::LuaFunction*)  tolua_tousertype(tolua_S,3,0));
  const std::string listener_name = ((const std::string)  tolua_tocppstring(tolua_S,4,0));
  int priority = ((int)  tolua_tonumber(tolua_S,5,0));
  {
   gamer::CommandListener* tolua_ret = (gamer::CommandListener*)  gamer::CommandListener::create(cmd_id,command_callback,listener_name,priority);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"gamer::CommandListener");
   tolua_pushcppstring(tolua_S,(const char*)listener_name);
  }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'create'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: command_id of class  gamer::CommandListener */
#ifndef TOLUA_DISABLE_tolua_command_listener_gamer_CommandListener_command_id00
static int tolua_command_listener_gamer_CommandListener_command_id00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const gamer::CommandListener",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const gamer::CommandListener* self = (const gamer::CommandListener*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'command_id'", NULL);
#endif
  {
   id_t tolua_ret = (id_t)  self->command_id();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((id_t)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"id_t");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(id_t));
     tolua_pushusertype(tolua_S,tolua_obj,"id_t");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'command_id'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: listener_name of class  gamer::CommandListener */
#ifndef TOLUA_DISABLE_tolua_command_listener_gamer_CommandListener_listener_name00
static int tolua_command_listener_gamer_CommandListener_listener_name00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const gamer::CommandListener",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const gamer::CommandListener* self = (const gamer::CommandListener*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'listener_name'", NULL);
#endif
  {
   const std::string tolua_ret = (const std::string)  self->listener_name();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'listener_name'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: priority of class  gamer::CommandListener */
#ifndef TOLUA_DISABLE_tolua_command_listener_gamer_CommandListener_priority00
static int tolua_command_listener_gamer_CommandListener_priority00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const gamer::CommandListener",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const gamer::CommandListener* self = (const gamer::CommandListener*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'priority'", NULL);
#endif
  {
   int tolua_ret = (int)  self->priority();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'priority'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: is_lua_function of class  gamer::CommandListener */
#ifndef TOLUA_DISABLE_tolua_command_listener_gamer_CommandListener_is_lua_function00
static int tolua_command_listener_gamer_CommandListener_is_lua_function00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const gamer::CommandListener",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const gamer::CommandListener* self = (const gamer::CommandListener*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'is_lua_function'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->is_lua_function();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'is_lua_function'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: lua_function of class  gamer::CommandListener */
#ifndef TOLUA_DISABLE_tolua_command_listener_gamer_CommandListener_lua_function00
static int tolua_command_listener_gamer_CommandListener_lua_function00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const gamer::CommandListener",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const gamer::CommandListener* self = (const gamer::CommandListener*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'lua_function'", NULL);
#endif
  {
   gamer::Listener::LuaFunction tolua_ret = (gamer::Listener::LuaFunction)  self->lua_function();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((gamer::Listener::LuaFunction)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"gamer::Listener::LuaFunction");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(gamer::Listener::LuaFunction));
     tolua_pushusertype(tolua_S,tolua_obj,"gamer::Listener::LuaFunction");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'lua_function'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: set_lua_function_id of class  gamer::CommandListener */
#ifndef TOLUA_DISABLE_tolua_command_listener_gamer_CommandListener_set_lua_function_id00
static int tolua_command_listener_gamer_CommandListener_set_lua_function_id00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"gamer::CommandListener",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  gamer::CommandListener* self = (gamer::CommandListener*)  tolua_tousertype(tolua_S,1,0);
  const std::string function_id = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'set_lua_function_id'", NULL);
#endif
  {
   self->set_lua_function_id(function_id);
   tolua_pushcppstring(tolua_S,(const char*)function_id);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'set_lua_function_id'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: lua_function_id of class  gamer::CommandListener */
#ifndef TOLUA_DISABLE_tolua_command_listener_gamer_CommandListener_lua_function_id00
static int tolua_command_listener_gamer_CommandListener_lua_function_id00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const gamer::CommandListener",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const gamer::CommandListener* self = (const gamer::CommandListener*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'lua_function_id'", NULL);
#endif
  {
   const std::string tolua_ret = (const std::string)  self->lua_function_id();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'lua_function_id'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: set_enabled of class  gamer::CommandListener */
#ifndef TOLUA_DISABLE_tolua_command_listener_gamer_CommandListener_set_enabled00
static int tolua_command_listener_gamer_CommandListener_set_enabled00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"gamer::CommandListener",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  gamer::CommandListener* self = (gamer::CommandListener*)  tolua_tousertype(tolua_S,1,0);
  bool enabled = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'set_enabled'", NULL);
#endif
  {
   self->set_enabled(enabled);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'set_enabled'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: is_enabled of class  gamer::CommandListener */
#ifndef TOLUA_DISABLE_tolua_command_listener_gamer_CommandListener_is_enabled00
static int tolua_command_listener_gamer_CommandListener_is_enabled00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const gamer::CommandListener",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const gamer::CommandListener* self = (const gamer::CommandListener*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'is_enabled'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->is_enabled();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'is_enabled'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: checkValidity of class  gamer::CommandListener */
#ifndef TOLUA_DISABLE_tolua_command_listener_gamer_CommandListener_checkValidity00
static int tolua_command_listener_gamer_CommandListener_checkValidity00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const gamer::CommandListener",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const gamer::CommandListener* self = (const gamer::CommandListener*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'checkValidity'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->checkValidity();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'checkValidity'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: is_registered of class  gamer::CommandListener */
#ifndef TOLUA_DISABLE_tolua_command_listener_gamer_CommandListener_is_registered00
static int tolua_command_listener_gamer_CommandListener_is_registered00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const gamer::CommandListener",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const gamer::CommandListener* self = (const gamer::CommandListener*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'is_registered'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->is_registered();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'is_registered'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_command_listener_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  tolua_module(tolua_S,"gamer",0);
  tolua_beginmodule(tolua_S,"gamer");
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"CommandListener","gamer::CommandListener","",tolua_collect_gamer__CommandListener);
   #else
   tolua_cclass(tolua_S,"CommandListener","gamer::CommandListener","",NULL);
   #endif
   tolua_beginmodule(tolua_S,"CommandListener");
    tolua_function(tolua_S,"delete",tolua_command_listener_gamer_CommandListener_delete00);
    tolua_function(tolua_S,"create",tolua_command_listener_gamer_CommandListener_create00);
    tolua_function(tolua_S,"command_id",tolua_command_listener_gamer_CommandListener_command_id00);
    tolua_function(tolua_S,"listener_name",tolua_command_listener_gamer_CommandListener_listener_name00);
    tolua_function(tolua_S,"priority",tolua_command_listener_gamer_CommandListener_priority00);
    tolua_function(tolua_S,"is_lua_function",tolua_command_listener_gamer_CommandListener_is_lua_function00);
    tolua_function(tolua_S,"lua_function",tolua_command_listener_gamer_CommandListener_lua_function00);
    tolua_function(tolua_S,"set_lua_function_id",tolua_command_listener_gamer_CommandListener_set_lua_function_id00);
    tolua_function(tolua_S,"lua_function_id",tolua_command_listener_gamer_CommandListener_lua_function_id00);
    tolua_function(tolua_S,"set_enabled",tolua_command_listener_gamer_CommandListener_set_enabled00);
    tolua_function(tolua_S,"is_enabled",tolua_command_listener_gamer_CommandListener_is_enabled00);
    tolua_function(tolua_S,"checkValidity",tolua_command_listener_gamer_CommandListener_checkValidity00);
    tolua_function(tolua_S,"is_registered",tolua_command_listener_gamer_CommandListener_is_registered00);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_command_listener (lua_State* tolua_S) {
 return tolua_command_listener_open(tolua_S);
};
#endif


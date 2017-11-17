/*
** Lua binding: event_listener
** Generated automatically by tolua++-1.0.92 on 11/17/17 11:39:41.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_event_listener_open (lua_State* tolua_S);

#include "event_listener.h"
#include <functional>
#include <string>
#include "base/macros.h"
#include "listener.h"

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_gamer__Listener (lua_State* tolua_S)
{
 gamer::Listener* self = (gamer::Listener*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_gamer__EventListener (lua_State* tolua_S)
{
 gamer::EventListener* self = (gamer::EventListener*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"std::function<void(const gamer::Event&)>");
 tolua_usertype(tolua_S,"id_t");
 tolua_usertype(tolua_S,"gamer::Event");
 tolua_usertype(tolua_S,"gamer::Listener");
 tolua_usertype(tolua_S,"gamer::EventListener");
}

/* method: delete of class  gamer::Listener */
#ifndef TOLUA_DISABLE_tolua_event_listener_gamer_Listener_delete00
static int tolua_event_listener_gamer_Listener_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"gamer::Listener",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  gamer::Listener* self = (gamer::Listener*)  tolua_tousertype(tolua_S,1,0);
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

/* method: checkValidity of class  gamer::Listener */
#ifndef TOLUA_DISABLE_tolua_event_listener_gamer_Listener_checkValidity00
static int tolua_event_listener_gamer_Listener_checkValidity00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const gamer::Listener",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const gamer::Listener* self = (const gamer::Listener*)  tolua_tousertype(tolua_S,1,0);
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

/* method: set_listener_name of class  gamer::Listener */
#ifndef TOLUA_DISABLE_tolua_event_listener_gamer_Listener_set_listener_name00
static int tolua_event_listener_gamer_Listener_set_listener_name00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"gamer::Listener",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  gamer::Listener* self = (gamer::Listener*)  tolua_tousertype(tolua_S,1,0);
  const std::string listener_name = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'set_listener_name'", NULL);
#endif
  {
   self->set_listener_name(listener_name);
   tolua_pushcppstring(tolua_S,(const char*)listener_name);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'set_listener_name'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: listener_name of class  gamer::Listener */
#ifndef TOLUA_DISABLE_tolua_event_listener_gamer_Listener_listener_name00
static int tolua_event_listener_gamer_Listener_listener_name00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const gamer::Listener",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const gamer::Listener* self = (const gamer::Listener*)  tolua_tousertype(tolua_S,1,0);
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

/* method: set_priority of class  gamer::Listener */
#ifndef TOLUA_DISABLE_tolua_event_listener_gamer_Listener_set_priority00
static int tolua_event_listener_gamer_Listener_set_priority00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"gamer::Listener",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  gamer::Listener* self = (gamer::Listener*)  tolua_tousertype(tolua_S,1,0);
  int priority = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'set_priority'", NULL);
#endif
  {
   self->set_priority(priority);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'set_priority'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: priority of class  gamer::Listener */
#ifndef TOLUA_DISABLE_tolua_event_listener_gamer_Listener_priority00
static int tolua_event_listener_gamer_Listener_priority00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const gamer::Listener",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const gamer::Listener* self = (const gamer::Listener*)  tolua_tousertype(tolua_S,1,0);
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

/* method: is_lua_function of class  gamer::Listener */
#ifndef TOLUA_DISABLE_tolua_event_listener_gamer_Listener_is_lua_function00
static int tolua_event_listener_gamer_Listener_is_lua_function00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const gamer::Listener",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const gamer::Listener* self = (const gamer::Listener*)  tolua_tousertype(tolua_S,1,0);
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

/* method: set_lua_function of class  gamer::Listener */
#ifndef TOLUA_DISABLE_tolua_event_listener_gamer_Listener_set_lua_function00
static int tolua_event_listener_gamer_Listener_set_lua_function00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"gamer::Listener",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  gamer::Listener* self = (gamer::Listener*)  tolua_tousertype(tolua_S,1,0);
  int lua_function = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'set_lua_function'", NULL);
#endif
  {
   self->set_lua_function(lua_function);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'set_lua_function'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: lua_function of class  gamer::Listener */
#ifndef TOLUA_DISABLE_tolua_event_listener_gamer_Listener_lua_function00
static int tolua_event_listener_gamer_Listener_lua_function00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const gamer::Listener",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const gamer::Listener* self = (const gamer::Listener*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'lua_function'", NULL);
#endif
  {
    int tolua_ret = (  int)  self->lua_function();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
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

/* method: set_lua_function_id of class  gamer::Listener */
#ifndef TOLUA_DISABLE_tolua_event_listener_gamer_Listener_set_lua_function_id00
static int tolua_event_listener_gamer_Listener_set_lua_function_id00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"gamer::Listener",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  gamer::Listener* self = (gamer::Listener*)  tolua_tousertype(tolua_S,1,0);
  const std::string func_id = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'set_lua_function_id'", NULL);
#endif
  {
   self->set_lua_function_id(func_id);
   tolua_pushcppstring(tolua_S,(const char*)func_id);
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

/* method: lua_function_id of class  gamer::Listener */
#ifndef TOLUA_DISABLE_tolua_event_listener_gamer_Listener_lua_function_id00
static int tolua_event_listener_gamer_Listener_lua_function_id00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const gamer::Listener",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const gamer::Listener* self = (const gamer::Listener*)  tolua_tousertype(tolua_S,1,0);
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

/* method: set_enabled of class  gamer::Listener */
#ifndef TOLUA_DISABLE_tolua_event_listener_gamer_Listener_set_enabled00
static int tolua_event_listener_gamer_Listener_set_enabled00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"gamer::Listener",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  gamer::Listener* self = (gamer::Listener*)  tolua_tousertype(tolua_S,1,0);
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

/* method: is_enabled of class  gamer::Listener */
#ifndef TOLUA_DISABLE_tolua_event_listener_gamer_Listener_is_enabled00
static int tolua_event_listener_gamer_Listener_is_enabled00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const gamer::Listener",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const gamer::Listener* self = (const gamer::Listener*)  tolua_tousertype(tolua_S,1,0);
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

/* method: is_registered of class  gamer::Listener */
#ifndef TOLUA_DISABLE_tolua_event_listener_gamer_Listener_is_registered00
static int tolua_event_listener_gamer_Listener_is_registered00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const gamer::Listener",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const gamer::Listener* self = (const gamer::Listener*)  tolua_tousertype(tolua_S,1,0);
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

/* method: delete of class  gamer::EventListener */
#ifndef TOLUA_DISABLE_tolua_event_listener_gamer_EventListener_delete00
static int tolua_event_listener_gamer_EventListener_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"gamer::EventListener",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  gamer::EventListener* self = (gamer::EventListener*)  tolua_tousertype(tolua_S,1,0);
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

/* method: create of class  gamer::EventListener */
#ifndef TOLUA_DISABLE_tolua_event_listener_gamer_EventListener_create00
static int tolua_event_listener_gamer_EventListener_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"gamer::EventListener",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"id_t",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  id_t event_id = *((id_t*)  tolua_tousertype(tolua_S,2,0));
   int event_callback = ((  int)  tolua_tonumber(tolua_S,3,0));
  const std::string listener_name = ((const std::string)  tolua_tocppstring(tolua_S,4,0));
  int priority = ((int)  tolua_tonumber(tolua_S,5,0));
  {
   gamer::EventListener* tolua_ret = (gamer::EventListener*)  gamer::EventListener::create(event_id,event_callback,listener_name,priority);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"gamer::EventListener");
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

/* method: executeCallback of class  gamer::EventListener */
#ifndef TOLUA_DISABLE_tolua_event_listener_gamer_EventListener_executeCallback00
static int tolua_event_listener_gamer_EventListener_executeCallback00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"gamer::EventListener",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const gamer::Event",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  gamer::EventListener* self = (gamer::EventListener*)  tolua_tousertype(tolua_S,1,0);
  const gamer::Event* event = ((const gamer::Event*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'executeCallback'", NULL);
#endif
  {
   self->executeCallback(*event);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'executeCallback'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: checkValidity of class  gamer::EventListener */
#ifndef TOLUA_DISABLE_tolua_event_listener_gamer_EventListener_checkValidity00
static int tolua_event_listener_gamer_EventListener_checkValidity00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const gamer::EventListener",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const gamer::EventListener* self = (const gamer::EventListener*)  tolua_tousertype(tolua_S,1,0);
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

/* method: event_id of class  gamer::EventListener */
#ifndef TOLUA_DISABLE_tolua_event_listener_gamer_EventListener_event_id00
static int tolua_event_listener_gamer_EventListener_event_id00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const gamer::EventListener",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const gamer::EventListener* self = (const gamer::EventListener*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'event_id'", NULL);
#endif
  {
   int tolua_ret = (int)  self->event_id();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'event_id'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: set_event_callback of class  gamer::EventListener */
#ifndef TOLUA_DISABLE_tolua_event_listener_gamer_EventListener_set_event_callback00
static int tolua_event_listener_gamer_EventListener_set_event_callback00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"gamer::EventListener",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const std::function<void(const gamer::Event&)>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  gamer::EventListener* self = (gamer::EventListener*)  tolua_tousertype(tolua_S,1,0);
  const std::function<void(const gamer::Event&)>* event_callback = ((const std::function<void(const gamer::Event&)>*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'set_event_callback'", NULL);
#endif
  {
   self->set_event_callback(*event_callback);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'set_event_callback'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: event_callback of class  gamer::EventListener */
#ifndef TOLUA_DISABLE_tolua_event_listener_gamer_EventListener_event_callback00
static int tolua_event_listener_gamer_EventListener_event_callback00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"gamer::EventListener",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  gamer::EventListener* self = (gamer::EventListener*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'event_callback'", NULL);
#endif
  {
    const std::function<void(const gamer::Event&)>& tolua_ret = (  const std::function<void(const gamer::Event&)>&)  self->event_callback();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const std::function<void(const gamer::Event&)>");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'event_callback'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: is_registered of class  gamer::EventListener */
#ifndef TOLUA_DISABLE_tolua_event_listener_gamer_EventListener_is_registered00
static int tolua_event_listener_gamer_EventListener_is_registered00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const gamer::EventListener",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const gamer::EventListener* self = (const gamer::EventListener*)  tolua_tousertype(tolua_S,1,0);
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
TOLUA_API int tolua_event_listener_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  tolua_module(tolua_S,"gamer",0);
  tolua_beginmodule(tolua_S,"gamer");
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"Listener","gamer::Listener","",tolua_collect_gamer__Listener);
   #else
   tolua_cclass(tolua_S,"Listener","gamer::Listener","",NULL);
   #endif
   tolua_beginmodule(tolua_S,"Listener");
    tolua_function(tolua_S,"delete",tolua_event_listener_gamer_Listener_delete00);
    tolua_function(tolua_S,"checkValidity",tolua_event_listener_gamer_Listener_checkValidity00);
    tolua_function(tolua_S,"set_listener_name",tolua_event_listener_gamer_Listener_set_listener_name00);
    tolua_function(tolua_S,"listener_name",tolua_event_listener_gamer_Listener_listener_name00);
    tolua_function(tolua_S,"set_priority",tolua_event_listener_gamer_Listener_set_priority00);
    tolua_function(tolua_S,"priority",tolua_event_listener_gamer_Listener_priority00);
    tolua_function(tolua_S,"is_lua_function",tolua_event_listener_gamer_Listener_is_lua_function00);
    tolua_function(tolua_S,"set_lua_function",tolua_event_listener_gamer_Listener_set_lua_function00);
    tolua_function(tolua_S,"lua_function",tolua_event_listener_gamer_Listener_lua_function00);
    tolua_function(tolua_S,"set_lua_function_id",tolua_event_listener_gamer_Listener_set_lua_function_id00);
    tolua_function(tolua_S,"lua_function_id",tolua_event_listener_gamer_Listener_lua_function_id00);
    tolua_function(tolua_S,"set_enabled",tolua_event_listener_gamer_Listener_set_enabled00);
    tolua_function(tolua_S,"is_enabled",tolua_event_listener_gamer_Listener_is_enabled00);
    tolua_function(tolua_S,"is_registered",tolua_event_listener_gamer_Listener_is_registered00);
   tolua_endmodule(tolua_S);
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"EventListener","gamer::EventListener","gamer::Listener",tolua_collect_gamer__EventListener);
   #else
   tolua_cclass(tolua_S,"EventListener","gamer::EventListener","gamer::Listener",NULL);
   #endif
   tolua_beginmodule(tolua_S,"EventListener");
    tolua_function(tolua_S,"delete",tolua_event_listener_gamer_EventListener_delete00);
    tolua_function(tolua_S,"create",tolua_event_listener_gamer_EventListener_create00);
    tolua_function(tolua_S,"executeCallback",tolua_event_listener_gamer_EventListener_executeCallback00);
    tolua_function(tolua_S,"checkValidity",tolua_event_listener_gamer_EventListener_checkValidity00);
    tolua_function(tolua_S,"event_id",tolua_event_listener_gamer_EventListener_event_id00);
    tolua_function(tolua_S,"set_event_callback",tolua_event_listener_gamer_EventListener_set_event_callback00);
    tolua_function(tolua_S,"event_callback",tolua_event_listener_gamer_EventListener_event_callback00);
    tolua_function(tolua_S,"is_registered",tolua_event_listener_gamer_EventListener_is_registered00);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_event_listener (lua_State* tolua_S) {
 return tolua_event_listener_open(tolua_S);
};
#endif


/*
** Lua binding: event_manager
** Generated automatically by tolua++-1.0.92 on 11/17/17 11:39:44.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_event_manager_open (lua_State* tolua_S);

#include "event_manager.h"
#include "base/macros.h"
#include <map>
#include <vector>

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_gamer__EventManager (lua_State* tolua_S)
{
 gamer::EventManager* self = (gamer::EventManager*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"id_t");
 tolua_usertype(tolua_S,"gamer::Event");
 tolua_usertype(tolua_S,"gamer::EventListener");
 tolua_usertype(tolua_S,"gamer::EventManager");
}

/* method: delete of class  gamer::EventManager */
#ifndef TOLUA_DISABLE_tolua_event_manager_gamer_EventManager_delete00
static int tolua_event_manager_gamer_EventManager_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"gamer::EventManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  gamer::EventManager* self = (gamer::EventManager*)  tolua_tousertype(tolua_S,1,0);
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

/* method: getInstance of class  gamer::EventManager */
#ifndef TOLUA_DISABLE_tolua_event_manager_gamer_EventManager_getInstance00
static int tolua_event_manager_gamer_EventManager_getInstance00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"gamer::EventManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   gamer::EventManager* tolua_ret = (gamer::EventManager*)  gamer::EventManager::getInstance();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"gamer::EventManager");
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

/* method: destoryInstance of class  gamer::EventManager */
#ifndef TOLUA_DISABLE_tolua_event_manager_gamer_EventManager_destoryInstance00
static int tolua_event_manager_gamer_EventManager_destoryInstance00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"gamer::EventManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   gamer::EventManager::destoryInstance();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'destoryInstance'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: addEventListener of class  gamer::EventManager */
#ifndef TOLUA_DISABLE_tolua_event_manager_gamer_EventManager_addEventListener00
static int tolua_event_manager_gamer_EventManager_addEventListener00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"gamer::EventManager",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"gamer::EventListener",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  gamer::EventManager* self = (gamer::EventManager*)  tolua_tousertype(tolua_S,1,0);
  gamer::EventListener* listener = ((gamer::EventListener*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addEventListener'", NULL);
#endif
  {
   self->addEventListener(listener);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addEventListener'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: removeEventListener of class  gamer::EventManager */
#ifndef TOLUA_DISABLE_tolua_event_manager_gamer_EventManager_removeEventListener00
static int tolua_event_manager_gamer_EventManager_removeEventListener00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"gamer::EventManager",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"gamer::EventListener",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  gamer::EventManager* self = (gamer::EventManager*)  tolua_tousertype(tolua_S,1,0);
  gamer::EventListener* listener = ((gamer::EventListener*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'removeEventListener'", NULL);
#endif
  {
   self->removeEventListener(listener);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'removeEventListener'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: removeEventListenerWithCleanup of class  gamer::EventManager */
#ifndef TOLUA_DISABLE_tolua_event_manager_gamer_EventManager_removeEventListenerWithCleanup00
static int tolua_event_manager_gamer_EventManager_removeEventListenerWithCleanup00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"gamer::EventManager",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"gamer::EventListener",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  gamer::EventManager* self = (gamer::EventManager*)  tolua_tousertype(tolua_S,1,0);
  gamer::EventListener* listener = ((gamer::EventListener*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'removeEventListenerWithCleanup'", NULL);
#endif
  {
   self->removeEventListenerWithCleanup(listener);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'removeEventListenerWithCleanup'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: removeEventListener of class  gamer::EventManager */
#ifndef TOLUA_DISABLE_tolua_event_manager_gamer_EventManager_removeEventListener01
static int tolua_event_manager_gamer_EventManager_removeEventListener01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"gamer::EventManager",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  gamer::EventManager* self = (gamer::EventManager*)  tolua_tousertype(tolua_S,1,0);
  const std::string listener_name = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'removeEventListener'", NULL);
#endif
  {
   self->removeEventListener(listener_name);
   tolua_pushcppstring(tolua_S,(const char*)listener_name);
  }
 }
 return 1;
tolua_lerror:
 return tolua_event_manager_gamer_EventManager_removeEventListener00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: removeEventListenerWithCleanup of class  gamer::EventManager */
#ifndef TOLUA_DISABLE_tolua_event_manager_gamer_EventManager_removeEventListenerWithCleanup01
static int tolua_event_manager_gamer_EventManager_removeEventListenerWithCleanup01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"gamer::EventManager",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  gamer::EventManager* self = (gamer::EventManager*)  tolua_tousertype(tolua_S,1,0);
  const std::string listener_name = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'removeEventListenerWithCleanup'", NULL);
#endif
  {
   self->removeEventListenerWithCleanup(listener_name);
   tolua_pushcppstring(tolua_S,(const char*)listener_name);
  }
 }
 return 1;
tolua_lerror:
 return tolua_event_manager_gamer_EventManager_removeEventListenerWithCleanup00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: removeAllEventListeners of class  gamer::EventManager */
#ifndef TOLUA_DISABLE_tolua_event_manager_gamer_EventManager_removeAllEventListeners00
static int tolua_event_manager_gamer_EventManager_removeAllEventListeners00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"gamer::EventManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  gamer::EventManager* self = (gamer::EventManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'removeAllEventListeners'", NULL);
#endif
  {
   self->removeAllEventListeners();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'removeAllEventListeners'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: removeAllEventListenersWithCleanup of class  gamer::EventManager */
#ifndef TOLUA_DISABLE_tolua_event_manager_gamer_EventManager_removeAllEventListenersWithCleanup00
static int tolua_event_manager_gamer_EventManager_removeAllEventListenersWithCleanup00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"gamer::EventManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  gamer::EventManager* self = (gamer::EventManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'removeAllEventListenersWithCleanup'", NULL);
#endif
  {
   self->removeAllEventListenersWithCleanup();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'removeAllEventListenersWithCleanup'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: dispatch of class  gamer::EventManager */
#ifndef TOLUA_DISABLE_tolua_event_manager_gamer_EventManager_dispatch00
static int tolua_event_manager_gamer_EventManager_dispatch00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"gamer::EventManager",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const gamer::Event",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  gamer::EventManager* self = (gamer::EventManager*)  tolua_tousertype(tolua_S,1,0);
  const gamer::Event* event = ((const gamer::Event*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'dispatch'", NULL);
#endif
  {
   self->dispatch(*event);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'dispatch'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: dispatch of class  gamer::EventManager */
#ifndef TOLUA_DISABLE_tolua_event_manager_gamer_EventManager_dispatch01
static int tolua_event_manager_gamer_EventManager_dispatch01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"gamer::EventManager",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"id_t",0,&tolua_err)) ||
     !tolua_isuserdata(tolua_S,3,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  gamer::EventManager* self = (gamer::EventManager*)  tolua_tousertype(tolua_S,1,0);
  id_t event_id = *((id_t*)  tolua_tousertype(tolua_S,2,0));
  void* optional_user_data = ((void*)  tolua_touserdata(tolua_S,3,nullptr));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'dispatch'", NULL);
#endif
  {
   self->dispatch(event_id,optional_user_data);
  }
 }
 return 0;
tolua_lerror:
 return tolua_event_manager_gamer_EventManager_dispatch00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: setPriority of class  gamer::EventManager */
#ifndef TOLUA_DISABLE_tolua_event_manager_gamer_EventManager_setPriority00
static int tolua_event_manager_gamer_EventManager_setPriority00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"gamer::EventManager",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"gamer::EventListener",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  gamer::EventManager* self = (gamer::EventManager*)  tolua_tousertype(tolua_S,1,0);
  gamer::EventListener* listener = ((gamer::EventListener*)  tolua_tousertype(tolua_S,2,0));
  int priority = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setPriority'", NULL);
#endif
  {
   self->setPriority(listener,priority);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setPriority'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: set_enabled of class  gamer::EventManager */
#ifndef TOLUA_DISABLE_tolua_event_manager_gamer_EventManager_set_enabled00
static int tolua_event_manager_gamer_EventManager_set_enabled00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"gamer::EventManager",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  gamer::EventManager* self = (gamer::EventManager*)  tolua_tousertype(tolua_S,1,0);
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

/* method: is_enabled of class  gamer::EventManager */
#ifndef TOLUA_DISABLE_tolua_event_manager_gamer_EventManager_is_enabled00
static int tolua_event_manager_gamer_EventManager_is_enabled00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const gamer::EventManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const gamer::EventManager* self = (const gamer::EventManager*)  tolua_tousertype(tolua_S,1,0);
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

/* Open function */
TOLUA_API int tolua_event_manager_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  tolua_module(tolua_S,"gamer",0);
  tolua_beginmodule(tolua_S,"gamer");
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"EventManager","gamer::EventManager","",tolua_collect_gamer__EventManager);
   #else
   tolua_cclass(tolua_S,"EventManager","gamer::EventManager","",NULL);
   #endif
   tolua_beginmodule(tolua_S,"EventManager");
    tolua_function(tolua_S,"delete",tolua_event_manager_gamer_EventManager_delete00);
    tolua_function(tolua_S,"getInstance",tolua_event_manager_gamer_EventManager_getInstance00);
    tolua_function(tolua_S,"destoryInstance",tolua_event_manager_gamer_EventManager_destoryInstance00);
    tolua_function(tolua_S,"addEventListener",tolua_event_manager_gamer_EventManager_addEventListener00);
    tolua_function(tolua_S,"removeEventListener",tolua_event_manager_gamer_EventManager_removeEventListener00);
    tolua_function(tolua_S,"removeEventListenerWithCleanup",tolua_event_manager_gamer_EventManager_removeEventListenerWithCleanup00);
    tolua_function(tolua_S,"removeEventListener",tolua_event_manager_gamer_EventManager_removeEventListener01);
    tolua_function(tolua_S,"removeEventListenerWithCleanup",tolua_event_manager_gamer_EventManager_removeEventListenerWithCleanup01);
    tolua_function(tolua_S,"removeAllEventListeners",tolua_event_manager_gamer_EventManager_removeAllEventListeners00);
    tolua_function(tolua_S,"removeAllEventListenersWithCleanup",tolua_event_manager_gamer_EventManager_removeAllEventListenersWithCleanup00);
    tolua_function(tolua_S,"dispatch",tolua_event_manager_gamer_EventManager_dispatch00);
    tolua_function(tolua_S,"dispatch",tolua_event_manager_gamer_EventManager_dispatch01);
    tolua_function(tolua_S,"setPriority",tolua_event_manager_gamer_EventManager_setPriority00);
    tolua_function(tolua_S,"set_enabled",tolua_event_manager_gamer_EventManager_set_enabled00);
    tolua_function(tolua_S,"is_enabled",tolua_event_manager_gamer_EventManager_is_enabled00);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_event_manager (lua_State* tolua_S) {
 return tolua_event_manager_open(tolua_S);
};
#endif


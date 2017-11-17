/*
** Lua binding: myevent
** Generated automatically by tolua++-1.0.92 on 11/17/17 11:41:40.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_myevent_open (lua_State* tolua_S);

#include "myevent.h"
#include <string>
#include "base/macros.h"

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_id_t (lua_State* tolua_S)
{
 id_t* self = (id_t*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_gamer__Event (lua_State* tolua_S)
{
 gamer::Event* self = (gamer::Event*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"id_t");
 tolua_usertype(tolua_S,"gamer::Event");
}

/* method: new of class  gamer::Event */
#ifndef TOLUA_DISABLE_tolua_myevent_gamer_Event_new00
static int tolua_myevent_gamer_Event_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"gamer::Event",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   gamer::Event* tolua_ret = (gamer::Event*)  Mtolua_new((gamer::Event)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"gamer::Event");
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

/* method: new_local of class  gamer::Event */
#ifndef TOLUA_DISABLE_tolua_myevent_gamer_Event_new00_local
static int tolua_myevent_gamer_Event_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"gamer::Event",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   gamer::Event* tolua_ret = (gamer::Event*)  Mtolua_new((gamer::Event)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"gamer::Event");
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

/* method: new of class  gamer::Event */
#ifndef TOLUA_DISABLE_tolua_myevent_gamer_Event_new01
static int tolua_myevent_gamer_Event_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"gamer::Event",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"id_t",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  id_t event_id = *((id_t*)  tolua_tousertype(tolua_S,2,0));
  {
   gamer::Event* tolua_ret = (gamer::Event*)  Mtolua_new((gamer::Event)(event_id));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"gamer::Event");
  }
 }
 return 1;
tolua_lerror:
 return tolua_myevent_gamer_Event_new00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  gamer::Event */
#ifndef TOLUA_DISABLE_tolua_myevent_gamer_Event_new01_local
static int tolua_myevent_gamer_Event_new01_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"gamer::Event",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"id_t",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  id_t event_id = *((id_t*)  tolua_tousertype(tolua_S,2,0));
  {
   gamer::Event* tolua_ret = (gamer::Event*)  Mtolua_new((gamer::Event)(event_id));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"gamer::Event");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_myevent_gamer_Event_new00_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  gamer::Event */
#ifndef TOLUA_DISABLE_tolua_myevent_gamer_Event_delete00
static int tolua_myevent_gamer_Event_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"gamer::Event",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  gamer::Event* self = (gamer::Event*)  tolua_tousertype(tolua_S,1,0);
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

/* method: set_event_id of class  gamer::Event */
#ifndef TOLUA_DISABLE_tolua_myevent_gamer_Event_set_event_id00
static int tolua_myevent_gamer_Event_set_event_id00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"gamer::Event",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"id_t",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  gamer::Event* self = (gamer::Event*)  tolua_tousertype(tolua_S,1,0);
  id_t event_id = *((id_t*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'set_event_id'", NULL);
#endif
  {
   self->set_event_id(event_id);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'set_event_id'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: event_id of class  gamer::Event */
#ifndef TOLUA_DISABLE_tolua_myevent_gamer_Event_event_id00
static int tolua_myevent_gamer_Event_event_id00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const gamer::Event",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const gamer::Event* self = (const gamer::Event*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'event_id'", NULL);
#endif
  {
   id_t tolua_ret = (id_t)  self->event_id();
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
 tolua_error(tolua_S,"#ferror in function 'event_id'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: set_sub_event_id of class  gamer::Event */
#ifndef TOLUA_DISABLE_tolua_myevent_gamer_Event_set_sub_event_id00
static int tolua_myevent_gamer_Event_set_sub_event_id00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"gamer::Event",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"id_t",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  gamer::Event* self = (gamer::Event*)  tolua_tousertype(tolua_S,1,0);
  id_t sub_event_id = *((id_t*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'set_sub_event_id'", NULL);
#endif
  {
   self->set_sub_event_id(sub_event_id);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'set_sub_event_id'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: sub_event_id of class  gamer::Event */
#ifndef TOLUA_DISABLE_tolua_myevent_gamer_Event_sub_event_id00
static int tolua_myevent_gamer_Event_sub_event_id00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const gamer::Event",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const gamer::Event* self = (const gamer::Event*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'sub_event_id'", NULL);
#endif
  {
   id_t tolua_ret = (id_t)  self->sub_event_id();
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
 tolua_error(tolua_S,"#ferror in function 'sub_event_id'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: set_event_name of class  gamer::Event */
#ifndef TOLUA_DISABLE_tolua_myevent_gamer_Event_set_event_name00
static int tolua_myevent_gamer_Event_set_event_name00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"gamer::Event",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  gamer::Event* self = (gamer::Event*)  tolua_tousertype(tolua_S,1,0);
  const std::string event_name = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'set_event_name'", NULL);
#endif
  {
   self->set_event_name(event_name);
   tolua_pushcppstring(tolua_S,(const char*)event_name);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'set_event_name'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: event_name of class  gamer::Event */
#ifndef TOLUA_DISABLE_tolua_myevent_gamer_Event_event_name00
static int tolua_myevent_gamer_Event_event_name00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const gamer::Event",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const gamer::Event* self = (const gamer::Event*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'event_name'", NULL);
#endif
  {
   const std::string tolua_ret = (const std::string)  self->event_name();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'event_name'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: set_user_data of class  gamer::Event */
#ifndef TOLUA_DISABLE_tolua_myevent_gamer_Event_set_user_data00
static int tolua_myevent_gamer_Event_set_user_data00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"gamer::Event",0,&tolua_err) ||
     !tolua_isuserdata(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  gamer::Event* self = (gamer::Event*)  tolua_tousertype(tolua_S,1,0);
  void* user_data = ((void*)  tolua_touserdata(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'set_user_data'", NULL);
#endif
  {
   self->set_user_data(user_data);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'set_user_data'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: user_data of class  gamer::Event */
#ifndef TOLUA_DISABLE_tolua_myevent_gamer_Event_user_data00
static int tolua_myevent_gamer_Event_user_data00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const gamer::Event",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const gamer::Event* self = (const gamer::Event*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'user_data'", NULL);
#endif
  {
   void* tolua_ret = (void*)  self->user_data();
   tolua_pushuserdata(tolua_S,(void*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'user_data'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: check_event_id of class  gamer::Event */
#ifndef TOLUA_DISABLE_tolua_myevent_gamer_Event_check_event_id00
static int tolua_myevent_gamer_Event_check_event_id00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const gamer::Event",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const gamer::Event* self = (const gamer::Event*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'check_event_id'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->check_event_id();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'check_event_id'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: stop_propagation of class  gamer::Event */
#ifndef TOLUA_DISABLE_tolua_myevent_gamer_Event_stop_propagation00
static int tolua_myevent_gamer_Event_stop_propagation00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"gamer::Event",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  gamer::Event* self = (gamer::Event*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'stop_propagation'", NULL);
#endif
  {
   self->stop_propagation();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'stop_propagation'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: is_stopped of class  gamer::Event */
#ifndef TOLUA_DISABLE_tolua_myevent_gamer_Event_is_stopped00
static int tolua_myevent_gamer_Event_is_stopped00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const gamer::Event",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const gamer::Event* self = (const gamer::Event*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'is_stopped'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->is_stopped();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'is_stopped'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_myevent_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  tolua_module(tolua_S,"gamer",0);
  tolua_beginmodule(tolua_S,"gamer");
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"Event","gamer::Event","",tolua_collect_gamer__Event);
   #else
   tolua_cclass(tolua_S,"Event","gamer::Event","",NULL);
   #endif
   tolua_beginmodule(tolua_S,"Event");
    tolua_function(tolua_S,"new",tolua_myevent_gamer_Event_new00);
    tolua_function(tolua_S,"new_local",tolua_myevent_gamer_Event_new00_local);
    tolua_function(tolua_S,".call",tolua_myevent_gamer_Event_new00_local);
    tolua_function(tolua_S,"new",tolua_myevent_gamer_Event_new01);
    tolua_function(tolua_S,"new_local",tolua_myevent_gamer_Event_new01_local);
    tolua_function(tolua_S,".call",tolua_myevent_gamer_Event_new01_local);
    tolua_function(tolua_S,"delete",tolua_myevent_gamer_Event_delete00);
    tolua_function(tolua_S,"set_event_id",tolua_myevent_gamer_Event_set_event_id00);
    tolua_function(tolua_S,"event_id",tolua_myevent_gamer_Event_event_id00);
    tolua_function(tolua_S,"set_sub_event_id",tolua_myevent_gamer_Event_set_sub_event_id00);
    tolua_function(tolua_S,"sub_event_id",tolua_myevent_gamer_Event_sub_event_id00);
    tolua_function(tolua_S,"set_event_name",tolua_myevent_gamer_Event_set_event_name00);
    tolua_function(tolua_S,"event_name",tolua_myevent_gamer_Event_event_name00);
    tolua_function(tolua_S,"set_user_data",tolua_myevent_gamer_Event_set_user_data00);
    tolua_function(tolua_S,"user_data",tolua_myevent_gamer_Event_user_data00);
    tolua_function(tolua_S,"check_event_id",tolua_myevent_gamer_Event_check_event_id00);
    tolua_function(tolua_S,"stop_propagation",tolua_myevent_gamer_Event_stop_propagation00);
    tolua_function(tolua_S,"is_stopped",tolua_myevent_gamer_Event_is_stopped00);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_myevent (lua_State* tolua_S) {
 return tolua_myevent_open(tolua_S);
};
#endif


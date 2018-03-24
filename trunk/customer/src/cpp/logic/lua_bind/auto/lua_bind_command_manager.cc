/*
** Lua binding: command_manager
** Generated automatically by tolua++-1.0.92 on 11/17/17 11:39:35.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_command_manager_open (lua_State* tolua_S);

#include <vector>
#include <string>
#include "command_manager.h"
#include "command_listener.h"
#include "base/macros.h"

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_gamer__CommandManager (lua_State* tolua_S)
{
 gamer::CommandManager* self = (gamer::CommandManager*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"gamer::CommandManager");
 tolua_usertype(tolua_S,"gamer::CommandListener");
 tolua_usertype(tolua_S,"id_t");
}

/* method: delete of class  gamer::CommandManager */
#ifndef TOLUA_DISABLE_tolua_command_manager_gamer_CommandManager_delete00
static int tolua_command_manager_gamer_CommandManager_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"gamer::CommandManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  gamer::CommandManager* self = (gamer::CommandManager*)  tolua_tousertype(tolua_S,1,0);
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

/* method: getInstance of class  gamer::CommandManager */
#ifndef TOLUA_DISABLE_tolua_command_manager_gamer_CommandManager_getInstance00
static int tolua_command_manager_gamer_CommandManager_getInstance00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"gamer::CommandManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   gamer::CommandManager* tolua_ret = (gamer::CommandManager*)  gamer::CommandManager::getInstance();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"gamer::CommandManager");
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

/* method: destoryInstance of class  gamer::CommandManager */
#ifndef TOLUA_DISABLE_tolua_command_manager_gamer_CommandManager_destoryInstance00
static int tolua_command_manager_gamer_CommandManager_destoryInstance00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"gamer::CommandManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   gamer::CommandManager::destoryInstance();
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

/* method: addCmdListener of class  gamer::CommandManager */
#ifndef TOLUA_DISABLE_tolua_command_manager_gamer_CommandManager_addCmdListener00
static int tolua_command_manager_gamer_CommandManager_addCmdListener00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"gamer::CommandManager",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"gamer::CommandListener",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  gamer::CommandManager* self = (gamer::CommandManager*)  tolua_tousertype(tolua_S,1,0);
  gamer::CommandListener* listener = ((gamer::CommandListener*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addCmdListener'", NULL);
#endif
  {
   self->addCmdListener(listener);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addCmdListener'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: removeCmdListener of class  gamer::CommandManager */
#ifndef TOLUA_DISABLE_tolua_command_manager_gamer_CommandManager_removeCmdListener00
static int tolua_command_manager_gamer_CommandManager_removeCmdListener00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"gamer::CommandManager",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"gamer::CommandListener",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  gamer::CommandManager* self = (gamer::CommandManager*)  tolua_tousertype(tolua_S,1,0);
  gamer::CommandListener* listener = ((gamer::CommandListener*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'removeCmdListener'", NULL);
#endif
  {
   self->removeCmdListener(listener);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'removeCmdListener'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: removeCmdListenerWithCleanup of class  gamer::CommandManager */
#ifndef TOLUA_DISABLE_tolua_command_manager_gamer_CommandManager_removeCmdListenerWithCleanup00
static int tolua_command_manager_gamer_CommandManager_removeCmdListenerWithCleanup00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"gamer::CommandManager",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"gamer::CommandListener",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  gamer::CommandManager* self = (gamer::CommandManager*)  tolua_tousertype(tolua_S,1,0);
  gamer::CommandListener* listener = ((gamer::CommandListener*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'removeCmdListenerWithCleanup'", NULL);
#endif
  {
   self->removeCmdListenerWithCleanup(listener);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'removeCmdListenerWithCleanup'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: removeAllCmdListeners of class  gamer::CommandManager */
#ifndef TOLUA_DISABLE_tolua_command_manager_gamer_CommandManager_removeAllCmdListeners00
static int tolua_command_manager_gamer_CommandManager_removeAllCmdListeners00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"gamer::CommandManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  gamer::CommandManager* self = (gamer::CommandManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'removeAllCmdListeners'", NULL);
#endif
  {
   self->removeAllCmdListeners();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'removeAllCmdListeners'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: removeAllCmdListenersWithcleanup of class  gamer::CommandManager */
#ifndef TOLUA_DISABLE_tolua_command_manager_gamer_CommandManager_removeAllCmdListenersWithcleanup00
static int tolua_command_manager_gamer_CommandManager_removeAllCmdListenersWithcleanup00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"gamer::CommandManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  gamer::CommandManager* self = (gamer::CommandManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'removeAllCmdListenersWithcleanup'", NULL);
#endif
  {
   self->removeAllCmdListenersWithcleanup();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'removeAllCmdListenersWithcleanup'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: sendCmd of class  gamer::CommandManager */
#ifndef TOLUA_DISABLE_tolua_command_manager_gamer_CommandManager_sendCmd00
static int tolua_command_manager_gamer_CommandManager_sendCmd00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"gamer::CommandManager",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"id_t",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  gamer::CommandManager* self = (gamer::CommandManager*)  tolua_tousertype(tolua_S,1,0);
  id_t command_id = *((id_t*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'sendCmd'", NULL);
#endif
  {
   self->sendCmd(command_id);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'sendCmd'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_command_manager_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  tolua_module(tolua_S,"gamer",0);
  tolua_beginmodule(tolua_S,"gamer");
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"CommandManager","gamer::CommandManager","",tolua_collect_gamer__CommandManager);
   #else
   tolua_cclass(tolua_S,"CommandManager","gamer::CommandManager","",NULL);
   #endif
   tolua_beginmodule(tolua_S,"CommandManager");
    tolua_function(tolua_S,"delete",tolua_command_manager_gamer_CommandManager_delete00);
    tolua_function(tolua_S,"getInstance",tolua_command_manager_gamer_CommandManager_getInstance00);
    tolua_function(tolua_S,"destoryInstance",tolua_command_manager_gamer_CommandManager_destoryInstance00);
    tolua_function(tolua_S,"addCmdListener",tolua_command_manager_gamer_CommandManager_addCmdListener00);
    tolua_function(tolua_S,"removeCmdListener",tolua_command_manager_gamer_CommandManager_removeCmdListener00);
    tolua_function(tolua_S,"removeCmdListenerWithCleanup",tolua_command_manager_gamer_CommandManager_removeCmdListenerWithCleanup00);
    tolua_function(tolua_S,"removeAllCmdListeners",tolua_command_manager_gamer_CommandManager_removeAllCmdListeners00);
    tolua_function(tolua_S,"removeAllCmdListenersWithcleanup",tolua_command_manager_gamer_CommandManager_removeAllCmdListenersWithcleanup00);
    tolua_function(tolua_S,"sendCmd",tolua_command_manager_gamer_CommandManager_sendCmd00);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_command_manager (lua_State* tolua_S) {
 return tolua_command_manager_open(tolua_S);
};
#endif


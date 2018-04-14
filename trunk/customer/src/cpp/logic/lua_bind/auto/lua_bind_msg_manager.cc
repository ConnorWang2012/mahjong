/*
** Lua binding: msg_manager
** Generated automatically by tolua++-1.0.92 on 02/10/18 19:16:40.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_msg_manager_open (lua_State* tolua_S);

#include "msg/msg_manager.h"
#include <string>
#include <unordered_map>
#include "myevent.h"
#include "macros.h"
#include "msg/msg.h"

/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"gamer::MsgManager");
 tolua_usertype(tolua_S,"gamer::LuaFunction");
 tolua_usertype(tolua_S,"google::protobuf::Message");
}

/* method: getInstance of class  gamer::MsgManager */
#ifndef TOLUA_DISABLE_tolua_msg_manager_gamer_MsgManager_getInstance00
static int tolua_msg_manager_gamer_MsgManager_getInstance00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"gamer::MsgManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   gamer::MsgManager* tolua_ret = (gamer::MsgManager*)  gamer::MsgManager::getInstance();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"gamer::MsgManager");
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

/* method: sendMsg of class  gamer::MsgManager */
#ifndef TOLUA_DISABLE_tolua_msg_manager_gamer_MsgManager_sendMsg00
static int tolua_msg_manager_gamer_MsgManager_sendMsg00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"gamer::MsgManager",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const google::protobuf::Message",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  gamer::MsgManager* self = (gamer::MsgManager*)  tolua_tousertype(tolua_S,1,0);
  unsigned int msg_type = (( unsigned int)  tolua_tonumber(tolua_S,2,0));
  unsigned int msg_id = (( unsigned int)  tolua_tonumber(tolua_S,3,0));
  const google::protobuf::Message* msg = ((const google::protobuf::Message*)  tolua_tousertype(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'sendMsg'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->sendMsg(msg_type,msg_id,*msg);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'sendMsg'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: addMsgListener of class  gamer::MsgManager */
#ifndef TOLUA_DISABLE_tolua_msg_manager_gamer_MsgManager_addMsgListener00
static int tolua_msg_manager_gamer_MsgManager_addMsgListener00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"gamer::MsgManager",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     //(tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"gamer::LuaFunction",0,&tolua_err)) ||
	 tolua_isvaluenil(tolua_S, 4, &tolua_err) || !lua_isfunction(tolua_S, 4) ||
	 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  gamer::MsgManager* self = (gamer::MsgManager*)  tolua_tousertype(tolua_S,1,0);
  unsigned int msg_type = (( unsigned int)  tolua_tonumber(tolua_S,2,0));
  unsigned int msg_id = (( unsigned int)  tolua_tonumber(tolua_S,3,0));
  auto var = lua_topointer(tolua_S, 4);
  auto listener_id = std::to_string((unsigned)var);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addMsgListener'", NULL);
#endif
  {
   self->addMsgListener(msg_type, msg_id, listener_id);
   tolua_pushcppstring(tolua_S, (const char*)listener_id);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addMsgListener'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: addMsgListener of class  gamer::MsgManager */
#ifndef TOLUA_DISABLE_tolua_msg_manager_gamer_MsgManager_addMsgListener01
static int tolua_msg_manager_gamer_MsgManager_addMsgListener01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"gamer::MsgManager",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     //(tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"gamer::LuaFunction",0,&tolua_err)) ||
	 tolua_isvaluenil(tolua_S, 3, &tolua_err) || !lua_isfunction(tolua_S, 3) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  gamer::MsgManager* self = (gamer::MsgManager*)  tolua_tousertype(tolua_S,1,0);
  unsigned int msg_type = (( unsigned int)  tolua_tonumber(tolua_S,2,0));
  auto var = lua_topointer(tolua_S, 3);
  auto listener_id = std::to_string((unsigned)var);

#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addMsgListener'", NULL);
#endif
  {
   self->addMsgListener(msg_type, listener_id);
   tolua_pushcppstring(tolua_S, (const char*)listener_id);
  }
 }
 return 1;
tolua_lerror:
 return tolua_msg_manager_gamer_MsgManager_addMsgListener00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: removeMsgListener of class  gamer::MsgManager */
#ifndef TOLUA_DISABLE_tolua_msg_manager_gamer_MsgManager_removeMsgListener00
static int tolua_msg_manager_gamer_MsgManager_removeMsgListener00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"gamer::MsgManager",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     //(tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"gamer::LuaFunction",0,&tolua_err)) ||
	 tolua_isvaluenil(tolua_S, 4, &tolua_err) || !lua_isfunction(tolua_S, 4) ||
	 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  gamer::MsgManager* self = (gamer::MsgManager*)  tolua_tousertype(tolua_S,1,0);
  unsigned int msg_type = (( unsigned int)  tolua_tonumber(tolua_S,2,0));
  unsigned int msg_id = (( unsigned int)  tolua_tonumber(tolua_S,3,0));
  auto var = lua_topointer(tolua_S, 4);
  auto listener_id = std::to_string((unsigned)var);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'removeMsgListener'", NULL);
#endif
  {
   self->removeMsgListener(msg_type, msg_id, listener_id);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'removeMsgListener'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: removeMsgListener of class  gamer::MsgManager */
#ifndef TOLUA_DISABLE_tolua_msg_manager_gamer_MsgManager_removeMsgListener01
static int tolua_msg_manager_gamer_MsgManager_removeMsgListener01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"gamer::MsgManager",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     //(tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"gamer::LuaFunction",0,&tolua_err)) ||
	 tolua_isvaluenil(tolua_S, 3, &tolua_err) || !lua_isfunction(tolua_S, 3) ||
	 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  gamer::MsgManager* self = (gamer::MsgManager*)  tolua_tousertype(tolua_S,1,0);
  unsigned int msg_type = (( unsigned int)  tolua_tonumber(tolua_S,2,0));
  auto var = lua_topointer(tolua_S, 3);
  auto listener_id = std::to_string((unsigned)var);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'removeMsgListener'", NULL);
#endif
  {
   self->removeMsgListener(msg_type,listener_id);
  }
 }
 return 0;
tolua_lerror:
 return tolua_msg_manager_gamer_MsgManager_removeMsgListener00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: removeMsgListener of class  gamer::MsgManager */
#ifndef TOLUA_DISABLE_tolua_msg_manager_gamer_MsgManager_removeMsgListener02
static int tolua_msg_manager_gamer_MsgManager_removeMsgListener02(lua_State* tolua_S)
{
	tolua_Error tolua_err;
	if (
		!tolua_isusertype(tolua_S, 1, "gamer::MsgManager", 0, &tolua_err) ||
		!tolua_isstring(tolua_S, 2, 0, &tolua_err) ||
		!tolua_isnoobj(tolua_S, 3, &tolua_err)
		)
		goto tolua_lerror;
	else
	{
		gamer::MsgManager* self = (gamer::MsgManager*)tolua_tousertype(tolua_S, 1, 0);
		const char* listener_id = ((const char*)tolua_tostring(tolua_S, 2, 0));
#ifndef TOLUA_RELEASE
		if (!self) tolua_error(tolua_S, "invalid 'self' in function 'removeMsgListener'", NULL);
#endif
		{
			self->removeMsgListener(listener_id);
		}
	}
	return 0;
tolua_lerror:
	return tolua_msg_manager_gamer_MsgManager_removeMsgListener00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_msg_manager_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  tolua_module(tolua_S,"gamer",0);
  tolua_beginmodule(tolua_S,"gamer");
   tolua_cclass(tolua_S,"MsgManager","gamer::MsgManager","",NULL);
   tolua_beginmodule(tolua_S,"MsgManager");
    tolua_function(tolua_S,"getInstance",tolua_msg_manager_gamer_MsgManager_getInstance00);
    tolua_function(tolua_S,"sendMsg",tolua_msg_manager_gamer_MsgManager_sendMsg00);
    tolua_function(tolua_S,"addMsgListener",tolua_msg_manager_gamer_MsgManager_addMsgListener00);
    tolua_function(tolua_S,"addMsgListener",tolua_msg_manager_gamer_MsgManager_addMsgListener01);
    tolua_function(tolua_S,"removeMsgListener",tolua_msg_manager_gamer_MsgManager_removeMsgListener00);
    tolua_function(tolua_S,"removeMsgListener",tolua_msg_manager_gamer_MsgManager_removeMsgListener01);
	tolua_function(tolua_S,"removeMsgListener",tolua_msg_manager_gamer_MsgManager_removeMsgListener02);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_msg_manager (lua_State* tolua_S) {
 return tolua_msg_manager_open(tolua_S);
};
#endif


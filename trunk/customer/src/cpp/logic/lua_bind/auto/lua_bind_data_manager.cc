/*
** Lua binding: data_manager
** Generated automatically by tolua++-1.0.92 on 06/19/17 21:44:43.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_data_manager_open (lua_State* tolua_S);

#include "data_manager.h"
#include <unordered_map>
#include "base/basic_manager.h"
#include "data/data_constants.h"

/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"google::protobuf::Message");
 tolua_usertype(tolua_S,"gamer::DataManager");
 tolua_usertype(tolua_S,"BasicManager<DataManager>");
}

/* method: getInstance of class  gamer::DataManager */
#ifndef TOLUA_DISABLE_tolua_data_manager_gamer_DataManager_getInstance00
static int tolua_data_manager_gamer_DataManager_getInstance00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"gamer::DataManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   gamer::DataManager* tolua_ret = (gamer::DataManager*)  gamer::DataManager::getInstance();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"gamer::DataManager");
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

/* method: getMutableData of class  gamer::DataManager */
#ifndef TOLUA_DISABLE_tolua_data_manager_gamer_DataManager_getMutableData00
static int tolua_data_manager_gamer_DataManager_getMutableData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"gamer::DataManager",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  gamer::DataManager* self = (gamer::DataManager*)  tolua_tousertype(tolua_S,1,0);
  int key = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getMutableData'", NULL);
#endif
  {
   google::protobuf::Message* tolua_ret = (google::protobuf::Message*)  self->getMutableData(key);
   switch (key)
   {
   case (int)gamer::DataIDs::DATA_ID_MY_LOGIN_MSG_PROTOCOL:
       tolua_pushusertype(tolua_S, (void*)tolua_ret, "gamer::protocol::MyLoginMsgProtocol");
       break;
   case (int)gamer::DataIDs::DATA_ID_CREATE_ROOM_MSG_PROTOCOL:
       tolua_pushusertype(tolua_S, (void*)tolua_ret, "gamer::protocol::CreateRoomMsgProtocol");
       break;
   case (int)gamer::DataIDs::DATA_ID_ROOM_MSG_PROTOCOL:
       tolua_pushusertype(tolua_S, (void*)tolua_ret, "gamer::protocol::RoomMsgProtocol");
       break;
   default:
       goto tolua_lerror;
       break;
   }
    //tolua_pushusertype(tolua_S,(void*)tolua_ret,"google::protobuf::Message");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getMutableData'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_data_manager_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  tolua_module(tolua_S,"gamer",0);
  tolua_beginmodule(tolua_S,"gamer");
   tolua_cclass(tolua_S,"DataManager","gamer::DataManager","BasicManager<DataManager>",NULL);
   tolua_beginmodule(tolua_S,"DataManager");
    tolua_function(tolua_S,"getInstance",tolua_data_manager_gamer_DataManager_getInstance00);
    tolua_function(tolua_S,"getMutableData",tolua_data_manager_gamer_DataManager_getMutableData00);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_data_manager (lua_State* tolua_S) {
 return tolua_data_manager_open(tolua_S);
};
#endif


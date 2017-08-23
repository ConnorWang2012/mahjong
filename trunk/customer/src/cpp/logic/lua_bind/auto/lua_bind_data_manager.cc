/*
** Lua binding: data_manager
** Generated automatically by tolua++-1.0.92 on 08/19/17 00:09:24.
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

/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"gamer::protocol::PlayerCardsMsgProtocol");
 tolua_usertype(tolua_S,"gamer::DataManager");
 tolua_usertype(tolua_S,"gamer::protocol::CreateRoomMsgProtocol");
 tolua_usertype(tolua_S,"gamer::protocol::RoomMsgProtocol");
 tolua_usertype(tolua_S,"gamer::protocol::PlayCardMsgProtocol");
 tolua_usertype(tolua_S,"gamer::protocol::MyLoginMsgProtocol");
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

/* method: my_login_msg_protocol of class  gamer::DataManager */
#ifndef TOLUA_DISABLE_tolua_data_manager_gamer_DataManager_my_login_msg_protocol00
static int tolua_data_manager_gamer_DataManager_my_login_msg_protocol00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"gamer::DataManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  gamer::DataManager* self = (gamer::DataManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'my_login_msg_protocol'", NULL);
#endif
  {
   gamer::protocol::MyLoginMsgProtocol* tolua_ret = (gamer::protocol::MyLoginMsgProtocol*)  self->my_login_msg_protocol();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"gamer::protocol::MyLoginMsgProtocol");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'my_login_msg_protocol'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: create_room_msg_protocol of class  gamer::DataManager */
#ifndef TOLUA_DISABLE_tolua_data_manager_gamer_DataManager_create_room_msg_protocol00
static int tolua_data_manager_gamer_DataManager_create_room_msg_protocol00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"gamer::DataManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  gamer::DataManager* self = (gamer::DataManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'create_room_msg_protocol'", NULL);
#endif
  {
   gamer::protocol::CreateRoomMsgProtocol* tolua_ret = (gamer::protocol::CreateRoomMsgProtocol*)  self->create_room_msg_protocol();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"gamer::protocol::CreateRoomMsgProtocol");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'create_room_msg_protocol'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: room_msg_protocol of class  gamer::DataManager */
#ifndef TOLUA_DISABLE_tolua_data_manager_gamer_DataManager_room_msg_protocol00
static int tolua_data_manager_gamer_DataManager_room_msg_protocol00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"gamer::DataManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  gamer::DataManager* self = (gamer::DataManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'room_msg_protocol'", NULL);
#endif
  {
   gamer::protocol::RoomMsgProtocol* tolua_ret = (gamer::protocol::RoomMsgProtocol*)  self->room_msg_protocol();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"gamer::protocol::RoomMsgProtocol");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'room_msg_protocol'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: play_card_msg_protocol of class  gamer::DataManager */
#ifndef TOLUA_DISABLE_tolua_data_manager_gamer_DataManager_play_card_msg_protocol00
static int tolua_data_manager_gamer_DataManager_play_card_msg_protocol00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"gamer::DataManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  gamer::DataManager* self = (gamer::DataManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'play_card_msg_protocol'", NULL);
#endif
  {
   gamer::protocol::PlayCardMsgProtocol* tolua_ret = (gamer::protocol::PlayCardMsgProtocol*)  self->play_card_msg_protocol();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"gamer::protocol::PlayCardMsgProtocol");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'play_card_msg_protocol'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: cards_msg_protocol_of_player_self of class  gamer::DataManager */
#ifndef TOLUA_DISABLE_tolua_data_manager_gamer_DataManager_cards_msg_protocol_of_player_self00
static int tolua_data_manager_gamer_DataManager_cards_msg_protocol_of_player_self00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"gamer::DataManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  gamer::DataManager* self = (gamer::DataManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'cards_msg_protocol_of_player_self'", NULL);
#endif
  {
   gamer::protocol::PlayerCardsMsgProtocol* tolua_ret = (gamer::protocol::PlayerCardsMsgProtocol*)  self->cards_msg_protocol_of_player_self();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"gamer::protocol::PlayerCardsMsgProtocol");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'cards_msg_protocol_of_player_self'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: cards_msg_protocol_of_left_player of class  gamer::DataManager */
#ifndef TOLUA_DISABLE_tolua_data_manager_gamer_DataManager_cards_msg_protocol_of_left_player00
static int tolua_data_manager_gamer_DataManager_cards_msg_protocol_of_left_player00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"gamer::DataManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  gamer::DataManager* self = (gamer::DataManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'cards_msg_protocol_of_left_player'", NULL);
#endif
  {
   gamer::protocol::PlayerCardsMsgProtocol* tolua_ret = (gamer::protocol::PlayerCardsMsgProtocol*)  self->cards_msg_protocol_of_left_player();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"gamer::protocol::PlayerCardsMsgProtocol");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'cards_msg_protocol_of_left_player'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: cards_msg_protocol_of_opposite_player of class  gamer::DataManager */
#ifndef TOLUA_DISABLE_tolua_data_manager_gamer_DataManager_cards_msg_protocol_of_opposite_player00
static int tolua_data_manager_gamer_DataManager_cards_msg_protocol_of_opposite_player00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"gamer::DataManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  gamer::DataManager* self = (gamer::DataManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'cards_msg_protocol_of_opposite_player'", NULL);
#endif
  {
   gamer::protocol::PlayerCardsMsgProtocol* tolua_ret = (gamer::protocol::PlayerCardsMsgProtocol*)  self->cards_msg_protocol_of_opposite_player();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"gamer::protocol::PlayerCardsMsgProtocol");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'cards_msg_protocol_of_opposite_player'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: cards_msg_protocol_of_right_player of class  gamer::DataManager */
#ifndef TOLUA_DISABLE_tolua_data_manager_gamer_DataManager_cards_msg_protocol_of_right_player00
static int tolua_data_manager_gamer_DataManager_cards_msg_protocol_of_right_player00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"gamer::DataManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  gamer::DataManager* self = (gamer::DataManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'cards_msg_protocol_of_right_player'", NULL);
#endif
  {
   gamer::protocol::PlayerCardsMsgProtocol* tolua_ret = (gamer::protocol::PlayerCardsMsgProtocol*)  self->cards_msg_protocol_of_right_player();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"gamer::protocol::PlayerCardsMsgProtocol");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'cards_msg_protocol_of_right_player'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: self_player_id of class  gamer::DataManager */
#ifndef TOLUA_DISABLE_tolua_data_manager_gamer_DataManager_self_player_id00
static int tolua_data_manager_gamer_DataManager_self_player_id00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const gamer::DataManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const gamer::DataManager* self = (const gamer::DataManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'self_player_id'", NULL);
#endif
  {
   const int tolua_ret = (const int)  self->self_player_id();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'self_player_id'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: left_player_id of class  gamer::DataManager */
#ifndef TOLUA_DISABLE_tolua_data_manager_gamer_DataManager_left_player_id00
static int tolua_data_manager_gamer_DataManager_left_player_id00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const gamer::DataManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const gamer::DataManager* self = (const gamer::DataManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'left_player_id'", NULL);
#endif
  {
   const int tolua_ret = (const int)  self->left_player_id();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'left_player_id'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: opposite_player_id of class  gamer::DataManager */
#ifndef TOLUA_DISABLE_tolua_data_manager_gamer_DataManager_opposite_player_id00
static int tolua_data_manager_gamer_DataManager_opposite_player_id00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const gamer::DataManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const gamer::DataManager* self = (const gamer::DataManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'opposite_player_id'", NULL);
#endif
  {
   const int tolua_ret = (const int)  self->opposite_player_id();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'opposite_player_id'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: right_player_id of class  gamer::DataManager */
#ifndef TOLUA_DISABLE_tolua_data_manager_gamer_DataManager_right_player_id00
static int tolua_data_manager_gamer_DataManager_right_player_id00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const gamer::DataManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const gamer::DataManager* self = (const gamer::DataManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'right_player_id'", NULL);
#endif
  {
   const int tolua_ret = (const int)  self->right_player_id();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'right_player_id'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: updateCardForDiscard of class  gamer::DataManager */
#ifndef TOLUA_DISABLE_tolua_data_manager_gamer_DataManager_updateCardForDiscard00
static int tolua_data_manager_gamer_DataManager_updateCardForDiscard00(lua_State* tolua_S)
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
  int discard = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'updateCardForDiscard'", NULL);
#endif
  {
   self->updateCardForDiscard(discard);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'updateCardForDiscard'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: updateInvisibleHandCard of class  gamer::DataManager */
#ifndef TOLUA_DISABLE_tolua_data_manager_gamer_DataManager_updateInvisibleHandCard00
static int tolua_data_manager_gamer_DataManager_updateInvisibleHandCard00(lua_State* tolua_S)
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
  int new_card = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'updateInvisibleHandCard'", NULL);
#endif
  {
   self->updateInvisibleHandCard(new_card);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'updateInvisibleHandCard'.",&tolua_err);
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
    tolua_function(tolua_S,"my_login_msg_protocol",tolua_data_manager_gamer_DataManager_my_login_msg_protocol00);
    tolua_function(tolua_S,"create_room_msg_protocol",tolua_data_manager_gamer_DataManager_create_room_msg_protocol00);
    tolua_function(tolua_S,"room_msg_protocol",tolua_data_manager_gamer_DataManager_room_msg_protocol00);
    tolua_function(tolua_S,"play_card_msg_protocol",tolua_data_manager_gamer_DataManager_play_card_msg_protocol00);
    tolua_function(tolua_S,"cards_msg_protocol_of_player_self",tolua_data_manager_gamer_DataManager_cards_msg_protocol_of_player_self00);
    tolua_function(tolua_S,"cards_msg_protocol_of_left_player",tolua_data_manager_gamer_DataManager_cards_msg_protocol_of_left_player00);
    tolua_function(tolua_S,"cards_msg_protocol_of_opposite_player",tolua_data_manager_gamer_DataManager_cards_msg_protocol_of_opposite_player00);
    tolua_function(tolua_S,"cards_msg_protocol_of_right_player",tolua_data_manager_gamer_DataManager_cards_msg_protocol_of_right_player00);
    tolua_function(tolua_S,"self_player_id",tolua_data_manager_gamer_DataManager_self_player_id00);
    tolua_function(tolua_S,"left_player_id",tolua_data_manager_gamer_DataManager_left_player_id00);
    tolua_function(tolua_S,"opposite_player_id",tolua_data_manager_gamer_DataManager_opposite_player_id00);
    tolua_function(tolua_S,"right_player_id",tolua_data_manager_gamer_DataManager_right_player_id00);
    tolua_function(tolua_S,"updateCardForDiscard",tolua_data_manager_gamer_DataManager_updateCardForDiscard00);
    tolua_function(tolua_S,"updateInvisibleHandCard",tolua_data_manager_gamer_DataManager_updateInvisibleHandCard00);
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


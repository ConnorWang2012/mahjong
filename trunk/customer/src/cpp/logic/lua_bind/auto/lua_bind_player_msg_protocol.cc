/*
** Lua binding: player_msg_protocol
** Generated automatically by tolua++-1.0.92 on 11/02/17 16:56:24.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_player_msg_protocol_open (lua_State* tolua_S);

#include "msg/protocol/player_msg_protocol.pb.h"
#include <string>
#include <google/protobuf/stubs/common.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/unknown_field_set.h>

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect___google__protobuf__uint32 (lua_State* tolua_S)
{
 ::google::protobuf::uint32* self = (::google::protobuf::uint32*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_gamer__protocol__PlayerMsgProtocol (lua_State* tolua_S)
{
 gamer::protocol::PlayerMsgProtocol* self = (gamer::protocol::PlayerMsgProtocol*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"::google::protobuf::uint32");
 tolua_usertype(tolua_S,"gamer::protocol::PlayerMsgProtocol");
 tolua_usertype(tolua_S,"google::protobuf::Message");
}

/* method: new of class  gamer::protocol::PlayerMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_player_msg_protocol_gamer_protocol_PlayerMsgProtocol_new00
static int tolua_player_msg_protocol_gamer_protocol_PlayerMsgProtocol_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"gamer::protocol::PlayerMsgProtocol",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   gamer::protocol::PlayerMsgProtocol* tolua_ret = (gamer::protocol::PlayerMsgProtocol*)  Mtolua_new((gamer::protocol::PlayerMsgProtocol)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"gamer::protocol::PlayerMsgProtocol");
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

/* method: new_local of class  gamer::protocol::PlayerMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_player_msg_protocol_gamer_protocol_PlayerMsgProtocol_new00_local
static int tolua_player_msg_protocol_gamer_protocol_PlayerMsgProtocol_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"gamer::protocol::PlayerMsgProtocol",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   gamer::protocol::PlayerMsgProtocol* tolua_ret = (gamer::protocol::PlayerMsgProtocol*)  Mtolua_new((gamer::protocol::PlayerMsgProtocol)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"gamer::protocol::PlayerMsgProtocol");
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

/* method: ByteSize of class  gamer::protocol::PlayerMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_player_msg_protocol_gamer_protocol_PlayerMsgProtocol_ByteSize00
static int tolua_player_msg_protocol_gamer_protocol_PlayerMsgProtocol_ByteSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const gamer::protocol::PlayerMsgProtocol",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const gamer::protocol::PlayerMsgProtocol* self = (const gamer::protocol::PlayerMsgProtocol*)  tolua_tousertype(tolua_S,1,0);
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

/* method: player_id of class  gamer::protocol::PlayerMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_player_msg_protocol_gamer_protocol_PlayerMsgProtocol_player_id00
static int tolua_player_msg_protocol_gamer_protocol_PlayerMsgProtocol_player_id00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const gamer::protocol::PlayerMsgProtocol",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const gamer::protocol::PlayerMsgProtocol* self = (const gamer::protocol::PlayerMsgProtocol*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'player_id'", NULL);
#endif
  {
  ::google::protobuf::uint32 tolua_ret = (::google::protobuf::uint32)  self->player_id();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((::google::protobuf::uint32)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"::google::protobuf::uint32");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(::google::protobuf::uint32));
     tolua_pushusertype(tolua_S,tolua_obj,"::google::protobuf::uint32");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'player_id'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: nick_name of class  gamer::protocol::PlayerMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_player_msg_protocol_gamer_protocol_PlayerMsgProtocol_nick_name00
static int tolua_player_msg_protocol_gamer_protocol_PlayerMsgProtocol_nick_name00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const gamer::protocol::PlayerMsgProtocol",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const gamer::protocol::PlayerMsgProtocol* self = (const gamer::protocol::PlayerMsgProtocol*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'nick_name'", NULL);
#endif
  {
   const std::string tolua_ret = (const std::string)  self->nick_name();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'nick_name'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: level of class  gamer::protocol::PlayerMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_player_msg_protocol_gamer_protocol_PlayerMsgProtocol_level00
static int tolua_player_msg_protocol_gamer_protocol_PlayerMsgProtocol_level00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const gamer::protocol::PlayerMsgProtocol",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const gamer::protocol::PlayerMsgProtocol* self = (const gamer::protocol::PlayerMsgProtocol*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'level'", NULL);
#endif
  {
  ::google::protobuf::uint32 tolua_ret = (::google::protobuf::uint32)  self->level();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((::google::protobuf::uint32)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"::google::protobuf::uint32");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(::google::protobuf::uint32));
     tolua_pushusertype(tolua_S,tolua_obj,"::google::protobuf::uint32");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'level'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: level_name of class  gamer::protocol::PlayerMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_player_msg_protocol_gamer_protocol_PlayerMsgProtocol_level_name00
static int tolua_player_msg_protocol_gamer_protocol_PlayerMsgProtocol_level_name00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const gamer::protocol::PlayerMsgProtocol",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const gamer::protocol::PlayerMsgProtocol* self = (const gamer::protocol::PlayerMsgProtocol*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'level_name'", NULL);
#endif
  {
   const std::string tolua_ret = (const std::string)  self->level_name();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'level_name'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: score_gold of class  gamer::protocol::PlayerMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_player_msg_protocol_gamer_protocol_PlayerMsgProtocol_score_gold00
static int tolua_player_msg_protocol_gamer_protocol_PlayerMsgProtocol_score_gold00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const gamer::protocol::PlayerMsgProtocol",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const gamer::protocol::PlayerMsgProtocol* self = (const gamer::protocol::PlayerMsgProtocol*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'score_gold'", NULL);
#endif
  {
  ::google::protobuf::uint32 tolua_ret = (::google::protobuf::uint32)  self->score_gold();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((::google::protobuf::uint32)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"::google::protobuf::uint32");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(::google::protobuf::uint32));
     tolua_pushusertype(tolua_S,tolua_obj,"::google::protobuf::uint32");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'score_gold'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: score_diamond of class  gamer::protocol::PlayerMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_player_msg_protocol_gamer_protocol_PlayerMsgProtocol_score_diamond00
static int tolua_player_msg_protocol_gamer_protocol_PlayerMsgProtocol_score_diamond00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const gamer::protocol::PlayerMsgProtocol",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const gamer::protocol::PlayerMsgProtocol* self = (const gamer::protocol::PlayerMsgProtocol*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'score_diamond'", NULL);
#endif
  {
  ::google::protobuf::uint32 tolua_ret = (::google::protobuf::uint32)  self->score_diamond();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((::google::protobuf::uint32)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"::google::protobuf::uint32");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(::google::protobuf::uint32));
     tolua_pushusertype(tolua_S,tolua_obj,"::google::protobuf::uint32");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'score_diamond'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: num_room_cards of class  gamer::protocol::PlayerMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_player_msg_protocol_gamer_protocol_PlayerMsgProtocol_num_room_cards00
static int tolua_player_msg_protocol_gamer_protocol_PlayerMsgProtocol_num_room_cards00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const gamer::protocol::PlayerMsgProtocol",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const gamer::protocol::PlayerMsgProtocol* self = (const gamer::protocol::PlayerMsgProtocol*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'num_room_cards'", NULL);
#endif
  {
  ::google::protobuf::uint32 tolua_ret = (::google::protobuf::uint32)  self->num_room_cards();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((::google::protobuf::uint32)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"::google::protobuf::uint32");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(::google::protobuf::uint32));
     tolua_pushusertype(tolua_S,tolua_obj,"::google::protobuf::uint32");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'num_room_cards'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: num_played_games of class  gamer::protocol::PlayerMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_player_msg_protocol_gamer_protocol_PlayerMsgProtocol_num_played_games00
static int tolua_player_msg_protocol_gamer_protocol_PlayerMsgProtocol_num_played_games00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const gamer::protocol::PlayerMsgProtocol",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const gamer::protocol::PlayerMsgProtocol* self = (const gamer::protocol::PlayerMsgProtocol*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'num_played_games'", NULL);
#endif
  {
  ::google::protobuf::uint32 tolua_ret = (::google::protobuf::uint32)  self->num_played_games();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((::google::protobuf::uint32)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"::google::protobuf::uint32");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(::google::protobuf::uint32));
     tolua_pushusertype(tolua_S,tolua_obj,"::google::protobuf::uint32");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'num_played_games'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: num_win_games of class  gamer::protocol::PlayerMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_player_msg_protocol_gamer_protocol_PlayerMsgProtocol_num_win_games00
static int tolua_player_msg_protocol_gamer_protocol_PlayerMsgProtocol_num_win_games00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const gamer::protocol::PlayerMsgProtocol",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const gamer::protocol::PlayerMsgProtocol* self = (const gamer::protocol::PlayerMsgProtocol*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'num_win_games'", NULL);
#endif
  {
  ::google::protobuf::uint32 tolua_ret = (::google::protobuf::uint32)  self->num_win_games();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((::google::protobuf::uint32)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"::google::protobuf::uint32");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(::google::protobuf::uint32));
     tolua_pushusertype(tolua_S,tolua_obj,"::google::protobuf::uint32");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'num_win_games'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_player_msg_protocol_open (lua_State* tolua_S)
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
    tolua_cclass(tolua_S,"PlayerMsgProtocol","gamer::protocol::PlayerMsgProtocol","google::protobuf::Message",tolua_collect_gamer__protocol__PlayerMsgProtocol);
    #else
    tolua_cclass(tolua_S,"PlayerMsgProtocol","gamer::protocol::PlayerMsgProtocol","google::protobuf::Message",NULL);
    #endif
    tolua_beginmodule(tolua_S,"PlayerMsgProtocol");
     tolua_function(tolua_S,"new",tolua_player_msg_protocol_gamer_protocol_PlayerMsgProtocol_new00);
     tolua_function(tolua_S,"new_local",tolua_player_msg_protocol_gamer_protocol_PlayerMsgProtocol_new00_local);
     tolua_function(tolua_S,".call",tolua_player_msg_protocol_gamer_protocol_PlayerMsgProtocol_new00_local);
     tolua_function(tolua_S,"ByteSize",tolua_player_msg_protocol_gamer_protocol_PlayerMsgProtocol_ByteSize00);
     tolua_function(tolua_S,"player_id",tolua_player_msg_protocol_gamer_protocol_PlayerMsgProtocol_player_id00);
     tolua_function(tolua_S,"nick_name",tolua_player_msg_protocol_gamer_protocol_PlayerMsgProtocol_nick_name00);
     tolua_function(tolua_S,"level",tolua_player_msg_protocol_gamer_protocol_PlayerMsgProtocol_level00);
     tolua_function(tolua_S,"level_name",tolua_player_msg_protocol_gamer_protocol_PlayerMsgProtocol_level_name00);
     tolua_function(tolua_S,"score_gold",tolua_player_msg_protocol_gamer_protocol_PlayerMsgProtocol_score_gold00);
     tolua_function(tolua_S,"score_diamond",tolua_player_msg_protocol_gamer_protocol_PlayerMsgProtocol_score_diamond00);
     tolua_function(tolua_S,"num_room_cards",tolua_player_msg_protocol_gamer_protocol_PlayerMsgProtocol_num_room_cards00);
     tolua_function(tolua_S,"num_played_games",tolua_player_msg_protocol_gamer_protocol_PlayerMsgProtocol_num_played_games00);
     tolua_function(tolua_S,"num_win_games",tolua_player_msg_protocol_gamer_protocol_PlayerMsgProtocol_num_win_games00);
    tolua_endmodule(tolua_S);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_player_msg_protocol (lua_State* tolua_S) {
 return tolua_player_msg_protocol_open(tolua_S);
};
#endif


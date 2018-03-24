/*
** Lua binding: ting_card_msg_protocol
** Generated automatically by tolua++-1.0.92 on 11/05/17 13:15:24.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_ting_card_msg_protocol_open (lua_State* tolua_S);

#include "msg/protocol/ting_card_msg_protocol.pb.h"
#include <string>
#include <google/protobuf/stubs/common.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/unknown_field_set.h>

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_gamer__protocol__TingCardMsgProtocol (lua_State* tolua_S)
{
 gamer::protocol::TingCardMsgProtocol* self = (gamer::protocol::TingCardMsgProtocol*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"google::protobuf::Message");
 tolua_usertype(tolua_S,"gamer::protocol::TingCardMsgProtocol");
}

/* method: new of class  gamer::protocol::TingCardMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_ting_card_msg_protocol_gamer_protocol_TingCardMsgProtocol_new00
static int tolua_ting_card_msg_protocol_gamer_protocol_TingCardMsgProtocol_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"gamer::protocol::TingCardMsgProtocol",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   gamer::protocol::TingCardMsgProtocol* tolua_ret = (gamer::protocol::TingCardMsgProtocol*)  Mtolua_new((gamer::protocol::TingCardMsgProtocol)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"gamer::protocol::TingCardMsgProtocol");
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

/* method: new_local of class  gamer::protocol::TingCardMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_ting_card_msg_protocol_gamer_protocol_TingCardMsgProtocol_new00_local
static int tolua_ting_card_msg_protocol_gamer_protocol_TingCardMsgProtocol_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"gamer::protocol::TingCardMsgProtocol",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   gamer::protocol::TingCardMsgProtocol* tolua_ret = (gamer::protocol::TingCardMsgProtocol*)  Mtolua_new((gamer::protocol::TingCardMsgProtocol)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"gamer::protocol::TingCardMsgProtocol");
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

/* method: ByteSize of class  gamer::protocol::TingCardMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_ting_card_msg_protocol_gamer_protocol_TingCardMsgProtocol_ByteSize00
static int tolua_ting_card_msg_protocol_gamer_protocol_TingCardMsgProtocol_ByteSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const gamer::protocol::TingCardMsgProtocol",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const gamer::protocol::TingCardMsgProtocol* self = (const gamer::protocol::TingCardMsgProtocol*)  tolua_tousertype(tolua_S,1,0);
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

/* method: cards_of_ting_size of class  gamer::protocol::TingCardMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_ting_card_msg_protocol_gamer_protocol_TingCardMsgProtocol_cards_of_ting_size00
static int tolua_ting_card_msg_protocol_gamer_protocol_TingCardMsgProtocol_cards_of_ting_size00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const gamer::protocol::TingCardMsgProtocol",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const gamer::protocol::TingCardMsgProtocol* self = (const gamer::protocol::TingCardMsgProtocol*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'cards_of_ting_size'", NULL);
#endif
  {
   int tolua_ret = (int)  self->cards_of_ting_size();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'cards_of_ting_size'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: cards_of_ting of class  gamer::protocol::TingCardMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_ting_card_msg_protocol_gamer_protocol_TingCardMsgProtocol_cards_of_ting00
static int tolua_ting_card_msg_protocol_gamer_protocol_TingCardMsgProtocol_cards_of_ting00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const gamer::protocol::TingCardMsgProtocol",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const gamer::protocol::TingCardMsgProtocol* self = (const gamer::protocol::TingCardMsgProtocol*)  tolua_tousertype(tolua_S,1,0);
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'cards_of_ting'", NULL);
#endif
  {
   unsigned int tolua_ret = (unsigned int)  self->cards_of_ting(index);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'cards_of_ting'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: discard of class  gamer::protocol::TingCardMsgProtocol */
#ifndef TOLUA_DISABLE_tolua_ting_card_msg_protocol_gamer_protocol_TingCardMsgProtocol_discard00
static int tolua_ting_card_msg_protocol_gamer_protocol_TingCardMsgProtocol_discard00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const gamer::protocol::TingCardMsgProtocol",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const gamer::protocol::TingCardMsgProtocol* self = (const gamer::protocol::TingCardMsgProtocol*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'discard'", NULL);
#endif
  {
   unsigned int tolua_ret = (unsigned int)  self->discard();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'discard'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_ting_card_msg_protocol_open (lua_State* tolua_S)
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
    tolua_cclass(tolua_S,"TingCardMsgProtocol","gamer::protocol::TingCardMsgProtocol","google::protobuf::Message",tolua_collect_gamer__protocol__TingCardMsgProtocol);
    #else
    tolua_cclass(tolua_S,"TingCardMsgProtocol","gamer::protocol::TingCardMsgProtocol","google::protobuf::Message",NULL);
    #endif
    tolua_beginmodule(tolua_S,"TingCardMsgProtocol");
     tolua_function(tolua_S,"new",tolua_ting_card_msg_protocol_gamer_protocol_TingCardMsgProtocol_new00);
     tolua_function(tolua_S,"new_local",tolua_ting_card_msg_protocol_gamer_protocol_TingCardMsgProtocol_new00_local);
     tolua_function(tolua_S,".call",tolua_ting_card_msg_protocol_gamer_protocol_TingCardMsgProtocol_new00_local);
     tolua_function(tolua_S,"ByteSize",tolua_ting_card_msg_protocol_gamer_protocol_TingCardMsgProtocol_ByteSize00);
     tolua_function(tolua_S,"cards_of_ting_size",tolua_ting_card_msg_protocol_gamer_protocol_TingCardMsgProtocol_cards_of_ting_size00);
     tolua_function(tolua_S,"cards_of_ting",tolua_ting_card_msg_protocol_gamer_protocol_TingCardMsgProtocol_cards_of_ting00);
     tolua_function(tolua_S,"discard",tolua_ting_card_msg_protocol_gamer_protocol_TingCardMsgProtocol_discard00);
    tolua_endmodule(tolua_S);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_ting_card_msg_protocol (lua_State* tolua_S) {
 return tolua_ting_card_msg_protocol_open(tolua_S);
};
#endif


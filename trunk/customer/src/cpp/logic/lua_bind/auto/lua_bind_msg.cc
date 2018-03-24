/*
** Lua binding: msg
** Generated automatically by tolua++-1.0.92 on 06/10/17 01:12:26.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_msg_open (lua_State* tolua_S);

#include "msg.h"
#include <functional>
#include "macros.h"

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_gamer__ClientMsg (lua_State* tolua_S)
{
 gamer::ClientMsg* self = (gamer::ClientMsg*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_gamer__ServerMsg (lua_State* tolua_S)
{
 gamer::ServerMsg* self = (gamer::ServerMsg*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"gamer::ClientMsg");
 tolua_usertype(tolua_S,"gamer::ServerMsg");
}

/* method: new of class  gamer::ClientMsg */
#ifndef TOLUA_DISABLE_tolua_msg_gamer_ClientMsg_new00
static int tolua_msg_gamer_ClientMsg_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"gamer::ClientMsg",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   gamer::ClientMsg* tolua_ret = (gamer::ClientMsg*)  Mtolua_new((gamer::ClientMsg)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"gamer::ClientMsg");
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

/* method: new_local of class  gamer::ClientMsg */
#ifndef TOLUA_DISABLE_tolua_msg_gamer_ClientMsg_new00_local
static int tolua_msg_gamer_ClientMsg_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"gamer::ClientMsg",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   gamer::ClientMsg* tolua_ret = (gamer::ClientMsg*)  Mtolua_new((gamer::ClientMsg)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"gamer::ClientMsg");
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

/* get function: total_len of class  gamer::ClientMsg */
#ifndef TOLUA_DISABLE_tolua_get_gamer__ClientMsg_unsigned_total_len
static int tolua_get_gamer__ClientMsg_unsigned_total_len(lua_State* tolua_S)
{
  gamer::ClientMsg* self = (gamer::ClientMsg*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'total_len'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->total_len);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: total_len of class  gamer::ClientMsg */
#ifndef TOLUA_DISABLE_tolua_set_gamer__ClientMsg_unsigned_total_len
static int tolua_set_gamer__ClientMsg_unsigned_total_len(lua_State* tolua_S)
{
  gamer::ClientMsg* self = (gamer::ClientMsg*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'total_len'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->total_len = (( unsigned int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: type of class  gamer::ClientMsg */
#ifndef TOLUA_DISABLE_tolua_get_gamer__ClientMsg_unsigned_type
static int tolua_get_gamer__ClientMsg_unsigned_type(lua_State* tolua_S)
{
  gamer::ClientMsg* self = (gamer::ClientMsg*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'type'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->type);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: type of class  gamer::ClientMsg */
#ifndef TOLUA_DISABLE_tolua_set_gamer__ClientMsg_unsigned_type
static int tolua_set_gamer__ClientMsg_unsigned_type(lua_State* tolua_S)
{
  gamer::ClientMsg* self = (gamer::ClientMsg*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'type'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->type = (( unsigned int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: id of class  gamer::ClientMsg */
#ifndef TOLUA_DISABLE_tolua_get_gamer__ClientMsg_unsigned_id
static int tolua_get_gamer__ClientMsg_unsigned_id(lua_State* tolua_S)
{
  gamer::ClientMsg* self = (gamer::ClientMsg*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'id'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->id);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: id of class  gamer::ClientMsg */
#ifndef TOLUA_DISABLE_tolua_set_gamer__ClientMsg_unsigned_id
static int tolua_set_gamer__ClientMsg_unsigned_id(lua_State* tolua_S)
{
  gamer::ClientMsg* self = (gamer::ClientMsg*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'id'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->id = (( unsigned int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: context of class  gamer::ClientMsg */
#ifndef TOLUA_DISABLE_tolua_get_gamer__ClientMsg_context
static int tolua_get_gamer__ClientMsg_context(lua_State* tolua_S)
{
  gamer::ClientMsg* self = (gamer::ClientMsg*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'context'",NULL);
#endif
  tolua_pushuserdata(tolua_S,(void*)self->context);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: context of class  gamer::ClientMsg */
#ifndef TOLUA_DISABLE_tolua_set_gamer__ClientMsg_context
static int tolua_set_gamer__ClientMsg_context(lua_State* tolua_S)
{
  gamer::ClientMsg* self = (gamer::ClientMsg*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'context'",NULL);
  if (!tolua_isuserdata(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->context = ((void*)  tolua_touserdata(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  gamer::ServerMsg */
#ifndef TOLUA_DISABLE_tolua_msg_gamer_ServerMsg_new00
static int tolua_msg_gamer_ServerMsg_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"gamer::ServerMsg",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   gamer::ServerMsg* tolua_ret = (gamer::ServerMsg*)  Mtolua_new((gamer::ServerMsg)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"gamer::ServerMsg");
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

/* method: new_local of class  gamer::ServerMsg */
#ifndef TOLUA_DISABLE_tolua_msg_gamer_ServerMsg_new00_local
static int tolua_msg_gamer_ServerMsg_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"gamer::ServerMsg",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   gamer::ServerMsg* tolua_ret = (gamer::ServerMsg*)  Mtolua_new((gamer::ServerMsg)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"gamer::ServerMsg");
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

/* get function: total_len of class  gamer::ServerMsg */
#ifndef TOLUA_DISABLE_tolua_get_gamer__ServerMsg_unsigned_total_len
static int tolua_get_gamer__ServerMsg_unsigned_total_len(lua_State* tolua_S)
{
  gamer::ServerMsg* self = (gamer::ServerMsg*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'total_len'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->total_len);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: total_len of class  gamer::ServerMsg */
#ifndef TOLUA_DISABLE_tolua_set_gamer__ServerMsg_unsigned_total_len
static int tolua_set_gamer__ServerMsg_unsigned_total_len(lua_State* tolua_S)
{
  gamer::ServerMsg* self = (gamer::ServerMsg*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'total_len'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->total_len = (( unsigned int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: type of class  gamer::ServerMsg */
#ifndef TOLUA_DISABLE_tolua_get_gamer__ServerMsg_unsigned_type
static int tolua_get_gamer__ServerMsg_unsigned_type(lua_State* tolua_S)
{
  gamer::ServerMsg* self = (gamer::ServerMsg*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'type'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->type);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: type of class  gamer::ServerMsg */
#ifndef TOLUA_DISABLE_tolua_set_gamer__ServerMsg_unsigned_type
static int tolua_set_gamer__ServerMsg_unsigned_type(lua_State* tolua_S)
{
  gamer::ServerMsg* self = (gamer::ServerMsg*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'type'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->type = (( unsigned int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: id of class  gamer::ServerMsg */
#ifndef TOLUA_DISABLE_tolua_get_gamer__ServerMsg_unsigned_id
static int tolua_get_gamer__ServerMsg_unsigned_id(lua_State* tolua_S)
{
  gamer::ServerMsg* self = (gamer::ServerMsg*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'id'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->id);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: id of class  gamer::ServerMsg */
#ifndef TOLUA_DISABLE_tolua_set_gamer__ServerMsg_unsigned_id
static int tolua_set_gamer__ServerMsg_unsigned_id(lua_State* tolua_S)
{
  gamer::ServerMsg* self = (gamer::ServerMsg*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'id'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->id = (( unsigned int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: code of class  gamer::ServerMsg */
#ifndef TOLUA_DISABLE_tolua_get_gamer__ServerMsg_unsigned_code
static int tolua_get_gamer__ServerMsg_unsigned_code(lua_State* tolua_S)
{
  gamer::ServerMsg* self = (gamer::ServerMsg*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'code'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->code);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: code of class  gamer::ServerMsg */
#ifndef TOLUA_DISABLE_tolua_set_gamer__ServerMsg_unsigned_code
static int tolua_set_gamer__ServerMsg_unsigned_code(lua_State* tolua_S)
{
  gamer::ServerMsg* self = (gamer::ServerMsg*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'code'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->code = (( unsigned int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: context of class  gamer::ServerMsg */
#ifndef TOLUA_DISABLE_tolua_get_gamer__ServerMsg_context
static int tolua_get_gamer__ServerMsg_context(lua_State* tolua_S)
{
  gamer::ServerMsg* self = (gamer::ServerMsg*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'context'",NULL);
#endif
  tolua_pushuserdata(tolua_S,(void*)self->context);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: context of class  gamer::ServerMsg */
#ifndef TOLUA_DISABLE_tolua_set_gamer__ServerMsg_context
static int tolua_set_gamer__ServerMsg_context(lua_State* tolua_S)
{
  gamer::ServerMsg* self = (gamer::ServerMsg*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'context'",NULL);
  if (!tolua_isuserdata(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->context = ((void*)  tolua_touserdata(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* function: gamer::client_msg_header_len */
#ifndef TOLUA_DISABLE_tolua_msg_gamer_client_msg_header_len00
static int tolua_msg_gamer_client_msg_header_len00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   unsigned const int tolua_ret = (unsigned const int)  gamer::client_msg_header_len();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'client_msg_header_len'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: gamer::server_msg_header_len */
#ifndef TOLUA_DISABLE_tolua_msg_gamer_server_msg_header_len00
static int tolua_msg_gamer_server_msg_header_len00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
    unsigned const int tolua_ret = (unsigned const int)  gamer::server_msg_header_len();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'server_msg_header_len'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_msg_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  tolua_module(tolua_S,"gamer",0);
  tolua_beginmodule(tolua_S,"gamer");
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"ClientMsg","gamer::ClientMsg","",tolua_collect_gamer__ClientMsg);
   #else
   tolua_cclass(tolua_S,"ClientMsg","gamer::ClientMsg","",NULL);
   #endif
   tolua_beginmodule(tolua_S,"ClientMsg");
    tolua_function(tolua_S,"new",tolua_msg_gamer_ClientMsg_new00);
    tolua_function(tolua_S,"new_local",tolua_msg_gamer_ClientMsg_new00_local);
    tolua_function(tolua_S,".call",tolua_msg_gamer_ClientMsg_new00_local);
    tolua_variable(tolua_S,"total_len",tolua_get_gamer__ClientMsg_unsigned_total_len,tolua_set_gamer__ClientMsg_unsigned_total_len);
    tolua_variable(tolua_S,"type",tolua_get_gamer__ClientMsg_unsigned_type,tolua_set_gamer__ClientMsg_unsigned_type);
    tolua_variable(tolua_S,"id",tolua_get_gamer__ClientMsg_unsigned_id,tolua_set_gamer__ClientMsg_unsigned_id);
    tolua_variable(tolua_S,"context",tolua_get_gamer__ClientMsg_context,tolua_set_gamer__ClientMsg_context);
   tolua_endmodule(tolua_S);
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"ServerMsg","gamer::ServerMsg","",tolua_collect_gamer__ServerMsg);
   #else
   tolua_cclass(tolua_S,"ServerMsg","gamer::ServerMsg","",NULL);
   #endif
   tolua_beginmodule(tolua_S,"ServerMsg");
    tolua_function(tolua_S,"new",tolua_msg_gamer_ServerMsg_new00);
    tolua_function(tolua_S,"new_local",tolua_msg_gamer_ServerMsg_new00_local);
    tolua_function(tolua_S,".call",tolua_msg_gamer_ServerMsg_new00_local);
    tolua_variable(tolua_S,"total_len",tolua_get_gamer__ServerMsg_unsigned_total_len,tolua_set_gamer__ServerMsg_unsigned_total_len);
    tolua_variable(tolua_S,"type",tolua_get_gamer__ServerMsg_unsigned_type,tolua_set_gamer__ServerMsg_unsigned_type);
    tolua_variable(tolua_S,"id",tolua_get_gamer__ServerMsg_unsigned_id,tolua_set_gamer__ServerMsg_unsigned_id);
    tolua_variable(tolua_S,"code",tolua_get_gamer__ServerMsg_unsigned_code,tolua_set_gamer__ServerMsg_unsigned_code);
    tolua_variable(tolua_S,"context",tolua_get_gamer__ServerMsg_context,tolua_set_gamer__ServerMsg_context);
   tolua_endmodule(tolua_S);
   tolua_function(tolua_S,"client_msg_header_len",tolua_msg_gamer_client_msg_header_len00);
   tolua_function(tolua_S,"server_msg_header_len",tolua_msg_gamer_server_msg_header_len00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_msg (lua_State* tolua_S) {
 return tolua_msg_open(tolua_S);
};
#endif


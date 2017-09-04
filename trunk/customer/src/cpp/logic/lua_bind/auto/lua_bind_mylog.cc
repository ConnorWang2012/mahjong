/*
** Lua binding: mylog
** Generated automatically by tolua++-1.0.92 on 09/04/17 18:43:04.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_mylog_open (lua_State* tolua_S);

#include "log/mylog.h"

/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
}

/* function: gamer::writelog */
#ifndef TOLUA_DISABLE_tolua_mylog_gamer_writelog00
static int tolua_mylog_gamer_writelog00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_iscppstring(tolua_S,1,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const std::string s = ((const std::string)  tolua_tocppstring(tolua_S,1,0));
  {
   gamer::writelog(s);
   tolua_pushcppstring(tolua_S,(const char*)s);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'writelog'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_mylog_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  tolua_module(tolua_S,"gamer",0);
  tolua_beginmodule(tolua_S,"gamer");
   tolua_function(tolua_S,"writelog",tolua_mylog_gamer_writelog00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_mylog (lua_State* tolua_S) {
 return tolua_mylog_open(tolua_S);
};
#endif


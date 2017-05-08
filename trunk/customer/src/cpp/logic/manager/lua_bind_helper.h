/*******************************************************************************
  @ copyright(C), 2015-2020, ConnorAndHisFriendsCompany.Inc
  @ filename:	  lua_bind_helper.cc
  @ author:		  Connor
  @ version:	  1.0.0
  @ date:		  2015-02-19
  @ description:  offer function to help to bind c++ to lua.
  @ others:  
  @ history: 
     1.date:
       author:
       modification:
********************************************************************************/

#ifndef CONNOR_GAME_SRC_LUA_BIND_HELPER_H_
#define CONNOR_GAME_SRC_LUA_BIND_HELPER_H_

#include <string>
extern "C" 
{
    #include "lua.h"
    #include "lualib.h"
    #include "lauxlib.h"
}

namespace gamer {

class Event;

class LuaBindHelper {
  public:
    virtual ~LuaBindHelper();

    static LuaBindHelper* getInstance();

    static void destoryInstance();

    void setLuaState(lua_State* L);

    // @return  :   if store success, return lua function id, else return empty string.
    const std::string storeLuaFunction(lua_State* L, int idx);

    void dispatchEvent(const std::string& event_listener_id, Event* event);

    inline lua_State* lua_state() {
        return lua_state_;
    }

  private:
    LuaBindHelper();

    bool init(lua_State* L);

    void closeLuaState();

    std::string createLuaFunctionID();    

    void pushEvent(Event* event);

    bool getLuaFunction(const std::string& function_id);

    void callLuaFunction(int nargs, int nresults);

    //LuaBindHelper* s_lua_bind_helper_;
    lua_State* lua_state_;
    int lua_function_id_;
};

} // namespace gamer

#endif // CONNOR_GAME_SRC_LUA_BIND_HELPER_H_
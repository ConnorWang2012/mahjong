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
#include <unordered_set>

extern "C" 
{
    #include "lua.h"
    #include "lualib.h"
    #include "lauxlib.h"
}

#include <google/protobuf/message.h>

#include "macros.h"
#include "msg.h"

//namespace gamer
//{
//    namespace protobuf
//    {
//        class Message;
//    }
//}

namespace gamer 
{

class Event;

class LuaBindHelper 
{
  public:
    virtual ~LuaBindHelper();

    static LuaBindHelper* getInstance();

    void storeLuaFunction(int idx);

	void storeLuaFunction(const std::string& funtion_id, int idx);

    void callLuaFunction(LuaFunction lua_func, void* userdata);

    void dispatchMsg(LuaFunction lua_func, 
                     int code,
                     msg_header_t msg_type,
                     msg_header_t msg_id, 
                     const google::protobuf::Message* msg,
                     const std::string& msg_class);

	void dispatchMsg(const std::string& funtion_id,
		             int code,
		             msg_header_t msg_type,
		             msg_header_t msg_id,
		             const google::protobuf::Message* msg,
		             const std::string& msg_class);

    void set_lua_state(lua_State* L) { lua_state_ = L; }

    inline lua_State* lua_state() { return lua_state_; }

    void register_lua_bind_modules();

  private:
    LuaBindHelper();

    bool init(lua_State* L);

    void closeLuaState();

    void callLuaFunction(int nargs, int nresults);

    lua_State* lua_state_;

    std::unordered_set<LuaFunction> lua_functions_;
	//std::unordered_set<LuaFunction> lua_functions2_;
};

} // namespace gamer

#endif // CONNOR_GAME_SRC_LUA_BIND_HELPER_H_

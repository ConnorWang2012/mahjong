/*******************************************************************************
  @ copyright(C), 2015-2020, ConnorAndHisFriendsCompany.Inc
  @ filename:	  lua_bind_helper.cc
  @ author:		  Connor
  @ version:	  1.0.0
  @ date:		  2015-02-19
  @ description:  see the header file.
  @ others:  
  @ history: 
     1.date:
       author:
       modification:
********************************************************************************/

#include "lua_bind_helper.h"

#include "lua_bind_register.h"
#include "tolua++.h"
#include "macros.h"
#include "msg/protocol/my_login_msg_protocol.pb.h"

namespace gamer {

LuaBindHelper::LuaBindHelper()
{
}

LuaBindHelper::~LuaBindHelper()
{
    //this->closeLuaState();
    //this->destoryInstance();
}

LuaBindHelper* LuaBindHelper::getInstance()
{
    static LuaBindHelper s_lua_bind_helper_;
    return &s_lua_bind_helper_;
}

void LuaBindHelper::storeLuaFunction(int idx)
{
    if ( !lua_isfunction(lua_state_, idx) )
    {
        printf("[LuaBindHelper::storeLuaFunction] not a function\n");
        return;
    }

    LuaFunction func = (int)tolua_tonumber(lua_state_, idx, 0);
    lua_functions_.insert(func);

    char buf[10] = { 0 };
    snprintf(buf, sizeof(buf), "%d", func);

    lua_pushstring(lua_state_, buf);
    lua_pushvalue(lua_state_, idx);
    lua_rawset(lua_state_, LUA_REGISTRYINDEX);
}

void LuaBindHelper::callLuaFunction(LuaFunction lua_func, void* userdata)
{
    auto itr = lua_functions_.find(lua_func);
    if (itr == lua_functions_.end())
    {
        printf("[LuaBindHelper::callLuaFunction] lua function : %d  not found.\n", lua_func);
        return;
    }

    char buf[10] = { 0 };
    snprintf(buf, sizeof(buf), "%d", *itr);
    lua_pushstring(lua_state_, buf);
    
    lua_rawget(lua_state_, LUA_REGISTRYINDEX);

    auto proto = static_cast<gamer::protocol::MyLoginMsgProtocol*>(userdata);
    //tolua_pushuserdata(lua_state_, userdata);
    tolua_pushusertype(lua_state_, (void*)proto, "gamer::protocol::MyLoginMsgProtocol");

    //lua_newtable(lua_state_);
    //lua_pushstring(lua_state_, "mydata");
    //lua_pushnumber(lua_state_, 666);
    //lua_settable(lua_state_, -3);

    lua_pcall(lua_state_, 1, 0, 0);
}

void LuaBindHelper::register_lua_bind_modules()
{
    gamer::lua_bind_register(lua_state_);
}

bool LuaBindHelper::init(lua_State* L)
{
    if (nullptr == L)
    {
        lua_state_ = lua_open();
    }
    else
    {
        lua_state_ = L;
    }

    luaL_openlibs(lua_state_);

    return true;
}

void LuaBindHelper::closeLuaState()
{
    if (nullptr != lua_state_)
    {
        lua_close(lua_state_);
    }
}

void LuaBindHelper::callLuaFunction(int nargs, int nresults)
{
    int error = lua_pcall(lua_state_, nargs, nresults, 0);
    if (error)
    {
        printf("[callLuaFunction] lua_pcall error : %d\n", error);
    }
}

} // namespace gamer
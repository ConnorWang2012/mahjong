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
#include "tolua++.h"
#include "macros.h"

namespace gamer {

LuaBindHelper::LuaBindHelper()
    :lua_function_id_(1000)
{
}

LuaBindHelper::~LuaBindHelper()
{
    closeLuaState();
    destoryInstance();
}

LuaBindHelper* LuaBindHelper::getInstance()
{
    static LuaBindHelper* lua_bind_helper = nullptr;
    if (nullptr == lua_bind_helper)
    {
        //printf("nullptr == lua_bind_helper\n");
        lua_bind_helper = new LuaBindHelper();
        if ( !lua_bind_helper->init(nullptr) )
        {
            SAFE_DELETE(lua_bind_helper); 
        }
    }
    return lua_bind_helper;
}

void LuaBindHelper::destoryInstance()
{
    LuaBindHelper* lua_bind_helper = getInstance();
    SAFE_DELETE(lua_bind_helper);
}

void LuaBindHelper::setLuaState(lua_State* L)
{
    if (nullptr == L)
        return;
    
    lua_state_ = L;

    //closeLuaState();
    //init(L);
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

const std::string LuaBindHelper::storeLuaFunction(lua_State* L, int idx)
{
    if ( !lua_isfunction(L, idx) )
    {
        printf("[storeLuaFunction] not a function\n");
        return "";
    }
    std::string func_id = createLuaFunctionID();
    //printf("[storeLuaFunction] func_id : %s\n", func_id.c_str());
    lua_pushstring(L, func_id.c_str());
    lua_pushvalue(L, idx); 
    //lua_settable(L, LUA_REGISTRYINDEX);
    lua_rawset(L, LUA_REGISTRYINDEX);
    return func_id;
}

void LuaBindHelper::dispatchEvent(const std::string& event_listener_id, Event* event)
{
    //printf("[dispatchEvent] event_listener_id : %s\n", event_listener_id.c_str());
    if ( !getLuaFunction(event_listener_id) )
    {
        printf("[dispatchEvent] lua function not found.function_id : %s\n", event_listener_id.c_str());
        return;
    }
    pushEvent(event);
    callLuaFunction(1, 0);
}

void LuaBindHelper::closeLuaState()
{
    if (nullptr != lua_state_)
    {
        lua_close(lua_state_);
    }
}

std::string LuaBindHelper::createLuaFunctionID()
{
    //return std::to_string(++lua_function_id_); // android build not pass£¨NDK(r9d)£©
    char buf[20] = {0};
    
#if GAMER_PLATFORM == GAMER_PLATFORM_WIN32
    sprintf_s(buf, "%d", ++lua_function_id_);
#elif GAMER_PLATFORM == GAMER_PLATFORM_IOS
    sprintf(buf, "%d", ++lua_function_id_);
#elif GAMER_PLATFORM == GAMER_PLATFORM_ANDROID
    sprintf(buf, "%d", ++lua_function_id_);
#endif
    
    return std::string(buf);
}

void LuaBindHelper::pushEvent(Event* event)
{
    tolua_pushuserdata(lua_state_, event);
}

bool LuaBindHelper::getLuaFunction(const std::string& function_id)
{
    if ("" == function_id)
    {
        printf("[callLuaFunction] "" == function_id\n");
        return false;
    }
    lua_pushstring(lua_state_, function_id.c_str());
    //lua_gettable(L, LUA_REGISTRYINDEX);
    lua_rawget(lua_state_, LUA_REGISTRYINDEX);
    return true;
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
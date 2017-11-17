/*******************************************************************************
  @ copyright(C), 2015-2020, ConnorAndHisFriendsCompany.Inc
  @ filename:	  event_listener.cc
  @ author:		  Connor
  @ version:	  1.0.0
  @ date:		  2015-01-18
  @ description:  see the header file.
  @ others:  
  @ history: 
     1.date:
       author:
       modification:
********************************************************************************/

#include "event_listener.h"

#include <cassert>
#include <stdint.h>

#include "event_constants.h"
#include "lua_bind_helper.h"
#include "macros.h"

namespace gamer {

EventListener::EventListener()
{
    this->init();
}

EventListener::~EventListener()
{
}

EventListener* EventListener::create(
    id_t event_id, 
    const EventCallback& event_callback, 
    const std::string& listener_name, 
    int priority)
{
	EventListener* listener = new EventListener();
	if (listener && listener->init(event_id, 
                                   event_callback, 
                                   listener_name, 
                                   priority))
	{
		return listener;
	}
	SAFE_DELETE(listener);
	return nullptr;
}

EventListener* EventListener::create(id_t event_id, 
                                     LuaFunction event_callback,
                                     const std::string& listener_name,
                                     int priority)
{
    EventListener* listener = new EventListener();
    if (listener && listener->init(event_id, event_callback, listener_name, priority))
    {
        listener->is_lua_function_ = true;
        return listener;
    }
    SAFE_DELETE(listener);
    return nullptr;
}

void EventListener::executeCallback(const Event& event)
{
    if (nullptr != event_callback_)
    {
        event_callback_(event);
    }
}

bool EventListener::checkValidity() const
{
    id_t event_id = this->event_id();
    if (this->is_lua_function()) 
    {
        return 0 < event_id && 0 <= this->lua_function();
    }
    return 0 < event_id && (nullptr != event_callback_ || nullptr != cmd_callback_); 
}

EventListener* EventListener::createCmdListener(id_t event_id,
                                     const CommandCallback& cmd_callback, 
                                     const std::string& listener_name, 
                                     int priority )
{
    EventListener* listener = new EventListener();
    if (listener && listener->init(event_id, cmd_callback, listener_name, priority))
    {
        return listener;
    }
    SAFE_DELETE(listener);
    return nullptr;
}

void EventListener::init()
{
    // ugly, TODO : in ctor init
    target_id_        = 0;
    listener_name_    = "";
    priority_         = UINT32_MAX;
    is_enabled_       = true;
    is_lua_function_  = false;
    lua_function_     = 0;
    lua_function_id_  = "";
    is_registered_    = false;
}

bool EventListener::init(id_t event_id, 
                         const EventCallback& event_callback, 
                         const std::string& listener_name, 
                         int priority)
{
    assert(nullptr != event_callback);

    this->set_target_id(event_id);
	this->event_callback_ = event_callback;
    this->set_listener_name(listener_name);
    this->set_priority(priority);

	return true;
}

bool EventListener::init(id_t event_id, 
                         LuaFunction event_callback, 
                         const std::string& listener_name, 
                         int priority)
{
    assert(0 < event_id);

    LuaBindHelper::getInstance()->storeLuaFunction(3);

    this->set_lua_function(event_callback);
    this->set_target_id(event_id);
    this->set_listener_name(listener_name);
    this->set_priority(priority);

    return true;
}

bool EventListener::init(id_t event_id, 
                         const CommandCallback& cmd_callback, 
                         const std::string& listener_name, 
                         int priority)
{
    assert(nullptr != cmd_callback);

    this->set_target_id(event_id);
    cmd_callback_ = cmd_callback;
    this->set_listener_name(listener_name);
    this->set_priority(priority);

    return true;
}

} // namespace gamer
﻿/*******************************************************************************
  @ copyright(C), 2015-2020, ConnorAndHisFriendsCompany.Inc
  @ filename:	  event_manager.cc
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

#include "event_manager.h"

#include <cassert>
#include <algorithm>
#include <stdint.h>

#include "command.h"
#include "event_listener.h"
#include "lua_bind_helper.h"
#include "myevent.h"
#include "macros.h"

namespace 
{

class DispatchGuard 
{
public:
	DispatchGuard(int& count)
        :count_(count)
	{
		++count_;
	}

	~DispatchGuard()
	{
		--count_;
	}

private:
	int& count_;
};

} // namespace

namespace gamer
{

EventManager* EventManager::s_shared_event_mgr_ = nullptr;

EventManager::EventManager()
    : dispatch_count_(0),
	  is_enabled_(true),
	  dirty_flag_(DirtyFlag::NONE),
	  dirty_event_id_(0),
	  dirty_event_name_("")
{
}

EventManager::~EventManager()
{
    this->removeAllEventListenersWithCleanup();
}

EventManager* EventManager::getInstance()
{
	if (nullptr == s_shared_event_mgr_)
	{
		s_shared_event_mgr_ = new EventManager();
		if( !s_shared_event_mgr_->init() )
		{
			SAFE_DELETE(s_shared_event_mgr_);
		}
	}
	return s_shared_event_mgr_;
}

void EventManager::destoryInstance()
{
	SAFE_DELETE(s_shared_event_mgr_);
}

void EventManager::addEventListener(EventListener* listener)
{
    if (nullptr == listener || listener->is_registered())
        return;
    assert(false != listener->checkValidity());

    this->addEventListener(listener, listener->priority());
}

void EventManager::dispatch(const Event& event)
{
    assert(false != event.check_event_id());

    if ( !is_enabled_ )
        return;

    DispatchGuard guard(dispatch_count_);

    auto listenerMap = listener_map_.find(event.event_id());
    if (listener_map_.end() != listenerMap)
    {
        auto listeners = listenerMap->second;
        this->dispatchEvent(listeners, event);
    }

    this->updateEventListeners();
}

void EventManager::dispatch(id_t event_id, void* optional_user_data)
{
    assert(event_id > 0);

    if ( !is_enabled_ )
        return;

    DispatchGuard guard(dispatch_count_);

    Event evn(event_id);
    if(nullptr != optional_user_data)
    {
        evn.set_user_data(optional_user_data);
    }

    auto listenerMap = listener_map_.find(event_id);
    if (listener_map_.end() != listenerMap)
    {
        auto listeners = listenerMap->second;
        this->dispatchEvent(listeners, evn);
    }

    this->updateEventListeners();
}

void EventManager::removeEventListener(EventListener* listener)
{
	if (nullptr != listener)
	{
		this->removeEventListenerImpl(listener, false);
	}
}

void EventManager::removeEventListener(const std::string& listener_name)
{
    this->removeEventListenerImpl(listener_name, false);
}

void EventManager::removeEventListenerWithCleanup(EventListener* listener)
{
	if (nullptr != listener)
	{
		this->removeEventListenerImpl(listener, true);
	}
}

void EventManager::removeEventListenerWithCleanup(const std::string& listener_name)
{
    this->removeEventListenerImpl(listener_name, true);
}

void EventManager::removeAllEventListeners()
{
    this->removeAllEventListenersImpl(false);
}

void EventManager::removeAllEventListenersWithCleanup()
{
    this->removeAllEventListenersImpl(true);
}

void EventManager::setPriority(EventListener* listener, int priority)
{
	if (nullptr != listener)
	{
		for (auto it = listener_map_.begin(); it != listener_map_.end(); ++it)
		{
			auto listener_list = it->second;
			if (this->setPriority(listener_list, listener, priority))
			{
				this->set_dirty_flag(DirtyFlag::LISTENER_PRIORITY_CHANGE,
					listener->event_id());
				break;
			}
		}
	}

	//if ( !is_dispatching() )
	//{
	//	updateEventListeners();
	//}
}

bool EventManager::init()
{
    return true;
}

void EventManager::addEventListener(EventListener* listener, int priority)
{
    //assert(nullptr != listener);
    //assert(false != listener->checkValidity());

    if ( !this->is_dispatching() )
    {
        this->addEventListenerImpl(listener, priority);
    }
    else
    {
        listeners_to_add_.push_back(listener);
        this->set_dirty_flag(DirtyFlag::LISTENER_NUM_CHANGE);
    }
}

void EventManager::addEventListenerImpl(EventListener* listener, 
                                        int priority)
{
	auto it = listener_map_.find(listener->event_id());
	if(listener_map_.end() != it)
	{
		auto vecListener = &it->second;
		vecListener->push_back(listener);        

		this->sortEventListeners(vecListener);
	}
	else
	{
		std::vector<EventListener*> vListener(1, listener);
		listener_map_.insert(EventIDListenerMap::value_type(
            listener->event_id(), vListener));
	}	

    listener->set_registered(true);
}

void EventManager::removeEventListenerImpl(EventListener* listener, bool cleanup)
{
    if (this->is_dispatching())
    {
        // TODO:set dirty flag
        return;
    }

    // 1. find listener from id_listener_map_
    for (auto it = listener_map_.begin();it != listener_map_.end();++it)
    {
        auto iter = std::find(it->second.begin(), it->second.end(), listener);
        if (it->second.end() != iter)
        {
            if (cleanup)
            {
                SAFE_DELETE(*iter);
            } 
            else
            {
                ((EventListener*)*iter)->set_registered(false);
            }
            it->second.erase(iter);
            return;
        }
    }

    // 2. find listener from listeners_to_add_vec_
    if ( !listeners_to_add_.empty() )
    {
        std::sort(listeners_to_add_.begin(), listeners_to_add_.end());

        auto iter = std::find(listeners_to_add_.begin(), 
							  listeners_to_add_.end(), 
							  listener);
        if (listeners_to_add_.end() != iter)
        {
            if (cleanup)
            {
                SAFE_DELETE(*iter);
            }
            listeners_to_add_.erase(iter);
            return;
        }
    }
}

void EventManager::removeEventListenerImpl(const std::string& listener_name, 
                                           bool cleanup)
{
    if (this->is_dispatching())
    {
        // TODO:set dirty flag
        return;
    }

    // 1. find listener from id_listener_map_
    for (auto it = listener_map_.begin();it != listener_map_.end();++it)
    {
        auto iter = std::find_if(it->second.begin(), 
            it->second.end(), 
            [&](const EventListener* l)
            {
                return (l->listener_name() == listener_name);
            });

        if (it->second.end() != iter)
        {
            if (cleanup)
            {
                SAFE_DELETE(*iter);
            }
            else
            {
                ((EventListener*)*iter)->set_registered(false);
            }
            it->second.erase(iter);
            return;
        }
    }

    // 2. find listener from listeners_to_add_vec_
    if ( !listeners_to_add_.empty() )
    {
        std::sort(listeners_to_add_.begin(), 
            listeners_to_add_.end());
        auto iter = std::find_if(listeners_to_add_.begin(), 
            listeners_to_add_.end(), 
            [&](const EventListener* l)
            {
                return (l->listener_name() == listener_name);
            });

        if (listeners_to_add_.end() != iter)
        {
            if (cleanup)
            {
                SAFE_DELETE(*iter);
            }
            listeners_to_add_.erase(iter);
            return;
        }
    }
}

void EventManager::removeAllEventListenersImpl(bool cleanup)
{
    if (this->is_dispatching())
    {
        // TODO:set dirty flag
        return;
    }

    bool delete_ok = true;
    for (auto it = listener_map_.begin(); it != listener_map_.end(); ++it)
    {
        auto listeners   = it->second;
        bool all_deleted = true;
        if (cleanup)
        {
            std::for_each (listeners.begin(), 
                           listeners.end(), 
                           [&](EventListener* listener)
                           {
                               if ( !is_dispatching() )
                               {
                                   SAFE_DELETE(listener);
                               }
                               else
                               {
                                   all_deleted = false;
                               }
                           });
        }
        else if ( !this->is_dispatching() )
        {
            std::for_each (listeners.begin(), 
                           listeners.end(), 
                           [&](EventListener* listener)
                           {
                               listener->set_registered(false);
                           });
            listeners.clear();
        }

        if (!all_deleted)
        {
            // TODO:set dirty flag
            delete_ok = false;
        }        
    }

    if (delete_ok)
    {
        listener_map_.clear();
    }
}

void EventManager::sortEventListeners(std::vector<EventListener*>* listeners)
{
	std::sort(listeners->begin(), 
              listeners->end(), 
              [&](const EventListener* l1, 
              const EventListener* l2) 
              {
		          return l1->priority() < l2->priority();
	          });
}

void EventManager::sortEventListeners(id_t event_id)
{
	auto it = listener_map_.find(event_id);
	if (listener_map_.end() != it)
	{
		auto listeners = &it->second;
		this->sortEventListeners(listeners);
	}
}

void EventManager::dispatchEvent(std::vector<EventListener*> listeners, 
                                 const Event& event)
{
    for (auto& l : listeners)
    {
        if (l->is_enabled())
        {
            if (l->is_lua_function())
            {
                LuaBindHelper::getInstance()->callLuaFunction(l->lua_function(), const_cast<Event*>(&event));
            }
            else
            {
                l->event_callback_(event);
            }
        }
    }
}

void EventManager::dispatchComand(Command* cmd)
{
	if (!is_enabled_)
		return;

    assert(nullptr != cmd);
    assert(false != cmd->check_command_id());

    DispatchGuard guard(dispatch_count_);

    auto listenerMap = listener_map_.find(cmd->command_id());
    if (listener_map_.end() != listenerMap)
    {
        auto listeners = listenerMap->second;
        this->dispatchCommandImpl(listeners, cmd);
    }

    this->updateEventListeners();
}

void EventManager::dispatchComand(id_t cmd_id, void* optional_user_data/*= nullptr*/)
{
	if (!is_enabled_)
		return;

    assert(cmd_id > 0);

    DispatchGuard guard(dispatch_count_);

    //Event* evn = Event::Create(event_id);
    Command cmd(cmd_id);
    if(nullptr != optional_user_data)
    {
        //evn->set_user_data(optionalUserData);
        cmd.set_user_data(optional_user_data);
    }

    auto listenerMap = listener_map_.find(cmd_id);
    if (listener_map_.end() != listenerMap)
    {
        auto listeners = listenerMap->second;
        this->dispatchCommandImpl(listeners, &cmd);
    }

    this->updateEventListeners();
}

void EventManager::dispatchCommandImpl(std::vector<EventListener*> listeners, Command* cmd)
{
    for (auto& l : listeners)
    {
        if (l->is_enabled())
        {
            if (l->is_lua_function())
            {
                //LuaBindHelper::getInstance()->dispatchEvent(l->lua_function_id(), event);
                // TODO : imply LuaBindHelper::getInstance()->dispatchCommand(l->lua_function_id(), cmd);
            }
            else
            {
                l->cmd_callback_(cmd);
            }
        }
    }
}

bool EventManager::setPriority(std::vector<EventListener*> listener_list, 
                               EventListener* listener, 
                               int priority)
{
	auto found = std::find(listener_list.begin(), 
                           listener_list.end(), 
                           listener);
	if (listener_list.end() != found)
	{
		listener->set_priority(priority);
		return true;
	}
	return false;
}

void EventManager::updateEventListeners()
{
	if ( !this->is_dirty() )
		return;

	DirtyFlag flag = this->dirty_flag();
	switch (flag)
	{
	case DirtyFlag::NONE:
		break;
	case DirtyFlag::LISTENER_PRIORITY_CHANGE:
		{
			this->sortEventListeners(dirty_event_id_);
		}
		break;
	case DirtyFlag::LISTENER_NUM_CHANGE:
		{
			if ( !listeners_to_add_.empty() )
			{
				for (auto& listener : listeners_to_add_)
				{
					this->addEventListener(listener);
				}
				listeners_to_add_.clear();
			}
		}
		break;
	case DirtyFlag::ALL:
		{
			this->sortEventListeners(dirty_event_id_);
		}
		break;
	default:
		break;
	}

	this->set_dirty_flag(DirtyFlag::NONE);
}

} // namespace gamer
/*******************************************************************************
  @ copyright(C), 2015-2020, ConnorAndHisFriendsCompany.Inc
  @ filename:	  command_manager.cc
  @ author:		  Connor
  @ version:	  1.0.0
  @ date:		  2015-03-03
  @ description:  see the header file.
  @ others:  
  @ history: 
     1.date:
       author:
       modification:
********************************************************************************/

#include "command_manager.h"

#include <cassert>
#include <stdint.h>
#include <algorithm>

#include "common.h"
#include "command.h"
#include "command_listener.h"
#include "event_listener.h"
#include "event_manager.h"

namespace gamer {

CommandManager::CommandManager()
    :event_manager_(nullptr)
    ,cmd_listeners_(nullptr)
{
}

CommandManager::~CommandManager()
{
    SAFE_DELETE(event_manager_); 
    removeAllCmdListenersImpl(true);
    SAFE_DELETE(cmd_listeners_); 
}

CommandManager* CommandManager::getInstance()
{
    static CommandManager* cmd_manager = nullptr;
    if (nullptr == cmd_manager)
    {
        cmd_manager = new CommandManager();
        if ( !cmd_manager->init() )
        {
            SAFE_DELETE(cmd_manager); 
        }
    }
    return cmd_manager;
}

bool CommandManager::init()
{
    event_manager_ = new EventManager();
    event_manager_->init();

    cmd_listeners_ = new std::vector<CommandListener*>();

    return true;
}

void CommandManager::destoryInstance()
{
    CommandManager* cmd_manager = getInstance();
    SAFE_DELETE(cmd_manager);    
}

void CommandManager::addCmdListener(CommandListener* listener)
{
    if (nullptr == listener || listener->is_registered())
        return;

    assert(false != listener->checkValidity());

    addCmdListener(listener, listener->priority());
}

void CommandManager::removeCmdListener(CommandListener* listener)
{
    if (nullptr == listener)
        return;
    event_manager_->removeEventListener(listener->event_listener_);
    removeCmdListenerImpl(listener, false);
}

void CommandManager::removeCmdListenerWithCleanup(CommandListener* listener)
{
    if (nullptr == listener)
        return;
    event_manager_->removeEventListenerWithCleanup(listener->event_listener_);
    removeCmdListenerImpl(listener, true);
}

void CommandManager::removeAllCmdListeners()
{
    removeAllEventListeners(false);
    removeAllCmdListenersImpl(false);
}

void CommandManager::removeAllCmdListenersWithcleanup()
{
    removeAllEventListeners(true);
    removeAllCmdListenersImpl(true);
}

void CommandManager::sendCmd(Command* cmd)
{
    event_manager_->dispatchComand(cmd);
}

void CommandManager::sendCmd(id_t cmd_id)
{
    event_manager_->dispatchComand(cmd_id);
}

void CommandManager::sendCmd(id_t cmd_id, void* user_data)
{
    event_manager_->dispatchComand(cmd_id, user_data);
}

void CommandManager::addCmdListener(CommandListener* listener, int priority)
{
    cmd_listeners_->push_back(listener);
    event_manager_->addEventListener(listener->event_listener_, priority);

    sortCmdListeners(cmd_listeners_);
}

void CommandManager::sortCmdListeners(std::vector<CommandListener*>* cmd_listeners)
{
    if (cmd_listeners->empty())
        return;

    std::sort(cmd_listeners->begin(), 
              cmd_listeners->end(), 
              [&](const CommandListener* l1, 
                  const CommandListener* l2) 
              {
                   return l1->priority() < l2->priority();
              });
}

void CommandManager::removeCmdListenerImpl(CommandListener* listener, bool cleanup)
{
    auto it = std::find(cmd_listeners_->begin(), 
                        cmd_listeners_->end(), 
                        listener);
    if (cmd_listeners_->end() != it)
    {
        if (cleanup)
        {
            //SAFE_DELETE(listener);
            SAFE_DELETE(*it);
        }
        else
        {
            ((CommandListener*)*it)->set_registered(false);
        }
        cmd_listeners_->erase(it);
    }
}

void CommandManager::removeAllCmdListenersImpl(bool cleanup)
{
    if (event_manager_->is_dispatching())
    {
        // TODO:set dirty flag
        return;
    }

    if (cleanup)
    {
        std::for_each (cmd_listeners_->begin(), 
                       cmd_listeners_->end(), 
                       //gamer::delete_vector_obj()); // xcode builded
                       [&](CommandListener* cmd_listener)
                       {
                           SAFE_DELETE(cmd_listener);
                       });
    }
    else
    {
        std::for_each (cmd_listeners_->begin(), 
                       cmd_listeners_->end(), 
                       [&](CommandListener* cmd_listener)
                       {        
                           cmd_listener->set_registered(false);
                       });
    }

    cmd_listeners_->clear();
}

void CommandManager::removeAllEventListeners(bool cleanup)
{
    if (cleanup)
    {
        event_manager_->removeAllEventListenersWithCleanup();
    }
    else
    {
        event_manager_->removeAllEventListeners();
    }
}

} // namespace gamer

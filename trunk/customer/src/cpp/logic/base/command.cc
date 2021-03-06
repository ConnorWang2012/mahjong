﻿/*******************************************************************************
  @ copyright(C), 2015-2020, ConnorAndHisFriendsCompany.Inc
  @ filename:	  command.cc
  @ author:		  Connor
  @ version:	  1.0.0
  @ date:		  2015-03-04
  @ description:  see the header file.
  @ others:  
  @ history: 
     1.date:
       author:
       modification:
********************************************************************************/

#include "command.h"

namespace gamer 
{

Command::Command()
{
    init(0);
}

Command::Command(id_t cmd_id)
{
    init(cmd_id);
}

Command::~Command()
{
    //SAFE_DELETE(event_);
}

bool Command::init(id_t cmd_id)
{
    //event_ = new Event(cmd_id);
    event_.set_event_id(cmd_id);
    return true;
}

} // namespace gamer
/*******************************************************************************
  @ copyright(C), 2015-2020, ConnorAndHisFriendsCompany.Inc
  @ filename:	  myevent.cc
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

#include "myevent.h"

namespace gamer 
{

Event::Event()           
    : event_id_(0),
	  event_name_(""),
	  is_stopped_(false),
	  user_data_(nullptr)
{

}

Event::Event(id_t event_id)           
    : event_id_(event_id),
	  event_name_(""),
	  is_stopped_(false),
	  user_data_(nullptr)
{

}

Event::~Event()
{
}

} // namespace gamer
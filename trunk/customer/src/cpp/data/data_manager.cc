/*******************************************************************************
@ copyright(C), 2015-2020, ConnorAndHisFriendsCompany.Inc
@ filename:	    data_manager.h
@ author:	    Connor
@ version:	    1.0.0
@ date:		    2017-05-01
@ description:  see the header.
@ others:
@ history:
1.date:
author:
modification:
********************************************************************************/

#include "data_manager.h"

namespace gamer
{

void DataManager::setData(int key, google::protobuf::Message* data)
{
    auto itr = data_map_.find(key);
    if (itr != data_map_.end())
    {
        itr->second = data;
    }
    else
    {
        data_map_.insert(std::make_pair(key, data));
    }
}

google::protobuf::Message* const DataManager::getData(int key) const
{
    auto itr = data_map_.find(key);
    if ( itr != data_map_.end())
    {
        return itr->second;
    }
    return nullptr;
}

} // namespace gamer
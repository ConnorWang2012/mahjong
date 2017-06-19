/*******************************************************************************
@ copyright(C), 2015-2020, ConnorAndHisFriendsCompany.Inc
@ filename:	    data_manager.h
@ author:	    Connor
@ version:	    1.0.0
@ date:		    2017-05-01
@ description:  data manager.
@ others:
@ history:
1.date:
author:
modification:
********************************************************************************/

#ifndef CONNOR_GAME_SRC_DATA_MANAGER_H_
#define CONNOR_GAME_SRC_DATA_MANAGER_H_

#include <unordered_map>

#include "base/basic_manager.h"

namespace google
{
    namespace protobuf
    {
        class Message;
    }
}

namespace gamer
{

class DataManager : public BasicManager<DataManager>
{
public:
    template<typename DataType>
    DataType* createData();

    template<typename DataType>
    DataType* cacheData(int key);

    void setData(int key, google::protobuf::Message* data);

    //const google::protobuf::Message& getData(int key) const;

    google::protobuf::Message* getMutableData(int key);

private:
    std::unordered_map<int, google::protobuf::Message*> data_map_;
};

template<typename DataType>
inline DataType* DataManager::createData()
{
    return new DataType();
}

template<typename DataType>
DataType* DataManager::cacheData(int key)
{
    auto data = this->getMutableData(key);
    if (nullptr == data)
    {
        data = new DataType();
        this->setData(key, data);
    }
    return static_cast<DataType*>(data);
}

} // namespace gamer

#endif // CONNOR_GAME_SRC_DATA_MANAGER_H_

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

    void cacheData(int key, google::protobuf::Message* data);

    //const google::protobuf::Message& getData(int key) const;

	const google::protobuf::Message* const getData(int key) const;

    google::protobuf::Message* getMutableData(int key);

private:
	void setData(int key, google::protobuf::Message* data);

	void releaseData(int key, google::protobuf::Message* data);

    std::unordered_map<int, google::protobuf::Message*> data_map_;
};

template<typename DataType>
inline DataType* DataManager::createData()
{
    return new DataType;
}

} // namespace gamer

#endif // CONNOR_GAME_SRC_DATA_MANAGER_H_

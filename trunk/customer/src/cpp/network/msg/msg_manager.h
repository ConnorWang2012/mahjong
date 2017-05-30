/*******************************************************************************
@ copyright(C), 2015-2020, ConnorAndHisFriendsCompany.Inc
@ filename:	    msg_manager.h
@ author:	    Connor
@ version:	    1.0.0
@ date:		    2017-05-01
@ description:  msg manager, such as msg send, msg receive.
@ others:
@ history:
1.date:
author:
modification:
********************************************************************************/

#ifndef CONNOR_GAME_SRC_MSG_MANAGER_H_
#define CONNOR_GAME_SRC_MSG_MANAGER_H_

#include <string>
#include <unordered_map>

#include "macros.h"
#include "msg/msg.h"

namespace gamer
{

class Event;

class MsgManager
{
public:
    typedef std::function<void(int, msg_header_t, msg_header_t, void*)> MsgResponseCallback;

	MsgManager& operator=(const MsgManager&) = delete;

	MsgManager(const MsgManager&) = delete;

	void *operator new(std::size_t) = delete;
	
	static MsgManager* getInstance();

    // use for c++ only
    bool sendMsg(msg_header_t msg_type, 
                 msg_header_t msg_id, 
                 const MsgResponseCallback& response_cb);

    // use for c++ only
    bool sendMsg(const ClientMsg& msg, const MsgResponseCallback& response_cb);

    // use for lua only
    bool sendMsg(msg_header_t msg_type, msg_header_t msg_id, gamer::LuaFunction response_cb);

private:
    typedef std::function<void(const ServerMsg&)> MsgHandler;

    MsgManager();

    void init();

    void addMsgDispatchHandlers();

    void addMsgHandlers();

    bool packMsg(const ClientMsg& msg, char* buf, msg_header_t& len);

    std::string getMsgCallbackKey(msg_header_t msg_type, msg_header_t msg_id);

    void dealWithLoginMsg(const ServerMsg& msg);

    void dealWithMgLoginMsg(const ServerMsg& msg);

    void onSocketConnected(gamer::Event* event);

    void onMsgReceived(const ServerMsg& msg);

    friend class NetworkManager;

    std::unordered_map<std::string, MsgResponseCallback> msg_response_callbacks_;
    std::unordered_map<std::string, LuaFunction> msg_response_lua_callbacks_;

    std::unordered_map<int, MsgHandler> msg_handlers_;          // key is MsgIDs
    std::unordered_map<int, MsgHandler> msg_dispatch_handlers_; // key is MsgTypes

    static const int MAX_MSG_LEN = 4096;
};

} // namespace gamer

#endif // CONNOR_GAME_SRC_MSG_MANAGER_H_
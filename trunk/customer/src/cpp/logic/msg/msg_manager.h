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

#include "base/macros.h"
#include "msg/msg.h"

namespace google
{
    namespace protobuf
    {
        class Message;
    }
}

namespace gamer
{

class Event;

class MsgManager
{
public:
    typedef std::function<void(int, 
                               msg_header_t, 
                               msg_header_t, 
                               const google::protobuf::Message* msg)> MsgResponseCallback;

	MsgManager& operator=(const MsgManager&) = delete;

	MsgManager(const MsgManager&) = delete;

	void *operator new(std::size_t) = delete;
	
	static MsgManager* getInstance();

    // use for c++ only
    bool sendMsg(const ClientMsg& msg, const MsgResponseCallback& response_cb);

    // use for c++ only
    bool sendMsg(msg_header_t msg_type,
                 msg_header_t msg_id,
                 const google::protobuf::Message& msg,
                 const MsgResponseCallback& response_cb);

    // use for lua only
    bool sendMsg(msg_header_t msg_type, 
                 msg_header_t msg_id, 
                 const google::protobuf::Message& msg, 
                 gamer::LuaFunction response_cb);

private:
    typedef std::function<void(const ServerMsg&)> MsgHandler;

    MsgManager();

    void init();

    void addMsgDispatchHandlers();

    void addMsgHandlers();

    bool packMsg(const ClientMsg& msg, char* buf, msg_header_t& len);

    bool packMsg(msg_header_t msg_type,
                 msg_header_t msg_id,
                 const google::protobuf::Message& msg, 
                 char* buf, 
                 msg_header_t& len);

    bool sendMsg(msg_header_t msg_type,
                 msg_header_t msg_id,
                 const google::protobuf::Message& msg,
                 bool is_lua, 
                 gamer::LuaFunction lua_cb, 
                 const MsgResponseCallback& cpp_cb);

    std::string getMsgCallbackKey(msg_header_t msg_type, msg_header_t msg_id);

    void getMsgCallbacks(const std::string& key, 
                         MsgResponseCallback& cpp_cb, 
                         gamer::LuaFunction& lua_cb);

    // use main thread£¨UI thread£©to dispatch msg£¨can not dispatch msg in network thread, 
    // because in network thread use UI will be crash, and usually, customer use UI in msg callback£©.
    void dispatchMsg(int msg_code, 
                     msg_header_t msg_type, 
                     msg_header_t msg_id, 
                     const google::protobuf::Message* msg,
                     const std::string& class_name);

    void dealWithLoginMsg(const ServerMsg& msg);

    void dealWithMgLoginMsg(const ServerMsg& msg);

    void dealWithRoomMsg(const ServerMsg& msg);

    void dealWithCreateRoomMsg(const ServerMsg& msg);

    void dealWithStartGameMsg(const ServerMsg& msg);

    void onSocketConnected(gamer::Event* event);

    void onMsgReceived(const ServerMsg& msg);

    friend class NetworkManager;

    std::unordered_map<std::string, MsgResponseCallback> msg_response_cpp_callbacks_;
    std::unordered_map<std::string, LuaFunction> msg_response_lua_callbacks_;

    std::unordered_map<int, MsgHandler> msg_handlers_;    // key is MsgIDs
    std::unordered_map<int, MsgHandler> msg_dispatchers_; // key is MsgTypes

    static const int MAX_MSG_LEN = 4096;
};

} // namespace gamer

#endif // CONNOR_GAME_SRC_MSG_MANAGER_H_
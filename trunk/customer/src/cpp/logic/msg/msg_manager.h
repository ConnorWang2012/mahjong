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
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "macros.h"
#include "msg.h"

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
    bool sendMsg(const ClientMsg& msg);

    // use for c++ and lua
    bool sendMsg(msg_header_t msg_type, 
                 msg_header_t msg_id, 
                 const google::protobuf::Message& msg);

    // use for c++ only
    void addMsgListener(msg_header_t msg_type,
                        msg_header_t msg_id,
                        const MsgResponseCallback& listener);

    // use for c++ only
    void addMsgListener(msg_header_t msg_type, const MsgResponseCallback& listener);

    // use for lua only
    void addMsgListener(msg_header_t msg_type, 
                        msg_header_t msg_id, 
		                const gamer::LuaFunctionID& function_id);

    // use for lua only
    void addMsgListener(msg_header_t msg_type, const gamer::LuaFunctionID& function_id);

    // use for c++ only
    void removeMsgListener(msg_header_t msg_type,
                           msg_header_t msg_id,
                           const MsgResponseCallback& listener);

    // use for c++ only
    void removeMsgListener(msg_header_t msg_type, const MsgResponseCallback& listener);

    // use for lua only
    void removeMsgListener(msg_header_t msg_type, 
                           msg_header_t msg_id, 
		                   const gamer::LuaFunctionID& function_id);

    // use for lua only
    void removeMsgListener(msg_header_t msg_type, const gamer::LuaFunctionID& function_id);

private:
    struct MsgProtocol
    {
        msg_header_t type;
        msg_header_t id;
        msg_header_t code;
        google::protobuf::Message* msg;
        std::string class_name;
        std::string dispatch_key;
    };

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

    bool parseMsg(const ServerMsg& server_msg, google::protobuf::Message* msg);

    bool doSendMsg(msg_header_t msg_type,
                   msg_header_t msg_id,
                   const google::protobuf::Message& msg);

    std::string getKeyForStoreLuaCallback(msg_header_t msg_type, msg_header_t msg_id);

    std::string getMsgDispatchKey();

    void addMsgListenerForLua(msg_header_t msg_type, 
                              msg_header_t msg_id, 
		                      const std::string& function_id);

	void addMsgListenerForLua(msg_header_t msg_type,
		                      const std::string& function_id);

    void addMsgListenerForCpp(msg_header_t msg_type, 
                              msg_header_t msg_id, 
                              const MsgResponseCallback& listener);

    void removeMsgListenerForLua(msg_header_t msg_type, 
                                 msg_header_t msg_id,
		                         const gamer::LuaFunctionID& function_id);

	void removeMsgListenerForLua(msg_header_t msg_type, const gamer::LuaFunctionID& function_id);

    void removeMsgListenerForCpp(msg_header_t msg_type,
                                 msg_header_t msg_id,
                                 const MsgResponseCallback& listener);

    // use main thread£¨UI thread£©to dispatch msg£¨can not dispatch msg in network thread, 
    // because in network thread use UI will be crash, and usually, customer use UI in msg callback£©.
    void dispatchMsg(int msg_code, 
                     msg_header_t msg_type, 
                     msg_header_t msg_id, 
                     google::protobuf::Message* msg,
                     const std::string& class_name);

    void dealWithLoginMsg(const ServerMsg& msg);

	void dealWithPropertyMsg(const ServerMsg& msg);

	void dealWithRoomMsg(const ServerMsg& msg);

    void dealWithMgLoginMsg(const ServerMsg& msg);

	void dealWithGetPlayerInfoMsg(const ServerMsg& msg);

	void dealWithSetPropertyMsg(const ServerMsg& msg);

    void dealWithCreateRoomMsg(const ServerMsg& msg);

    void dealWithPlayerJoinRoomMsg(const ServerMsg& msg);

    void dealWithStartGameMsg(const ServerMsg& msg);

    void dealWithGameEndMsg(const ServerMsg& msg);

    void dealWithPlayCardMsg(const ServerMsg& msg);

    // callback for dispatching multi-msg
    void onMultiMsgDispatch(float dt);

    void onSocketConnected(const gamer::Event& event);

    void onMsgReceived(const ServerMsg& msg);

    inline void set_is_multi_msg(bool is_multi_msg);

    inline bool is_multi_msg() const;

    friend class NetworkManager;

    std::unordered_map<std::string, std::vector<MsgResponseCallback>> msg_response_cpp_callbacks_;
    std::unordered_map<std::string, std::unordered_set<std::string>> lua_callbacks1_;  // key is msg id + msg type
	std::unordered_map<msg_header_t, std::unordered_set<std::string>> lua_callbacks2_; // key is msg type

    std::unordered_map<int, MsgHandler> msg_handlers_;    // key is MsgIDs
    std::unordered_map<int, MsgHandler> msg_dispatchers_; // key is MsgTypes

    std::queue<MsgProtocol*> msg_queue_;
    int msg_dispatch_index_;

    static const int MAX_MSG_LEN = 4096;

    bool is_multi_msg_;
};


inline void MsgManager::set_is_multi_msg(bool is_multi_msg)
{
    is_multi_msg_ = is_multi_msg;
}

inline bool MsgManager::is_multi_msg() const
{
    return is_multi_msg_;
}

} // namespace gamer

#endif // CONNOR_GAME_SRC_MSG_MANAGER_H_

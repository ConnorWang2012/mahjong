/*******************************************************************************
@ copyright(C), 2015-2020, ConnorAndHisFriendsCompany.Inc
@ filename:	    network_manager.h
@ author:	    Connor
@ version:	    1.0.0
@ date:		    2017-05-01
@ description:  manage network, such as connect server.
@ others:
@ history:
1.date:
author:
modification:
********************************************************************************/

#ifndef CONNOR_GAME_SRC_NETWORK_MANAGER_H_
#define CONNOR_GAME_SRC_NETWORK_MANAGER_H_

#include <functional>
#include <string>
#include <thread>

#include "msg/msg.h"

struct bufferevent;
struct event_base;

namespace gamer
{

class NetworkManager
{
public:
	NetworkManager& operator=(const NetworkManager&) = delete;

	NetworkManager(const NetworkManager&) = delete;

	void *operator new(std::size_t) = delete;
	
	static NetworkManager* getInstance();

	void set_ip(const std::string& ip);

	const std::string& ip() const;

	void set_port(int port);

	int port() const;

	void connect();

	void disconnect();

    bool send(void* ctx, size_t ctxlen);
    
private:
	NetworkManager();

	NetworkManager(const std::string& ip, int port);
	
	void initIPAndPort();

    static void parseBuffer(char* buf, gamer::Msg& msg);

    void onNetworkUpdate();

	static void onBufferEventReceived(struct bufferevent* bev, short event, void* ctx);

	static void onBufferRead(struct bufferevent* bev, void* ctx);

	static void onBufferWrite(struct bufferevent* bev, void* ctx);

	struct event_base* evbase_;
	struct bufferevent* bev_;

	std::string ip_;
	int port_;

    static const int MAX_BUFFER_LEN = 4096;

    std::thread network_thread_;
};

} // namespace gamer

#endif // CONNOR_GAME_SRC_NETWORK_MANAGER_H_
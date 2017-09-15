/*******************************************************************************
@ copyright(C), 2015-2020, ConnorAndHisFriendsCompany.Inc
@ filename:	    network_manager.cc
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

#include "network_manager.h"

#if defined(_WIN32)
#include <WinSock2.h>
#elif defined(__linux__)
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#elif defined(__APPLE__)
#endif

#include <chrono>

#include "event2/buffer.h"
#include "event2/bufferevent.h"
#include "event2/event.h"
#include "event2/thread.h"

#include "event_headers.h"
#include "macros.h"
#include "msg/msg_manager.h"

namespace gamer
{

NetworkManager::NetworkManager()
{

}

NetworkManager::NetworkManager(const std::string& ip, int port)
	:ip_(ip)
	,port_(port)
    ,is_connected_(false)
{

}

NetworkManager* NetworkManager::getInstance()
{
	static NetworkManager s_network_mgr; 
	return &s_network_mgr;
}

void NetworkManager::connect()
{
    if (this->is_connected())
        return;

	this->initIPAndPort();

	if (evbase_ && bev_)
	{
		auto ret = event_base_loopcontinue(evbase_);
		printf("[NetworkManager::connect] ret : %d", ret);
		return;
	}

	struct sockaddr_in sin;

#ifdef _WIN32
	WSADATA wsa_data;
	WSAStartup(0x0201, &wsa_data);

    evthread_use_windows_threads();
#else
    evthread_use_pthreads();
#endif

	if (nullptr == evbase_)
	{
		evbase_ = event_base_new();
	}

	if (nullptr == evbase_)
	{
		perror("event_base_new failed!");
		return;
		// TODO : dispatch event_base_new failed event
	}

	memset(&sin, 0, sizeof(sin));
	sin.sin_family = AF_INET;
	sin.sin_addr.s_addr = inet_addr(ip_.c_str());
	//sin.sin_addr.s_addr = inet_pton(AF_INET, ip_.c_str(), &sin);
	sin.sin_port = htons(port_);

	if (nullptr == bev_)
	{
		bev_ = bufferevent_socket_new(evbase_, -1, BEV_OPT_CLOSE_ON_FREE);
	}

	if (nullptr == bev_)
	{
		perror("bufferevent_socket_new failed!");
		return;
		// TODO : dispatch bufferevent_socket_new failed event
	}

	bufferevent_setcb(bev_,
		&gamer::NetworkManager::onBufferRead,
		&gamer::NetworkManager::onBufferWrite,
		&gamer::NetworkManager::onBufferEventReceived,
		NULL);

	bufferevent_enable(static_cast<bufferevent*>(bev_), 
        EV_READ | EV_WRITE | EV_PERSIST | EV_FEATURE_EARLY_CLOSE | EV_TIMEOUT);

	if (-1 == bufferevent_socket_connect(bev_, (struct sockaddr*)&sin, sizeof(sin)))
	{
		perror("bufferevent_socket_connect failed!");
		return;
		// TODO : dispatch bufferevent_socket_connect failed event
	}

	//event_base_dispatch(evbase_);
    event_base_loop(evbase_, EVLOOP_NONBLOCK | EVLOOP_NO_EXIT_ON_EMPTY);

    network_thread_ = std::thread(CALLBACK_SELECTOR_0(NetworkManager::onNetworkUpdate, this));
    network_thread_.detach();
}

void NetworkManager::disconnect()
{
	if (evbase_)
	{
		auto ret = event_base_loopexit(evbase_, NULL); // TODO : this is wrong way
        this->set_connected(false);
		printf("[NetworkManager::disconnect] ret : %d", ret);
	}
}

bool NetworkManager::send(void* ctx, size_t ctxlen)
{
    if (nullptr == ctx)
    {
        printf("[NetworkManager::send] context invalid");
        return false;
    }

    if (ctxlen > NetworkManager::MAX_BUFFER_LEN)
    {
        printf("[NetworkManager::send] context len invalid");
        return false;
    }

    if (bev_)
    {
        auto ret = bufferevent_write(bev_, ctx, ctxlen);
        if (0 == ret)
        {
            return true;
        }
    }

    return false;
}

void NetworkManager::initIPAndPort()
{
    ip_ = "127.0.0.1";
    port_ = 4994;
}

void NetworkManager::parseBuffer(char* buf, gamer::ServerMsg& msg)
{
    memcpy(&msg.total_len, buf, sizeof(msg_header_t));
    memcpy(&msg.type, buf + sizeof(msg_header_t), sizeof(msg_header_t));
    memcpy(&msg.id, buf + sizeof(msg_header_t) * 2, sizeof(msg_header_t));
    memcpy(&msg.code, buf + sizeof(msg_header_t) * 3, sizeof(msg_header_t));
    if (msg.code == (msg_header_t)MsgResponseCodes::MSG_RESPONSE_CODE_SUCCESS)
    {
        if (msg.total_len > gamer::server_msg_header_len())
        {
            msg.context = buf + gamer::server_msg_header_len();
        }
    }
}

void NetworkManager::onNetworkUpdate()
{
    //printf("[NetworkManager::onNetworkUpdate]");
    while (true)
    {
        event_base_loop(evbase_, EVLOOP_NONBLOCK | EVLOOP_NO_EXIT_ON_EMPTY);
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }
}

void NetworkManager::onBufferEventReceived(struct bufferevent* bev, short event, void* ctx) 
{
	if (event & BEV_EVENT_ERROR) 
	{
		printf("error from bufferevent!");
		// TODO : dispatch error from bufferevent event
	}

	if (event & (BEV_EVENT_EOF | BEV_EVENT_ERROR)) 
	{
		bufferevent_free(bev);
		printf("error from bufferevent, free bufferevent!");
		// TODO : dispatch error from bufferevent, free bufferevent event
	}

	if (event & BEV_EVENT_CONNECTED) 
	{
		printf("client connected\n");
        NetworkManager::getInstance()->set_connected(true);

        MsgManager::getInstance(); // TODO : init this in some ohter place
        EventManager::getInstance()->dispatchEvent((int)EventIDs::EVENT_ID_SOCKET_CONNECTED);
	} 
	else if (event & BEV_EVENT_TIMEOUT) 
	{
		printf("client connect timeout");
		// TODO : dispatch client connect timeout event
	}
}

void NetworkManager::onBufferRead(struct bufferevent* bev, void* ctx) 
{
	// This callback is invoked when there is data to read on bev.
	auto input = bufferevent_get_input(bev);
   
    auto buf_len = evbuffer_get_length(input);
    if (buf_len <= 0)
    {
        printf("[NetworkManager::onBufferRead] buffer len is 0");
        return;
    }

    if (buf_len > NetworkManager::MAX_BUFFER_LEN)
    {
        printf("[NetworkManager::onBufferRead] buffer len is to large");
        return;
    }

    char buf[NetworkManager::MAX_BUFFER_LEN] = { 0 };
    if(evbuffer_remove(input, buf, buf_len) <= 0)
    {
        printf("[NetworkManager::onBufferRead] read buffer failed");
        return;
    }

    unsigned parsed_buf_len = 0;
    while (parsed_buf_len < buf_len)
    {
        gamer::ServerMsg msg = { 0, 0, 0, 0, nullptr };
        NetworkManager::parseBuffer(buf + parsed_buf_len, msg);

        MsgManager::getInstance()->onMsgReceived(msg);
        parsed_buf_len += msg.total_len;
    }
}

void NetworkManager::onBufferWrite(struct bufferevent* bev, void* ctx) 
{
	//printf("client read_cb");
	//char msg[] = "client msg";
	//bufferevent_write(bev, msg, sizeof(msg));
}

} // namespace gamer
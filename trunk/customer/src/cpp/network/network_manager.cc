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

#include "event2/buffer.h"
#include "event2/bufferevent.h"
#include "event2/event.h"

#include "msg/msg_manager.h"

namespace gamer
{

NetworkManager::NetworkManager()
{

}

NetworkManager::NetworkManager(const std::string& ip, int port)
	:ip_(ip)
	,port_(port)
{

}

NetworkManager* NetworkManager::getInstance()
{
	static NetworkManager s_network_mgr; 
	return &s_network_mgr;
}

void NetworkManager::set_ip(const std::string& ip)
{
	ip_ = ip;
}

const std::string& NetworkManager::ip() const
{
	return ip_;
}

void NetworkManager::set_port(int port)
{
	port_ = port;
}

int NetworkManager::port() const
{
	return port_;
}

void NetworkManager::connect()
{
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

	bufferevent_enable(static_cast<bufferevent*>(bev_), EV_READ | EV_WRITE | EV_PERSIST);

	if (-1 == bufferevent_socket_connect(bev_, (struct sockaddr*)&sin, sizeof(sin)))
	{
		perror("bufferevent_socket_connect failed!");
		return;
		// TODO : dispatch bufferevent_socket_connect failed event
	}

	//event_base_dispatch(evbase_);
	event_base_loop(evbase_, EVLOOP_NONBLOCK | EVLOOP_NO_EXIT_ON_EMPTY);
}

void NetworkManager::disconnect()
{
	if (evbase_)
	{
		auto ret = event_base_loopexit(evbase_, NULL);
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

void NetworkManager::parseBuffer(char* buf, gamer::Msg& msg)
{
    memcpy(&msg.total_len, buf, sizeof(unsigned int));
    memcpy(&msg.type, buf + sizeof(unsigned int), sizeof(unsigned int));
    memcpy(&msg.id, buf + sizeof(unsigned int) * 2, sizeof(unsigned int));
    auto msg_header_len = sizeof(unsigned int) * 3;
    if (msg.total_len > msg_header_len)
    {
        memcpy(&msg.context, buf + msg_header_len, msg.total_len - msg_header_len);
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
		// TODO : dispatch client connected success event

		//write_cb(bev, NULL);
		//char msg[] = "client connected";
		//bufferevent_write(bev, msg, sizeof(msg));

		//auto input = bufferevent_get_input(bev);
		//auto output = bufferevent_get_output(bev);
		//evbuffer_add_printf(output, "client msg : %s", "client connected 2");

        //char buf1[256] = { 0 };
        //char buf2[128] = { 0 };
        //int msgid = 7;
        //int msgtype = 8;
        //memcpy(buf1, &msgid, sizeof(int));
        //memcpy(buf1 + sizeof(int), &msgtype, sizeof(int));
        //gamer::protocol::Msg msg;
        //msg.set_msg_id(1000);
        //msg.set_msg_type(2000);
        //msg.SerializeToArray(buf2, msg.ByteSize());
        //memcpy(buf1 + sizeof(int) * 2, buf2, msg.ByteSize());
        //auto size = sizeof(buf1);
        //auto total_size = sizeof(int) * 2 + msg.ByteSize();
        //gamer::NetworkManager::getInstance()->send(buf1, total_size, [](short, void*) {});
        gamer::Msg msg = { 12, 0, 2, nullptr };
        auto func = [&](unsigned int msg_type, unsigned int msg_id, void* tx) {
            printf("msg callback msg_type : %d, msg_id : %d", msg_type, msg_id);
        };
        MsgManager::getInstance()->sendMsg(msg, func);
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

    char buf[NetworkManager::MAX_BUFFER_LEN] = { 0 };
    if(evbuffer_remove(input, buf, buf_len) <= 0)
    {
        printf("[NetworkManager::onBufferRead] read buffer failed");
        return;
    }

    gamer::Msg msg = { 0, 0, 0, nullptr };
    NetworkManager::parseBuffer(buf, msg);

    MsgManager::getInstance()->onMsgReceived(msg);
}

void NetworkManager::onBufferWrite(struct bufferevent* bev, void* ctx) 
{
	//printf("client read_cb");
	//char msg[] = "client msg";
	//bufferevent_write(bev, msg, sizeof(msg));
}

} // namespace gamer
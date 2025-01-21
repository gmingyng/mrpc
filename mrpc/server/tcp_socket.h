#pragma once

#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/epoll.h>
#include <cstring>
#include <fcntl.h>
#include <errno.h>
#include <string>


namespace mrpc{

class TcpSocket{
public:
    explicit TcpSocket(const std::string& address, uint16_t port);
    ~TcpSocket();

    auto SendMsg() -> int;
    auto RecvMsg() -> std::string;

private:
    auto Readn() -> int;
    auto Writen() -> int;
};

}//namespace mrpc
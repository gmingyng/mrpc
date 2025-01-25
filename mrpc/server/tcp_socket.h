#pragma once

#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/epoll.h>
#include <cstring>
#include <fcntl.h>
#include <errno.h>
#include <string>

#include "../rpc_msg/rpc_msg.pb.h"

namespace mrpc{

/*
* 仅进行数据传输，解析交由服务器端
*/
class TcpSocket{
public:
    explicit TcpSocket(const std::string& address, uint16_t port);
    ~TcpSocket();

    auto Send() -> int;
    auto Recv() -> std::string;

private:
    auto Readn() -> int;
    auto Writen() -> int;

    
};

}//namespace mrpc
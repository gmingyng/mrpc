#pragma once

#include <string>
#include "../registry/local_registry.h"
#include "tcp_socket.h"

namespace mrpc {

class MrpcServer {
public:
    MrpcServer();
    ~MrpcServer();
private:

    TcpSocket net_connect_;
    LocalRegistry local_registry_;
    int port_;
    uint32_t timeout_;
};


}//namespace mrpc
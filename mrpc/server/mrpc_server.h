#pragma once

#include <string>
#include "../registry/local_registry.h"
#include "tcp_socket.h"
#include "../rpc_msg/rpc_msg.pb.h"

namespace mrpc {

class MrpcServer {
public:
    MrpcServer();
    ~MrpcServer();

    void Run();

    void Register(const std::string& service_name, ServiceSPtr service);

private:
    void RecvCallback();
    

    TcpSocket tcp_socket_;
    LocalRegistry local_registry_;
    int port_;
    uint32_t timeout_;
};


}//namespace mrpc
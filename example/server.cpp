#include "../mrpc/server/mrpc_server.h"
#include "../mrpc/server/impl_service.h"

using namespace mrpc;

int main() {
    MrpcServer server;
    auto account_service = std::make_shared<RpcAccountService>("RpcAccountService");
    
    server.Register("RpcAccountService", account_service);

    server.Run();
}
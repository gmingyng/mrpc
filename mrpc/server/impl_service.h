#pragma once

#include "base_service.h"
#include "rpc_msg/rpc_msg.pb.h"


namespace mrpc {

class RpcAccountService final : public BaseService {
public:
    RpcAccountService() = delete;
    explicit RpcAccountService(const std::string& name);
    
    using AccountReqSPtr = std::shared_ptr<InfoUpdateRequest>;
    using AccountResSPtr = std::shared_ptr<InfoUpdateResponse>;
    void Execute(MessageSPtr req, MessageSPtr res);
private:
    //method
    inline void AccountInfoUpdate(AccountReqSPtr req, AccountResSPtr res);
};

}//namespace mrpc
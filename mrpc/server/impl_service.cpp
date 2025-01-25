#include "impl_service.h"

namespace mrpc {

explicit RpcAccountService::RpcAccountService(const std::string& name) 
    : BaseService(name) {}

void RpcAccountService::Execute(MessageSPtr req, MessageSPtr res) {
    auto spec_req = std::dynamic_pointer_cast<InfoUpdateRequest>(req);
    auto spec_res = std::dynamic_pointer_cast<InfoUpdateResponse>(res);
    if(spec_req->method_name() == "AccountInfoUpdate") {
        AccountInfoUpdate(spec_req, spec_res);
    }
}


inline void RpcAccountService::AccountInfoUpdate(AccountReqSPtr req, AccountResSPtr res) {
    AccountInfo new_info = req->info();
    new_info.set_description(req->new_description());
    res->set_allocated_info_ret(&new_info);
    res->set_err_code(RpcErrCode::RPC_ERR_SUCCESS);
}

}//namespace mrpc 
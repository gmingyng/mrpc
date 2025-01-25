#pragma once

#include <string>
#include "rpc_msg/rpc_msg.pb.h"

namespace mrpc{

using MessageSPtr = std::shared_ptr<google::protobuf::Message>;

// class BaseServiceInterface {
// public:
//     virtual void Execute(MessageSPtr req, MessageSPtr res) = 0;
//     virtual auto GetName() const -> std::string = 0;
// };

// template<typename ReqType, typename ResType>
class BaseService {
public:
    explicit BaseService(const std::string& name) : name_(name) {}
    virtual ~BaseService() = default;

    virtual void Execute(MessageSPtr req, MessageSPtr res) = 0;

    auto GetName() const -> std::string { return name_; }
private:
    std::string name_;
};

}//namespace mrpc
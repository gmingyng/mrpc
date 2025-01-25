#pragma once

#include <string>
#include <unordered_map>
#include <functional>
#include <shared_mutex>
#include <memory>
#include <optional>
#include <mutex>
#include "../Serializer.h"
#include "../server/base_service.h"

namespace mrpc{

using ServiceSPtr = std::shared_ptr<BaseService>;

class LocalRegistry
{
public:
    LocalRegistry();
    ~LocalRegistry() = default;
    
    void Register(const std::string& service_name, ServiceSPtr service);

    auto Get(std::string service_name) -> std::optional<ServiceSPtr>;

    void Remove(const std::string& service_name);
private:
    std::unordered_map<std::string, ServiceSPtr> handler_table_;
    std::shared_ptr<std::shared_mutex> reg_latch_;
};

}//namespace mrpc
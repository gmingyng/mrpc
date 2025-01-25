#include "local_registry.h"

namespace mrpc{

LocalRegistry::LocalRegistry() 
    : reg_latch_(std::make_shared<std::shared_mutex>()) {}

void LocalRegistry::Register(const std::string& service_name, ServiceSPtr service) {
    std::unique_lock latch(*reg_latch_);
    handler_table_[service_name] = service;
}

auto LocalRegistry::Get(std::string service_name) -> std::optional<ServiceSPtr> {
    std::shared_lock latch(*reg_latch_);

    auto it = handler_table_.find(service_name);
    if(it == handler_table_.end()) {
        return std::nullopt;
    }
    return std::make_optional<ServiceSPtr>(it->second);
}

void LocalRegistry::Remove(const std::string& service_name) {
    std::unique_lock latch(*reg_latch_);

    auto it = handler_table_.find(service_name);
    if(it != handler_table_.end()) {
        handler_table_.erase(it);
    }
}

}//namespace mrpc
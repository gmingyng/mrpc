#include "local_registry.h"

namespace mrpc{

LocalRegistry::LocalRegistry() 
    : reg_latch_(std::make_shared<std::shared_mutex>()) {}

template <typename T>
void LocalRegistry::Register(const std::string& service_name, T service) {
    std::unique_lock latch(*reg_latch_);
    call_handlers_[service_name] = service;
}

template <typename T>
auto LocalRegistry::Get(std::string service_name) -> std::optional<T> {
    std::shared_lock latch(*reg_latch_);

    auto it = call_handlers_.find(service_name);
    if(it == call_handlers_.end()) {
        return std::nullopt;
    }
    return std::make_optional<T>(it->second);
}

void LocalRegistry::Remove(const std::string& service_name) {
    std::unique_lock latch(*reg_latch_);

    auto it = call_handlers_.find(service_name);
    if(it != call_handlers_.end()) {
        call_handlers_.erase(it);
    }
}

}//namespace mrpc
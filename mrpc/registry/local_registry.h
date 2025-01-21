#pragma once

#include <string>
#include <unordered_map>
#include <functional>
#include <shared_mutex>
#include <memory>
#include <optional>
#include <mutex>
#include "../Serializer.h"
#include "../registry/local_registry.h"
#include "../server/base_service.hpp"

namespace mrpc{

using ServiceFunc = std::function<void(Serializer*, const char*, int)>;

class LocalRegistry
{
public:
    LocalRegistry();
    ~LocalRegistry() = default;

    template <typename T>
    void Register(const std::string& service_name, T service);

    template <typename T>
    auto Get(std::string service_name) -> std::optional<T>;

    void Remove(const std::string& service_name);
private:
    std::unordered_map<std::string, std::shared_ptr<BaseService>> call_handlers_;
    std::shared_ptr<std::shared_mutex> reg_latch_;
};

}//namespace mrpc
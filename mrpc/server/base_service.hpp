#pragma once

#include <string>

namespace mrpc{

class BaseService {
public:
    explicit BaseService(const std::string& name) : name_(name) {}
    virtual ~BaseService() = default;

    virtual void Execute() = 0;

    auto GetName() const -> std::string {
        return name_;
    }
private:
    std::string name_;
};

}//namespace mrpc
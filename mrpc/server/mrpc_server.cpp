#include <sstream>
#include "mrpc_server.h"

namespace mrpc {

void MrpcServer::Register(const std::string& service_name, ServiceSPtr service) {
    local_registry_.Register(service_name, service);
}


void MrpcServer::RecvCallback() {

}

void MrpcServer::Run() {
    while(true)
    {
        char data[1024];
        
        // tcp_socket_.Recv(&data);
        std::istringstream is(data, std::ios::binary);
        std::shared_ptr<google::protobuf::Message> req;
        req->ParseFromIstream(&is);

        const auto desc = req->GetDescriptor();
        auto refl = req->GetReflection();
        auto field = desc->FindFieldByName("service_name");
        std::string service_name = refl->GetString(*req, field);
        auto ser_opt = local_registry_.Get(service_name);
        auto res = std::make_shared<InfoUpdateResponse>();
        if(ser_opt.has_value()) {
            auto service = ser_opt.value();            
            service->Execute(req, res);
        }
        // std::string req_type = req->GetTypeName();
        // if(req_type == "InfoUpdateRequest") {
        //     local_registry_.Get("")
        // } 
        // std::shared_ptr<google::protobuf::Message> msg;
        // const google::protobuf::Descriptor* descriptor = 
        //         google::protobuf::DescriptorPool::generated_pool() ->FindMessageTypeByName(req_type);
        // if(descriptor) {
        //     const google::protobuf::Message* prototype = 
        //             google::protobuf::MessageFactory::generated_factory()->GetPrototype(descriptor);
        //     if(prototype) {
        //         msg = std::make_shared<google::protobuf::Message>(prototype->New());
        //         msg->CopyFrom(*req);
        //     }
        // }
        // if(!msg) {
        //     return;
        // }

    }
}


}//namespace mrpc
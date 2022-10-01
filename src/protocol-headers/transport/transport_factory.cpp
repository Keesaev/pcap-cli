#include "transport_factory.h"

#include "tcp.h"
#include "unsupported_transport.hpp"

std::unique_ptr<transport> transport_factory::make_transport(transport_proto_type type,
    const unsigned char* bytes)
{
    switch (type) {
    case transport_proto_type::tcp:
        return std::unique_ptr<transport>(new tcp(bytes));
    default:
        return std::unique_ptr<transport>(new unsupported_transport());
    }
}

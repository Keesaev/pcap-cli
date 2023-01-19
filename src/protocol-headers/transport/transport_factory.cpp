#include "transport_factory.h"

#include "tcp.h"
#include "unsupported_transport.hpp"
#include <protocol-headers/transport/udp.h>

std::unique_ptr<transport> transport_factory::make_transport(transport_proto_type type,
    const unsigned char* bytes)
{
    switch (type) {
    case transport_proto_type::tcp:
        return std::unique_ptr<transport>(new tcp(bytes));
    case transport_proto_type::udp:
        return std::unique_ptr<transport>(new udp(bytes));
    default:
        return std::unique_ptr<transport>(new unsupported_transport());
    }
}

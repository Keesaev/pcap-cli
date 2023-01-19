#include "transport_factory.h"

#include <protocol-headers/transport/icmp.h>
#include <protocol-headers/transport/tcp.h>
#include <protocol-headers/transport/udp.h>
#include <protocol-headers/transport/unsupported_transport.hpp>

std::unique_ptr<transport> transport_factory::make_transport(transport_proto_type type,
    const unsigned char* bytes)
{
    switch (type) {
    case transport_proto_type::tcp:
        return std::unique_ptr<transport>(new tcp(bytes));
    case transport_proto_type::udp:
        return std::unique_ptr<transport>(new udp(bytes));
    case transport_proto_type::icmp:
        return std::unique_ptr<transport>(new icmp(bytes));
    default:
        return std::unique_ptr<transport>(new unsupported_transport());
    }
}

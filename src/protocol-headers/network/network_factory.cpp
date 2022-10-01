#include "network_factory.h"

#include "ipv4.h"
#include "ipv6.hpp"
#include "unsupported_network.hpp"

std::unique_ptr<network> network_factory::make_network(network_proto_type type,
    const unsigned char* bytes)
{
    switch (type) {
    case network_proto_type::ipv4:
        return std::unique_ptr<network>(new ipv4(bytes));

    default:
        return std::unique_ptr<network>(new unsupported_network());
    }
}

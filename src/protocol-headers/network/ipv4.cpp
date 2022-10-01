#include "ipv4.h"

#include "ipv4_protos.hpp"

#include <iostream> // TODO RM
ipv4::ipv4(const unsigned char* bytes)
    : _data { *reinterpret_cast<const ipv4_h*>(bytes) }
{
    std::cout << "IPv4:\t\t";
    for (int i = 0; i < sizeof(ipv4_h); i++) {
        std::cout << std::hex << (int)bytes[i] << std::dec << ' ';
    }
    std::cout << std::endl;
    std::cout << "IP NEXT PROTO = " << (int)_data.protocol << std::endl;
}

std::string ipv4::src_addr() const
{
    return _data.src_addr.pretty_str();
}

std::string ipv4::dst_addr() const
{
    return _data.dest_addr.pretty_str();
}

transport_proto_type ipv4::next_protocol_type() const
{
    switch (static_cast<ipv4_protos>(_data.protocol)) {
    case ipv4_protos::TCP:
        return transport_proto_type::tcp;
    // case ipv4_protos::UDP:
    //     return transport_proto_type::udp;
    // case ipv4_protos::ICMP:
    //     return transport_proto_type::icmp;
    default:
        return transport_proto_type::unsupported;
        break;
    }
}

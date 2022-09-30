#include "ethernet_2.h"

ethernet_2::ethernet_2(const unsigned char* bytes)
    : _data { *reinterpret_cast<const ethernet_2_h*>(bytes) }
{
}

network_proto_type ethernet_2::next_protocol() const
{
    switch (_data.ether_t) {
    case ether_type::ipv4:
        return network_proto_type::ipv4;
    case ether_type::ipv6:
        return network_proto_type::ipv6;
    default:
        return network_proto_type::unsupported;
    }
}

int ethernet_2::size() const
{
    return sizeof(ethernet_2_h);
}

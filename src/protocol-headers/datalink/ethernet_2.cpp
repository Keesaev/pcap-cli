#include "ethernet_2.h"

#include <cstring>
#include <iostream> // TODO rm

#include <netinet/in.h>

ethernet_2::ethernet_2(const unsigned char* bytes)
{
    std::memcpy(&_data, bytes, sizeof(ethernet_2_h));
    _data.ether_t = ::htons(_data.ether_t);
    std::cout << "ethernet_2:\t";
    for (int i = 0; i < sizeof(ethernet_2_h); i++) {
        std::cout << std::hex << (int)bytes[i] << " ";
    }
    std::cout << std::endl;
}

network_proto_type ethernet_2::next_protocol() const
{
    switch (static_cast<ether_type>(_data.ether_t)) {
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

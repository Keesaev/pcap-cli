#include "ethernet_2.h"

#include <cstring>
#include <iostream> // TODO rm

#include <netinet/in.h>

const std::array<std::string, ethernet_2::_field_count> ethernet_2::_descriptions {
    "Destination mac", "Source mac", "Ether type"
};

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

std::string ethernet_2::pretty_mac(const uint8_t* const src_mac) const
{
    char str[25];
    std::sprintf(str,
        "%02x:%02x:%02x:%02x:%02x:%02x",
        src_mac[0],
        src_mac[1],
        src_mac[2],
        src_mac[3],
        src_mac[4],
        src_mac[5]);
    return std::string(str);
}

const std::pair<std::string, std::string> ethernet_2::operator[](std::size_t idx) const
{
    auto value = [this](std::size_t idx) -> std::string {
        switch (idx) {
        case 0:
            return pretty_mac(_data.dest_mac);
        case 1:
            return pretty_mac(_data.src_mac);
        case 2:
            return std::to_string(_data.ether_t);
        default:
            return "";
        }
    };
    return { value(idx), _descriptions[idx] };
}

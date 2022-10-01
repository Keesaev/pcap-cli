#include "ipv4.h"

#include <cstring>

#include <iostream> // TODO RM
ipv4::ipv4(const unsigned char* bytes)
{
    std::memcpy(&_data, bytes, sizeof(ipv4_h));

    std::cout << "IPv4:\t\t";
    for (int i = 0; i < sizeof(ipv4_h); i++) {
        std::cout << std::hex << (int)bytes[i] << std::dec << ' ';
    }
    std::cout << std::endl;
}

std::string ipv4::src_addr() const
{
    return _data.src_addr.pretty_str();
}

std::string ipv4::dst_addr() const
{
    return _data.dest_addr.pretty_str();
}

int ipv4::next_protocol_type() const
{
    return (int)_data.protocol;
}

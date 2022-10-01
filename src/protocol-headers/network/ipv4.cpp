#include "ipv4.h"
#include <iostream> // TODO RM
ipv4::ipv4(const unsigned char* bytes)
    : _data { *reinterpret_cast<const ipv4_h*>(bytes) }
{
}

std::string ipv4::src_addr() const
{
    return "not implemented";
}

std::string ipv4::dst_addr() const
{
    return "not implemented";
}

int ipv4::next_protocol_type() const
{
    return (int)_data.protocol;
}
#include "tcp.h"

#include <iostream> // TODO rm

tcp::tcp(const unsigned char* bytes)
    : _data { *reinterpret_cast<const tcp_h*>(bytes) }
{
}

std::string tcp::hex() const
{
    return "";
}

const std::pair<std::string, std::string> tcp::operator[](std::size_t idx) const
{
    return { "", "" };
}

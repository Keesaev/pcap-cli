#include "tcp.h"

#include <iostream> // TODO rm

tcp::tcp(const unsigned char* bytes)
    : _data { *reinterpret_cast<const tcp_h*>(bytes) }
{
}
#include "ethernet_2.h"

ethernet_2::ethernet_2(const unsigned char* bytes)
    : _data { *reinterpret_cast<const ethernet_2_h*>(bytes) }
{
}

int ethernet_2::next_protocol_type() const
{
    return _data.ether_type;
}

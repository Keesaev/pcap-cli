#pragma once

#include "datalink.hpp"
#include "ether_type.hpp"

#include <stdint.h>

class ethernet_2 final : public datalink {
#pragma pack(push, 1)
    struct ethernet_2_h {
        uint8_t dest_mac[6];
        uint8_t src_mac[6];
        uint16_t ether_t;
    } _data;
#pragma pack(pop)
public:
    ethernet_2(const unsigned char* bytes);

    virtual int size() const final;
    virtual network_proto_type next_protocol() const final;
};

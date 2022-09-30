#pragma once

#include "datalink.hpp"

#include <stdint.h>

class ethernet_2 final : public datalink {
    const struct ethernet_2_h {
        uint8_t dest_mac[6];
        uint8_t src_mac[6];
        uint16_t ether_type;
    } _data;

public:
    ethernet_2(const unsigned char* bytes);

    virtual int next_protocol_type() const final;
};

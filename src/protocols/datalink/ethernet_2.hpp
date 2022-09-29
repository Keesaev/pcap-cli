#pragma once

#include <stdint.h>

struct ethernet_2{
    uint8_t dest_mac[6];
    uint8_t src_mac[6];
    uint16_t ether_type;
};
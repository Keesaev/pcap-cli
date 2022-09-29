#pragma once

#include <stdint.h>

struct ipv4_s{
    uint8_t v_hl;
    uint8_t tos;
    uint16_t length;
    uint16_t id;
    uint16_t offset;
    uint8_t ttl;
    uint8_t protocol;
    uint16_t checksum;
    uint32_t src_addr;
    uint32_t dest_addr;
};
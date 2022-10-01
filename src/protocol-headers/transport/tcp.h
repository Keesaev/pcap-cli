#pragma once

#include "transport.hpp"

#include <stdint.h>

class tcp final : public transport {
#pragma pack(push, 1)
    struct tcp_control {
        uint8_t data_offset : 4;
        uint8_t reserved : 3;
        uint8_t ns : 1;
        uint8_t cwr : 1;
        uint8_t ece : 1;
        uint8_t urg : 1;
        uint8_t ack : 1;
        uint8_t psh : 1;
        uint8_t rst : 1;
        uint8_t syn : 1;
        uint8_t fin : 1;
    };
    struct tcp_h {
        uint16_t src_port;
        uint16_t dst_port;
        uint32_t seq_num;
        uint32_t ack_num;
        tcp_control control;
        uint16_t win_size;
        uint16_t checksum;
        uint16_t urg_ptr;
    } _data;
#pragma pack(pop)

public:
    tcp(const unsigned char* bytes);
    virtual int proto_size() const final { return sizeof(tcp_h); }
    virtual ~tcp() { }
};
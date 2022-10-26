#pragma once

#include "transport.hpp"

#include <array>
#include <stdint.h>

class tcp final : public transport {
#pragma pack(push, 1)
    struct tcp_control {
        uint8_t ns : 1;
        uint8_t reserved : 3;
        uint8_t data_offset : 4;
        uint8_t fin : 1;
        uint8_t syn : 1;
        uint8_t rst : 1;
        uint8_t psh : 1;
        uint8_t ack : 1;
        uint8_t urg : 1;
        uint8_t ece : 1;
        uint8_t cwr : 1;
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
    static const int _field_count = 18;
    static const std::array<std::string, _field_count> _descriptions;

public:
    tcp(const unsigned char* bytes);
    virtual std::string name() const final { return "TCP"; }
    virtual std::string hex() const final;
    virtual int header_size() const final { return sizeof(tcp_h); }
    virtual int field_count() const final { return _field_count; }
    virtual const std::pair<std::string, std::string> operator[](std::size_t idx) const final;

    virtual ~tcp() { }
};
#pragma once

#include "transport.hpp"

#include <array>
#include <stdint.h>

class udp final : public transport {
#pragma pack(push, 1)
    struct udp_h {
        uint16_t src_port;
        uint16_t dst_port;
        uint16_t length;
        uint16_t checksum;
    } _data;
#pragma pack(pop)

    static const int _field_count = 4;
    static const std::array<std::string, _field_count> _descriptions;

public:
    udp(const unsigned char* bytes);
    virtual std::string name() const final { return "UDP"; }
    virtual std::string hex() const final;
    virtual int header_size() const final { return sizeof(udp_h); }
    virtual int field_count() const final { return _field_count; }
    virtual const std::pair<std::string, std::string> operator[](std::size_t idx) const final;

    virtual ~udp() { }
};
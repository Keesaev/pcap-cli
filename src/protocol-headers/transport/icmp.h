#pragma once

#include "transport.hpp"

#include <array>
#include <stdint.h>

class icmp final : public transport {
#pragma pack(push, 1)
    struct icmp_h {
        uint8_t type;
        uint8_t code;
        uint16_t checksum;
    } _data;
#pragma pack(pop)

    static const int _field_count = 3;
    static const std::array<std::string, _field_count> _descriptions;

public:
    icmp(const unsigned char* bytes);
    virtual std::string name() const final { return "ICMP"; }
    virtual std::string hex() const final;
    virtual int header_size() const final { return sizeof(icmp_h); }
    virtual int field_count() const final { return _field_count; }
    virtual const std::pair<std::string, std::string> operator[](std::size_t idx) const final;

    virtual ~icmp() { }
};
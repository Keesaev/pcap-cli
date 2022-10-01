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
    std::string pretty_mac(const uint8_t* const src_mac) const;
    static const std::array<std::string, 3> _descriptions;

public:
    ethernet_2(const unsigned char* bytes);

    virtual int proto_size() const final { return sizeof(ethernet_2_h); }
    virtual network_proto_type next_protocol() const final;
    virtual int size() const final { return 3; }
    virtual const std::pair<std::string, std::string> operator[](std::size_t idx) const final;

    virtual ~ethernet_2() {};
};

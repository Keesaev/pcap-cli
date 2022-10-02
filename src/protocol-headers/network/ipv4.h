#pragma once

#include <array>
#include <stdint.h>

#include "network.hpp"

class ipv4 final : public network {
#pragma pack(push, 1)
    struct ip_addr {
        uint8_t oct1;
        uint8_t oct2;
        uint8_t oct3;
        uint8_t oct4;

        std::string pretty_str() const
        {
            char str[17];
            sprintf(str, "%i.%i.%i.%i", oct1, oct2, oct3, oct4);
            return std::string(str);
        }
    };

    struct ipv4_vhl {
        uint8_t ihl : 4;
        uint8_t version : 4;
    };

    struct ipv4_tos {
        uint8_t dscp : 6;
        uint8_t ecn : 2;
    };

    struct ipv4_flags_offset {
        uint8_t reserved : 1;
        uint8_t df : 1;
        uint8_t mf : 1;
        uint16_t offset : 13;
    };

    struct ipv4_h {
        ipv4_vhl vhl;
        ipv4_tos tos;
        uint16_t length;
        uint16_t id;
        ipv4_flags_offset offset;
        uint8_t ttl;
        uint8_t protocol;
        uint16_t checksum;
        ip_addr src_addr;
        ip_addr dest_addr;
    } _data;
#pragma pack(pop)
    static const int _field_count = 14;
    static const std::array<std::string, _field_count> _descriptions;

public:
    ipv4(const unsigned char* bytes);

    virtual std::string name() const final { return "IPv4"; };
    virtual std::string src_addr() const final;
    virtual std::string dst_addr() const final;
    virtual transport_proto_type next_protocol_type() const final;
    virtual int header_size() const final { return sizeof(ipv4_h); }

    virtual int field_count() const final
    {
        return _field_count;
    }
    virtual const std::pair<std::string, std::string> operator[](std::size_t idx) const final;

    virtual ~ipv4() { }
};

#pragma once

#include <stdint.h>

#include "network.hpp"

class ipv4 final : public network {
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

    struct ipv4_h {
        uint8_t v_hl;
        uint8_t tos;
        uint16_t length;
        uint16_t id;
        uint16_t offset;
        uint8_t ttl;
        uint8_t protocol;
        uint16_t checksum;
        ip_addr src_addr;
        ip_addr dest_addr;
    } _data;

public:
    ipv4(const unsigned char* bytes);

    virtual std::string src_addr() const final;
    virtual std::string dst_addr() const final;
    virtual transport_proto_type next_protocol_type() const final;
    virtual int proto_size() final { return sizeof(ipv4_h); }

    virtual ~ipv4() { }
};

#pragma once

#include "network.hpp"

class unsupported_network final : public network {
public:
    virtual std::string name() const final { return "Unsupported"; };
    virtual std::string src_addr() const final { return ""; };
    virtual std::string dst_addr() const final { return ""; };
    virtual transport_proto_type next_protocol_type() const final
    {
        return transport_proto_type::unsupported;
    };
    virtual int header_size() const final { return 0; }
    virtual int field_count() const final { return 0; };
    virtual const std::pair<std::string, std::string> operator[](std::size_t idx) const final
    {
        return { "", "" };
    }

    virtual ~unsupported_network() { }
};
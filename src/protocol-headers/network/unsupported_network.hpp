#pragma once

#include "network.hpp"

class unsupported_network final : public network {
public:
    virtual std::string src_addr() const final { return ""; };
    virtual std::string dst_addr() const final { return ""; };
    virtual transport_proto_type next_protocol_type() const final
    {
        return transport_proto_type::unsupported;
    };
    virtual int size() { return 0; }

    virtual ~unsupported_network() { }
};
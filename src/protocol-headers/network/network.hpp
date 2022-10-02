#pragma once

#include "../protocol_header.hpp"

// supported transport protos
enum class transport_proto_type {
    unsupported = 0,
    tcp,
    udp,
    icmp
};

class network : public protocol_header {
public:
    virtual std::string src_addr() const = 0;
    virtual std::string dst_addr() const = 0;
    virtual transport_proto_type next_protocol_type() const = 0;

    virtual ~network() { }
};
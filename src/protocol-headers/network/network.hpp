#pragma once

#include <string>

// supported transport protos
enum class transport_proto_type {
    unsupported = 0,
    tcp,
    udp,
    icmp
};

class network {
public:
    virtual std::string name() const = 0;
    virtual std::string src_addr() const = 0;
    virtual std::string dst_addr() const = 0;
    virtual transport_proto_type next_protocol_type() const = 0;
    virtual int proto_size() = 0;

    virtual int field_count() const = 0;
    virtual const std::pair<std::string, std::string> operator[](std::size_t idx) const = 0;

    virtual ~network() { }
};
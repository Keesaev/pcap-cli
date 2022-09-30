#pragma once

#include <string>

enum class network_proto_type {
    unsupported = 0,
    ipv4,
    ipv6
};

class datalink {
public:
    virtual network_proto_type next_protocol() const = 0;
    virtual int size() const = 0;

    virtual ~datalink() { }
};
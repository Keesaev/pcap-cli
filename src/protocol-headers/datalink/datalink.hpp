#pragma once

#include <string>
#include <unordered_set>

// supported network protos
enum class network_proto_type {
    unsupported = 0,
    ipv4,
    ipv6
};

enum class datalink_proto_type {
    ethernet_2 = 1
};

static const std::unordered_set<int> supported_datalink_protos {
    1
};

class datalink {
public:
    virtual network_proto_type next_protocol() const = 0;
    virtual int size() const = 0;

    virtual ~datalink() { }
};
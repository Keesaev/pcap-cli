#pragma once

#include <unordered_set>

#include <protocol-headers/datalink/datalink_protos.hpp>
#include <protocol-headers/network/network_protos.hpp>
#include <protocol-headers/protocol_header.hpp>

class datalink : public protocol_header {
public:
    virtual network_proto_type next_protocol() const = 0;
    virtual ~datalink() { }
};

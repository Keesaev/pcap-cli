#pragma once

#include <unordered_set>

#include "../datalink/datalink_protos.hpp"
#include "../network/network_protos.hpp"
#include "../protocol_header.hpp"

class datalink : public protocol_header {
public:
    virtual network_proto_type next_protocol() const = 0;
    virtual ~datalink() { }
};

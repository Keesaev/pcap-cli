#pragma once

#include "network.hpp"

class unsupported final : public network {
public:
    virtual std::string src_addr() const final { return ""; };
    virtual std::string dst_addr() const final { return ""; };
    // TODO enum
    virtual int next_protocol_type() const final { return -1; };

    virtual ~unsupported() { }
};
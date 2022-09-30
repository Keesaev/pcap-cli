#pragma once

#include "datalink_factory.h"

class unsupported final : public datalink {
public:
    virtual network_proto_type next_protocol() const final
    {
        return network_proto_type::unsupported;
    }
    virtual int size() const final { return 0; };

    virtual ~unsupported() { }
};
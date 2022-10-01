#pragma once

#include "datalink.hpp"

class unsupported_datalink final : public datalink {
public:
    virtual network_proto_type next_protocol() const final
    {
        return network_proto_type::unsupported;
    }
    virtual int proto_size() const final { return 0; };

    virtual ~unsupported_datalink() { }
};
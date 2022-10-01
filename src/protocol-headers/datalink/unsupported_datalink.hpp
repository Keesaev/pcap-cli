#pragma once

#include "datalink.hpp"

class unsupported_datalink final : public datalink {
public:
    virtual network_proto_type next_protocol() const final
    {
        return network_proto_type::unsupported;
    }
    virtual int proto_size() const final { return 0; };
    virtual int size() const final { return 0; };
    virtual const std::pair<std::string, std::string> operator[](std::size_t idx) const final { return { "", "" }; };

    virtual ~unsupported_datalink() { }
};
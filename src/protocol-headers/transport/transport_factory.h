#pragma once

#include <protocol-headers/network/network.hpp>
#include "transport.hpp"

#include <memory>

class transport_factory {
public:
    static std::unique_ptr<transport> make_transport(transport_proto_type type,
        const unsigned char* bytes);
};
#pragma once

#include "../datalink/datalink.hpp"
#include "network.hpp"

#include <memory>

class network_factory {
public:
    static std::unique_ptr<network> make_network(network_proto_type type,
        const unsigned char* bytes);
};
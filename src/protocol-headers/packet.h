#pragma once

#include "datalink/datalink.hpp"
#include "datalink/datalink_factory.h"
#include "network/network.hpp"
#include "network/network_factory.h"

class packet {
    std::unique_ptr<datalink> _datalink;
    std::unique_ptr<network> _network;
    // std::unique_ptr<transport> _transport;
public:
    packet(int datalink_proto, const unsigned char* bytes);
    std::unique_ptr<datalink> const& get_datalink() const { return _datalink; }
    std::unique_ptr<network> const& get_network() const { return _network; }
};
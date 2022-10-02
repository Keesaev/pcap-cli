#pragma once

#include "datalink/datalink_factory.h"
#include "network/network_factory.h"
#include "transport/transport_factory.h"

class packet {
    std::unique_ptr<datalink> _datalink;
    std::unique_ptr<network> _network;
    std::unique_ptr<transport> _transport;

public:
    /**
     * @brief packet - contains datalink, network and transport header
     * @param datalink_proto - proto type received from pcap_datalink method
     * @param bytes - pointer to data containing package
     */
    packet(int datalink_proto, const unsigned char* bytes);
    /**
     * @brief get_datalink - returns ptr reference to datalink object
     */
    std::unique_ptr<datalink> const& get_datalink() const { return _datalink; }
    /**
     * @brief get_network - returns ptr reference to network object
     */
    std::unique_ptr<network> const& get_network() const { return _network; }
    /**
     * @brief get_transport - returns ptr reference to transport object
     */
    std::unique_ptr<transport> const& get_transport() const { return _transport; }
};

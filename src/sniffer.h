#pragma once

#include <pcap/pcap.h>

#include <memory>
#include <string>
#include <vector>

class sniffer {
    std::unique_ptr<pcap_t, void (*)(pcap_t*)> _handle;

    int m_packetCount { 0 };
    bool m_running = false;
    char errbuf[PCAP_ERRBUF_SIZE];

    void capture_one();

public:
    sniffer(std::string const& device_name);
    static std::vector<std::pair<std::string, std::string>> devices();

    bool valid() const { return _handle.get() != nullptr; }
    int link_layer() const;

    void run();
    // void stop();
};
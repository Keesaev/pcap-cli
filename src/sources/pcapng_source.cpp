#include "pcapng_source.h"
#include <protocol-headers/packet.h>

#include <iostream>

pcapng_source::pcapng_source(std::string const& device_name) noexcept(false)
    : _handle { pcap_open_offline(device_name.c_str(), _errbuf),
        [](pcap_t* handle) { pcap_close(handle); } }
{
    if (!_handle.get()) {
        throw pcapng_exception(_errbuf);
    }
}

void pcapng_source::run()
{
    pcap_pkthdr* header;
    const uint8_t* body;
    int res;

    for (;;) {
        int res = pcap_next_ex(_handle.get(), &header, &body);
        if (PCAP_ERROR_BREAK == res) {
            // All packages read
            return;
        } else if (PCAP_ERROR == res) {
            std::cout << pcap_geterr(_handle.get()) << std::endl;
        } else {
            for (const auto& sink : _sinks) {
                // assert LINKTYPE_ETHERNET
                sink->emplace_back(packet(1, body));
            }
        }
    }
}

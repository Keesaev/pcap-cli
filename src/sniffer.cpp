#include "sniffer.h"

#include "protocols/datalink/ethernet_2.h"

#include <iostream> // TODO RM

sniffer::sniffer(std::string const& device_name)
    : _handle { std::unique_ptr<pcap_t, void (*)(pcap_t*)>(
        pcap_create(device_name.c_str(), errbuf),
        [](pcap_t* handle) { pcap_close(handle); }) }
{
    if (_handle.get()) {
        pcap_set_snaplen(_handle.get(), 65535);
        pcap_set_promisc(_handle.get(), 1);
        pcap_set_rfmon(_handle.get(), 0);
        pcap_set_timeout(_handle.get(), 1000);
        pcap_set_immediate_mode(_handle.get(), 1);
        pcap_set_buffer_size(_handle.get(), PCAP_BUF_SIZE);
        pcap_set_tstamp_type(_handle.get(), PCAP_TSTAMP_HOST);
        pcap_activate(_handle.get());
    }
}

void sniffer::run()
{
    capture_one();
}

void sniffer::capture_one()
{
    // struct pcap_pkthdr and the packet data are not to
    // be freed by the caller, and are not guaranteed to be valid
    pcap_pkthdr* header;
    const unsigned char* body;

    if (pcap_next_ex(_handle.get(), &header, &body) != 1) {
        return;
    }

    ethernet_2 datalink = *reinterpret_cast<const ethernet_2*>(body);
    std::cout << datalink.ether_type << std::endl;
}

std::vector<std::pair<std::string, std::string>> sniffer::devices()
{
    std::vector<std::pair<std::string, std::string>> devs;

    pcap_if_t* alldevs;
    int retVal = pcap_findalldevs(&alldevs, nullptr);

    if (retVal != PCAP_ERROR) {
        while (alldevs->next != NULL) {
            devs.push_back({ alldevs->name,
                alldevs->description == nullptr ? "" : alldevs->description });
            alldevs = alldevs->next;
        }
    }
    pcap_freealldevs(alldevs);
    return devs;
}

int sniffer::link_layer() const
{
    return pcap_datalink(_handle.get());
}

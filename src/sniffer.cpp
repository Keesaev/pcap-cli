#include "sniffer.h"

#include <iostream> // TODO RM

std::unordered_map<sniffer_ex_code, std::string> sniffer_exception::_code_strings {
    { sniffer_ex_code::already_activated, "PCAP already activated" },
    { sniffer_ex_code::no_such_device, "No such device" },
    { sniffer_ex_code::perm_denied, "Permission denied" },
    { sniffer_ex_code::promisc_denied, "No permission to put capture into promiscuous mode" },
    { sniffer_ex_code::monitor_not_sup, "Capture source doesn't support monitor mode" },
    { sniffer_ex_code::iface_not_up, "Interface not up" },
    { sniffer_ex_code::generic_err, "Generic error" },
    { sniffer_ex_code::link_layer_not_sup, "Datalink layer not supported" }
};

sniffer::sniffer(std::string const& device_name, std::function<void(packet)> callback)
    : _handle { std::unique_ptr<pcap_t, void (*)(pcap_t*)>(
        pcap_create(device_name.c_str(), errbuf),
        [](pcap_t* handle) { pcap_close(handle); }) }
    , _callback { callback }
{
    if (_handle.get()) {
        pcap_set_snaplen(_handle.get(), 65535);
        pcap_set_promisc(_handle.get(), 1);
        pcap_set_rfmon(_handle.get(), 0);
        pcap_set_timeout(_handle.get(), 1000);
        pcap_set_immediate_mode(_handle.get(), 1);
        pcap_set_buffer_size(_handle.get(), PCAP_BUF_SIZE);
        pcap_set_tstamp_type(_handle.get(), PCAP_TSTAMP_HOST);
        auto act = pcap_activate(_handle.get());

        if (act != 0) {
            throw sniffer_exception(act);
        }

        _datalink_proto = pcap_datalink(_handle.get());
        if (supported_datalink_protos.find(_datalink_proto) == supported_datalink_protos.end()) {
            throw sniffer_exception(sniffer_ex_code::link_layer_not_sup);
        }
    } else {
        throw sniffer_exception(sniffer_ex_code::generic_err);
    }
}

void sniffer::run()
{
    // TODO while(_running)

    for (int i = 0; i < 10; i++) {
        // struct pcap_pkthdr and the packet data are not to
        // be freed by the caller, and are not guaranteed to be valid

        pcap_pkthdr* header;
        const unsigned char* body;

        if (pcap_next_ex(_handle.get(), &header, &body) != 1) {
            continue;
        }
        _callback(packet(_datalink_proto, body));
    }
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

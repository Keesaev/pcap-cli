#include "pcap_helper.h"

#include <pcap/pcap.h>

std::vector<std::pair<std::string, std::string>> pcap_helper::devices()
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

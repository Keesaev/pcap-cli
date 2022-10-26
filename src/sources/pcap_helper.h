#pragma once

#include <vector>
#include <string>

struct pcap_source{
    std::string name;
    std::string description;
};

class pcap_helper{
public:
    static std::vector<pcap_source> devices();
};
#pragma once

#include <vector>
#include <string>

class pcap_helper{
public:
    static std::vector<std::pair<std::string, std::string>> devices();
};
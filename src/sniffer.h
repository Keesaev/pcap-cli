#pragma once

#include <pcap/pcap.h>

#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

enum class sniffer_ex_code {
    already_activated = PCAP_ERROR_ACTIVATED,
    no_such_device = PCAP_ERROR_NO_SUCH_DEVICE,
    perm_denied = PCAP_ERROR_PERM_DENIED,
    promisc_denied = PCAP_ERROR_PROMISC_PERM_DENIED,
    monitor_not_sup = PCAP_ERROR_RFMON_NOTSUP,
    iface_not_up = PCAP_ERROR_IFACE_NOT_UP,
    generic_err = PCAP_ERROR,
    link_layer_not_sup
};

class sniffer_exception final : public std::exception {
    sniffer_ex_code _code;
    static std::unordered_map<sniffer_ex_code, std::string> _code_strings;

public:
    sniffer_exception(int code)
        : _code(static_cast<sniffer_ex_code>(code))
    {
    }
    sniffer_exception(sniffer_ex_code code)
        : _code(code)
    {
    }
    virtual const char* what() const noexcept final
    {
        return _code_strings[_code].c_str();
    }
    sniffer_ex_code code() const noexcept { return _code; }
};

class sniffer {
    std::unique_ptr<pcap_t, void (*)(pcap_t*)> _handle;

    int m_packetCount { 0 };
    bool m_running = false;
    char errbuf[PCAP_ERRBUF_SIZE];
    int _datalink_proto;

public:
    sniffer(std::string const& device_name) noexcept(false);
    static std::vector<std::pair<std::string, std::string>> devices();

    void run();
    // void stop();
};
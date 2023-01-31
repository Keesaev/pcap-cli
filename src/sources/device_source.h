#pragma once

#include <protocol-headers/packet.h>
#include "base_source.hpp"

#include <pcap/pcap.h>

#include <functional>
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

class device_exception final : public source_exception {
    sniffer_ex_code _code;
    static std::unordered_map<sniffer_ex_code, std::string> _code_strings;

public:
    device_exception(int code)
        : _code(static_cast<sniffer_ex_code>(code))
    {
    }
    device_exception(sniffer_ex_code code)
        : _code(code)
    {
    }
    virtual const char* what() const noexcept final
    {
        return _code_strings[_code].c_str();
    }
};

class device_source final : public base_source {
    std::unique_ptr<pcap_t, void (*)(pcap_t*)> _handle;

    int m_packetCount { 0 };
    bool m_running = false;
    char errbuf[PCAP_ERRBUF_SIZE];
    int _datalink_proto;

public:
    device_source(std::string const& device_name) noexcept(false);

    virtual void run() final;
    // TODO
    virtual void stop() final { }
};
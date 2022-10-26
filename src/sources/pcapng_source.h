#pragma once

#include "../protocol-headers/packet.h"
#include "base_source.hpp"

#include <functional>
#include <string>

#include <pcap/pcap.h>

class pcapng_exception final : public source_exception {
    std::string _what;

public:
    pcapng_exception(std::string what)
        : _what(what)
    {
    }
    virtual const char* what() const noexcept final
    {
        return _what.c_str();
    }
};

class pcapng_source final : public base_source {
    std::unique_ptr<pcap_t, void (*)(pcap_t*)> _handle;
    char _errbuf[100];

public:
    pcapng_source(std::string const& device_name) noexcept(false);

    virtual void run() final;
    // TODO
    virtual void stop() final { }
};
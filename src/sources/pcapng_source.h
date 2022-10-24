#pragma once

#include "base_source.hpp"
#include "../protocol-headers/packet.h"

#include <functional>
#include <string>

class pcapng_source final : public base_source {
public:
    pcapng_source(std::string const& device_name, std::function<void(packet)> callback) noexcept(false);

    virtual void run() final;
    // TODO
    virtual void stop() final { }
};
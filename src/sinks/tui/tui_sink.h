#pragma once

#include "../../sources/base_source.hpp"
#include "../../protocol-headers/packet.h"
#include "../sink.h"

#include <memory>

class tui_sink final : public sink {
    std::unique_ptr<base_source> _source;

public:
    virtual void run(std::string const& device) noexcept(false) final;
    virtual void stop() final;

    void print(packet pkt) const;

    virtual ~tui_sink() { }
};
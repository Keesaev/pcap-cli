#pragma once

#include <sinks/sink.h>
#include <vector>

class test_sink final : public sink {
    std::vector<packet> _packets;

public:
    virtual void emplace_back(packet&& p) final;

    std::vector<packet> const& packets() const
    {
        return _packets;
    }

    virtual ~test_sink() { }
};
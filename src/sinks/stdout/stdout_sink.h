#pragma once

#include <sinks/sink.h>

class stdout_sink final : public sink {
    void print(packet const& pkt) const;

public:
    virtual void emplace_back(packet&& p) final;

    virtual ~stdout_sink() { }
};
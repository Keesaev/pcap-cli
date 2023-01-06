#pragma once

#include "../sink.h"

class stdout_sink final : public sink {
    void print(packet const& pkt) const;

public:
    virtual void push_back(packet const& p) final;
    virtual void emplace_back(packet&& p) final;

    virtual ~stdout_sink() { }
};
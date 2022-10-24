#pragma once

#include "../protocol-headers/packet.h"

class sink {
public:
    virtual void push_back(packet const& p) = 0;
    virtual void emplace_back(packet&& p) = 0;

    virtual ~sink() { }
};

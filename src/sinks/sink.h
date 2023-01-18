#pragma once

#include <protocol-headers/packet.h>

class sink {
public:
    virtual void emplace_back(packet&& p) = 0;

    virtual ~sink() { }
};

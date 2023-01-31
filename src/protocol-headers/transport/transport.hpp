#pragma once

#include <protocol-headers/protocol_header.hpp>

class transport : public protocol_header {
public:
    virtual ~transport() { }
};
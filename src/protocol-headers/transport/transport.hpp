#pragma once

#include "../protocol_header.hpp"

class transport : public protocol_header {
public:
    virtual ~transport() { }
};
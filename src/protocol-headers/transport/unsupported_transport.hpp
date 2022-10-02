#pragma once

#include "transport.hpp"

class unsupported_transport final : public transport {
public:
    virtual int header_size() const final { return 0; }
    virtual ~unsupported_transport() { }
};
#pragma once

#include "transport.hpp"

class unsupported_transport final : public transport {
public:
    virtual std::string name() const final { return "Unsupported"; }
    virtual std::string hex() const final { return ""; }
    virtual int header_size() const final { return 0; }
    virtual int field_count() const final { return 0; }
    virtual const std::pair<std::string, std::string> operator[](std::size_t idx) const final { return { "", "" }; }

    virtual ~unsupported_transport() { }
};
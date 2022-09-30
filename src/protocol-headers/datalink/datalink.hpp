#pragma once

#include <string>

class datalink {
public:
    virtual int next_protocol_type() const = 0;

    virtual ~datalink() { }
};
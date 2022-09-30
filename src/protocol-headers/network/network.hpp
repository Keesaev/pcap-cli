#pragma once

#include <string>

class network {
public:
    virtual std::string src_addr() const = 0;
    virtual std::string dst_addr() const = 0;
    virtual int next_protocol_type() const = 0;

    virtual ~network() { }
};
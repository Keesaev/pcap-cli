#pragma once

class transport {
public:
    virtual int proto_size() const = 0;
    virtual ~transport() { }
};
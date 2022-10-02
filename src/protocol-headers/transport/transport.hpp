#pragma once

class transport {
public:
    virtual int header_size() const = 0;
    virtual ~transport() { }
};
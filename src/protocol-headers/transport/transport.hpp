#pragma once

class transport {
public:
    virtual int size() const = 0;
    virtual ~transport() { }
};
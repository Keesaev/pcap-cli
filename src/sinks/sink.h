#pragma once

#include <string>

class sink {
public:
    virtual void run(std::string const& device) noexcept(false) = 0;
    virtual void stop() = 0;

    virtual ~sink() { }
};
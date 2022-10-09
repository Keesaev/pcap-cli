#pragma once

#include <exception>

class source_exception : public std::exception {
public:
    virtual const char* what() const noexcept = 0;
};

class base_source {
public:
    virtual void run() = 0;
    virtual void stop() = 0;
};
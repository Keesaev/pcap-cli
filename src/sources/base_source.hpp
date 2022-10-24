#pragma once

#include <exception>
#include <vector>

#include "../sinks/sink.h"

class source_exception : public std::exception {
public:
    virtual const char* what() const noexcept = 0;
};

class base_source {
protected:
    std::vector<sink*> _sinks;

public:
    virtual void add_sink(sink* s)
    {
        _sinks.push_back(s);
    }
    virtual void run() = 0;
    virtual void stop() = 0;
};
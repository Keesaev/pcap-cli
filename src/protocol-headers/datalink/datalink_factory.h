#pragma once

#include "datalink.hpp"

#include <memory>

class datalink_factory {
public:
    static std::unique_ptr<datalink> make_datalink(int type);
};
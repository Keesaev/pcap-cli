#include "datalink_factory.h"

#include "ethernet_2.h"
#include "unsupported_datalink.hpp"

std::unique_ptr<datalink> datalink_factory::make_datalink(datalink_proto_type type,
    const unsigned char* bytes)
{
    switch (type) {
    case datalink_proto_type::ethernet_2:
        return std::unique_ptr<datalink>(new ethernet_2(bytes));
    default:
        return std::unique_ptr<datalink>(new unsupported_datalink());
    }
}

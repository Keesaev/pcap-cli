#include "datalink_factory.h"

#include "ethernet_2.h"

std::unique_ptr<datalink> datalink_factory::make_datalink(int type)
{
    return std::unique_ptr<datalink>(nullptr);
}

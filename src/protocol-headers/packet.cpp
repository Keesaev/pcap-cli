#include "packet.h"

packet::packet(int datalink_proto, const unsigned char* bytes)
    : _datalink { datalink_factory::make_datalink(static_cast<datalink_proto_type>(datalink_proto), bytes) }
    , _network { network_factory::make_network(_datalink->next_protocol(), bytes + _datalink->size()) }
{
}

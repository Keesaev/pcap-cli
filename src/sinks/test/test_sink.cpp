#include "test_sink.h"

void test_sink::emplace_back(packet&& p)
{
    _packets.emplace_back(std::forward<packet&&>(p));
}
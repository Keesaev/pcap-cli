#include "stdout_sink.h"

#include <sources/device_source.h>

#include <iostream>

void stdout_sink::emplace_back(packet&& p)
{
    print(p);
}

void stdout_sink::print(packet const& pkt) const
{
    for (const auto& layer : pkt.get_all_headers()) {
        std::cout << layer->hex();
    }
    std::cout << std::endl;
    for (const auto& layer : pkt.get_all_headers()) {
        std::cout << layer->name() << '\n'
                  << layer->hex() << '\n';
        for (int i = 0; i < layer->field_count(); i++) {
            auto [value, desc] = (*layer)[i];
            std::cout << '\t' << desc << '\t' << value << '\n';
        }
    }
}
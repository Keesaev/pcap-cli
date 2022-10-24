#include "tui_sink.h"

#include "../../sources/device_source.h"

#include <iostream>

void tui_sink::push_back(packet const& p)
{
    print(p);
}

void tui_sink::emplace_back(packet&& p)
{
    print(p);
}

void tui_sink::print(packet const& pkt) const
{
    for (const auto& layer : pkt.get_all_headers()) {
        std::cout << layer->name() << '\n'
                  << layer->hex() << '\n';
        for (int i = 0; i < layer->field_count(); i++) {
            auto [value, desc] = (*layer)[i];
            std::cout << '\t' << desc << '\t' << value << '\n';
        }
    }
}
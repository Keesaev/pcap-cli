#include "tui_sink.h"

#include <iostream>

void tui_sink::run(std::string const& device)
{
    _sniffer.reset(
        new sniffer(device, std::bind(&tui_sink::print, this, std::placeholders::_1)));
    _sniffer->run();
}

void tui_sink::print(packet pkt) const
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

void tui_sink::stop() { }
#include "sinks/tui/tui_sink.h"
#include <iostream>

int main()
{
    for (const auto& dev : sniffer::devices()) {
        std::cout << dev.first << " " << dev.second << std::endl;
    }

    std::unique_ptr<sniffer> s;
    tui_sink sink;

    try {
        sink.run(sniffer::devices()[0].first);
    } catch (sniffer_exception ex) {
        std::cerr << ex.what() << std::endl;
    }

    return 0;
}

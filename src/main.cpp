#include "sinks/tui/tui_sink.h"
#include <iostream>

#include "src/sources/pcap_helper.h"

int main()
{
    for (const auto& dev : pcap_helper::devices()) {
        std::cout << dev.first << " " << dev.second << std::endl;
    }

    tui_sink sink;

    try {
        sink.run(pcap_helper::devices()[0].first);
    } catch (source_exception &ex) {
        std::cerr << ex.what() << std::endl;
    }

    return 0;
}

#include <iostream>

#include "src/sources/pcap_helper.h"
#include "sinks/tui/tui_sink.h"
#include "sources/device_source.h"
#include "sinks/sink.h"

int main()
{
    for (const auto &[name, desc] : pcap_helper::devices()) {
        std::cout << name << " " << desc << std::endl;
    }

    auto sink = std::unique_ptr<tui_sink>(new tui_sink());
    auto source = std::make_unique<device_source>(pcap_helper::devices()[0].name);
    source->add_sink(sink.get());

    try{
        source->run();
    }
    catch(source_exception &ex){
        std::cout << ex.what() << std::endl;
    }

    return 0;
}

#include <iostream>

#include "sinks/stdout/stdout_sink.h"
#include "sinks/sink.h"

#include "sources/device_source.h"
#include "sources/pcapng_source.h"
#include "sources/pcap_helper.h"

int main()
{
    /*
    for (const auto &[name, desc] : pcap_helper::devices()) {
        std::cout << name << " " << desc << std::endl;
    }*/

    auto sink = std::unique_ptr<stdout_sink>(new stdout_sink());
    ///auto source = std::make_unique<device_source>(pcap_helper::devices()[0].name);
    auto source = std::make_unique<pcapng_source>("../test/tcp_3_packages.pcapng");
    source->add_sink(sink.get());

    try{
        source->run();
    }
    catch(source_exception &ex){
        std::cout << ex.what() << std::endl;
    }

    return 0;
}

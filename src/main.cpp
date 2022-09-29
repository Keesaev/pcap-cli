#include "sniffer.h"
#include <iostream>

int main()
{
    for (const auto& dev : sniffer::devices()) { 
        std::cout << dev.first << " " << dev.second << std::endl;
    }
    sniffer handler(sniffer::devices()[0].first);
    if(handler.valid()){
        handler.run();
    }
    else{
        std::cerr << "invalid" << std::endl;
    }
    return 0;
}
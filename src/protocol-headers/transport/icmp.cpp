#include "icmp.h"

#include <netinet/in.h> // htons

#include <iomanip> // setw, setfill
#include <sstream>

const std::array<std::string, icmp::_field_count> icmp::_descriptions {
    "Type",
    "Code",
    "Checksum"
};

icmp::icmp(const unsigned char* bytes)
    : _data { *reinterpret_cast<const icmp_h*>(bytes) }
{
}

std::string icmp::hex() const
{
    auto bytes = reinterpret_cast<const uint8_t*>(&_data);
    std::stringstream stream;
    for (int i = 0; i < sizeof(icmp); i++) {
        stream << std::setw(2) << std::setfill('0') << std::hex << (int)bytes[i] << ' ';
    }
    return stream.str();
}

const std::pair<std::string, std::string> icmp::operator[](std::size_t idx) const
{
    auto value = [&data = _data](std::size_t idx) -> std::string {
        switch (idx) {
        case 0:
            return std::to_string(data.type);
        case 1:
            return std::to_string(data.code);
        case 2:
            return std::to_string(::htons(data.checksum));
        default:
            return "";
        }
    };
    return { value(idx), _descriptions[idx] };
}

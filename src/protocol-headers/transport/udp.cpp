#include "udp.h"

#include <netinet/in.h> // htons

#include <iomanip> // setw, setfill
#include <sstream>

const std::array<std::string, udp::_field_count> udp::_descriptions {
    "Source Port",
    "Destination Port",
    "Length",
    "Checksum"
};

udp::udp(const unsigned char* bytes)
    : _data { *reinterpret_cast<const udp_h*>(bytes) }
{
}

std::string udp::hex() const
{
    auto bytes = reinterpret_cast<const uint8_t*>(&_data);
    std::stringstream stream;
    for (int i = 0; i < sizeof(udp); i++) {
        stream << std::setw(2) << std::setfill('0') << std::hex << (int)bytes[i] << ' ';
    }
    return stream.str();
}

const std::pair<std::string, std::string> udp::operator[](std::size_t idx) const
{
    auto value = [&data = _data](std::size_t idx) -> std::string {
        switch (idx) {
        case 0:
            return std::to_string(::htons(data.src_port));
        case 1:
            return std::to_string(::htons(data.dst_port));
        case 2:
            return std::to_string(::htons(data.length));
        case 3:
            return std::to_string(::htons(data.checksum));
        default:
            return "";
        }
    };
    return { value(idx), _descriptions[idx] };
}

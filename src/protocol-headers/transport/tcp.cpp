#include "tcp.h"

#include <iostream> // TODO rm

#include <netinet/in.h> // htons

#include <iomanip> // setw, setfill
#include <sstream>

const std::array<std::string, tcp::_field_count> tcp::_descriptions {
    "Source Port",
    "Destination Port",
    "Sequence Number (SN)",
    "Acknowledgment Number (ACK SN)",
    "Data offset (Header length)",
    "Reserved",
    "NS (ECN-nonce)",
    "CWR (Congestion Window Reduced)",
    "ECE (ECN-Echo)",
    "URG",
    "ACK",
    "PSH",
    "RST",
    "SYN",
    "FIN",
    "Window size",
    "Checksum",
    "Urgent Point"
};

tcp::tcp(const unsigned char* bytes)
    : _data { *reinterpret_cast<const tcp_h*>(bytes) }
{
}

std::string tcp::hex() const
{
    auto bytes = reinterpret_cast<const uint8_t*>(&_data);
    std::stringstream stream;
    for (int i = 0; i < sizeof(tcp); i++) {
        stream << std::setw(2) << std::setfill('0') << std::hex << (int)bytes[i] << ' ';
    }
    return stream.str();
}

const std::pair<std::string, std::string> tcp::operator[](std::size_t idx) const
{
    auto value = [&data = _data](std::size_t idx) -> std::string {
        switch (idx) {
        case 0:
            return std::to_string(::htons(data.src_port));
        case 1:
            return std::to_string(::htons(data.dst_port));
        case 2:
            return std::to_string(::htonl(data.seq_num));
        case 3:
            return std::to_string(::htonl(data.ack_num));
        case 4:
            return std::to_string(data.control.data_offset);
        case 5:
            return std::to_string(data.control.reserved);
        case 6:
            return std::to_string(data.control.ns);
        case 7:
            return std::to_string(data.control.cwr);
        case 8:
            return std::to_string(data.control.ece);
        case 9:
            return std::to_string(data.control.urg);
        case 10:
            return std::to_string(data.control.ack);
        case 11:
            return std::to_string(data.control.psh);
        case 12:
            return std::to_string(data.control.rst);
        case 13:
            return std::to_string(data.control.syn);
        case 14:
            return std::to_string(data.control.fin);
        case 15:
            return std::to_string(::htons(data.win_size));
        case 16:
            return std::to_string(::htons(data.checksum));
        case 17:
            return std::to_string(::htons(data.urg_ptr));
        default:
            return "";
        }
    };
    return { value(idx), _descriptions[idx] };
}

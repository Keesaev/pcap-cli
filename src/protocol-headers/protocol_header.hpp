#pragma once

#include <string>

class protocol_header {
public:
    /**
     * @brief name - get protocol name (IPv4, Ethernet II...)
     */
    virtual std::string name() const = 0;
    /**
     * @brief header_size - get header size
     */
    virtual int header_size() const = 0;
    /**
     * @brief field_count - get printable field count
     */
    virtual int field_count() const = 0;
    /**
     * @brief operator[] - get printable header data
     * @param idx - index from 0 to field_count
     * @return pair of strings { value, description }
     */
    virtual const std::pair<std::string, std::string> operator[](std::size_t idx) const = 0;

    virtual ~protocol_header() { }
};

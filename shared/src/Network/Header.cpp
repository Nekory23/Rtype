/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-chloe.chauvin
** File description:
** Header
*/

#include "Network/Header.hpp"

namespace srd::net {
    Header::Header(uint32_t _magic)
        : m_magic(_magic)
    {}

    void Header::setSize(const uint16_t _size)
    {
        m_size = _size;
    }

    void Header::setCode(const uint8_t _code)
    {
        m_code = _code;
    }

    uint16_t Header::getSize() const
    {
        return m_size;
    }

    uint8_t Header::getCode() const
    {
        return m_code;
    }

    sf::Packet &operator<<(sf::Packet &_packet, const Header &_header)
    {
        _packet << _header.m_magic << _header.m_size << _header.m_code;
        return _packet;
    }

    sf::Packet &operator>>(sf::Packet &_packet, const Header &_header)
    {
        uint32_t magic = 0;

        _packet >> magic >> _header.m_size >>  _header.m_code;

        if (_header.m_magic != magic)
            throw Exception("[Packet]", "wrong magic number");
        return _packet;
    }
}

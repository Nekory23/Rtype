/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-chloe.chauvin
** File description:
** Packet
*/

#include "Network/Packet.hpp"

namespace srd::net {
    const void *Packet::onSend(std::size_t &_size)
    {
        sf::Packet packet;

        m_hdr.setSize(getDataSize());
        packet << *this;
        clear();
        *this << m_hdr << packet;
        return getData();
    }

    Packet &Packet::operator<<(sf::Keyboard::Key _key)
    {
        (*this) << static_cast<uint8_t>(_key);
        return (*this);
    }

    Packet &Packet::operator>>(sf::Keyboard::Key &_key)
    {
        uint8_t key = 0;

        (*this) >> key;
        _key = static_cast<sf::Keyboard::Key>(key);
        return (*this);
    }

    Packet &Packet::operator<<(const std::size_t &_n)
    {
        (*this) << static_cast<uint32_t>(_n);
        return (*this);
    }

    Packet &Packet::operator>>(std::size_t &_n)
    {
        uint32_t n = 0;

        (*this) >> n;
        _n = static_cast<std::size_t>(n);
        return (*this);
    }
}
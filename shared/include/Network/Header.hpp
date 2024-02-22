/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-chloe.chauvin
** File description:
** Header
*/

#pragma once

#include <SFML/Network/Packet.hpp>
#include "Network/Exception.hpp"

namespace srd::net {
    class Header {
        public:
            Header(uint32_t _magic = 0xFEA1D75A);
            ~Header() = default;

            void setSize(const uint16_t _size);
            void setCode(const uint8_t _code);
            void setMagic(const uint32_t _magic);

            [[nodiscard]] uint16_t getSize() const;
            [[nodiscard]] uint8_t getCode() const;

            friend sf::Packet &operator<<(sf::Packet &_packet, const Header &_header);
            friend sf::Packet &operator>>(sf::Packet &_packet, const Header &_header);

        private:
            uint32_t m_magic;
            uint16_t m_size;
            uint8_t m_code;
    };
}
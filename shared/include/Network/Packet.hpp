/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-chloe.chauvin
** File description:
** Packet
*/

#pragma once

#include <map>
#include <SFML/Network/Packet.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Keyboard.hpp>

#include "Network/Header.hpp"

namespace srd::net {
    class Packet : public sf::Packet {
        public:
            Packet() = default;
            ~Packet() = default;

            virtual const void *onSend(std::size_t &_size) override;
            virtual void onReceive(const void *_data, std::size_t _size) override;

            template<class T>
            Packet &operator<<(const std::vector<T> &_vec);
            template<class T>
            Packet &operator>>(std::vector<T> &_vec);

            template<class T>
            Packet &operator<<(const sf::Vector2<T> &_vec);
            template<class T>
            Packet &operator>>(sf::Vector2<T> &_vec);

            template<class T, class _T>
            Packet &operator<<(const std::map<T, _T> &_map);
            template<class T, class _T>
            Packet &operator>>(std::map<T, _T> &_map);

            Packet &operator<<(const sf::Keyboard::Key _key);
            Packet &operator>>(sf::Keyboard::Key &_key);

            Packet &operator<<(const std::size_t &_n);
            Packet &operator>>(std::size_t &_n);
        private:
            Header m_hdr;
    };
}

#include "Network/Packet.inl"
/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-chloe.chauvin
** File description:
** Position
*/

#pragma once

#include "Network/Packet.hpp"

namespace srd::ECS::Component {
    class Position {
        public:
            Position(sf::Vector2f _pos = sf::Vector2f(0, 0));
            ~Position() = default;

            sf::Vector2f pos;
    };

    srd::net::Packet &operator<<(srd::net::Packet &_packet, const Position &_position);
    srd::net::Packet &operator>>(srd::net::Packet &_packet, Position &_position);
}
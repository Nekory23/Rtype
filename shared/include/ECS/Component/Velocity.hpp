/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-chloe.chauvin
** File description:
** Velocity
*/

#pragma once

#include <memory>

#include "Network/Packet.hpp"

namespace srd::ECS::Component {
    class Velocity {
        public:
            Velocity(sf::Vector2f _dir = sf::Vector2f(0, 0), float _speed = 0);
            ~Velocity() = default;

            sf::Vector2f dir;
            float speed;
    };

    srd::net::Packet &operator<<(srd::net::Packet &_packet, const Velocity &_velocity);
    srd::net::Packet &operator>>(srd::net::Packet &_packet, Velocity &_velocity);
}
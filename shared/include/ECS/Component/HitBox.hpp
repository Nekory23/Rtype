/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-chloe.chauvin
** File description:
** HitBox
*/

#pragma once

#include "Network/Packet.hpp"

namespace srd::ECS::Component {
    class HitBox {
        public:
            HitBox(sf::Vector2f _size = sf::Vector2f(0, 0));
            ~HitBox() = default;

            sf::Vector2f size;
    };

    srd::net::Packet &operator<<(srd::net::Packet &_packet, const HitBox &_hitbox);
    srd::net::Packet &operator>>(srd::net::Packet &_packet, HitBox &_hitbox);
}
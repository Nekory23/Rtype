/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-chloe.chauvin
** File description:
** Damage
*/

#pragma once

#include "Network/Packet.hpp"

namespace srd::ECS::Component {
    class Damage {
        public:
            Damage(uint8_t _dmg = 0.f);
            ~Damage() = default;

            uint8_t dmg;
    };

    srd::net::Packet &operator<<(srd::net::Packet &_packet, const Damage &_damage);
    srd::net::Packet &operator>>(srd::net::Packet &_packet, Damage &_damage);
}
/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-chloe.chauvin
** File description:
** Weapon
*/

#pragma once

#include "Network/Packet.hpp"

namespace srd::ECS::Component {
    class Weapon {
        public:
            enum class Type {
                Simple,
                Big,
                Fast,
                Focus
            };

            Weapon(Type _type = Type::Simple, float _as = 0.f);
            ~Weapon() = default;

            Type type;
            float as;
    };

    srd::net::Packet &operator<<(srd::net::Packet &_packet, const Weapon::Type _type);
    srd::net::Packet &operator>>(srd::net::Packet &_packet, Weapon::Type &_type);
    srd::net::Packet &operator<<(srd::net::Packet &_packet, const Weapon &_weapon);
    srd::net::Packet &operator>>(srd::net::Packet &_packet, Weapon &_weapon);
}
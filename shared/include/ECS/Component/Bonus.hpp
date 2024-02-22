/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-chloe.chauvin
** File description:
** Bonus
*/

#pragma once

#include "Network/Packet.hpp"

namespace srd::ECS::Component {
    class Bonus {
        public:
            enum class Type {
                FireUp = 0,
                DmgUp,
                Heal,
                NewWeapon
            };

            Bonus(Type _type = Type::FireUp, bool _used = false);
            ~Bonus() = default;

            Type type;
            bool used;
    };

    srd::net::Packet &operator<<(srd::net::Packet &_packet, const Bonus::Type _type);
    srd::net::Packet &operator>>(srd::net::Packet &_packet, Bonus::Type &_type);
    srd::net::Packet &operator<<(srd::net::Packet &_packet, const Bonus &_bonus);
    srd::net::Packet &operator>>(srd::net::Packet &_packet, Bonus &_bonus);
}
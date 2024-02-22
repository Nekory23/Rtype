/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-chloe.chauvin
** File description:
** Damage
*/

#include "ECS/Component/Damage.hpp"

namespace srd::ECS::Component {
    Damage::Damage(uint8_t _dmg)
        : dmg(_dmg)
    {}

    srd::net::Packet &operator<<(srd::net::Packet &_packet, const Damage &_damage)
    {
        _packet << _damage.dmg;
        return _packet;
    }

    srd::net::Packet &operator>>(srd::net::Packet &_packet, Damage &_damage)
    {
        _packet >> _damage.dmg;
        return _packet;
    }
}
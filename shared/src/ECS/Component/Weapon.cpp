/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-chloe.chauvin
** File description:
** Weapon
*/

#include "ECS/Component/Weapon.hpp"

namespace srd::ECS::Component {
    Weapon::Weapon(Type _type, float _as)
        : type(_type), as(_as)
    {}

    srd::net::Packet &operator<<(srd::net::Packet &_packet, const Weapon::Type _type)
    {
        _packet << static_cast<uint8_t>(_type);
        return _packet;
    }

    srd::net::Packet &operator>>(srd::net::Packet &_packet, Weapon::Type &_type)
    {
        uint8_t type = 0;

        _packet >> type;
        _type = static_cast<Weapon::Type>(type);
        return _packet;
    }

    srd::net::Packet &operator<<(srd::net::Packet &_packet, const Weapon &_weapon)
    {
        _packet << _weapon.type << _weapon.as;
        return _packet;
    }

    srd::net::Packet &operator>>(srd::net::Packet &_packet, Weapon &_weapon)
    {
        _packet >> _weapon.type >> _weapon.as;
        return _packet;
    }
}
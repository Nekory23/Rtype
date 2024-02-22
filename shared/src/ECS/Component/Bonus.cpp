/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-chloe.chauvin
** File description:
** Bonus
*/

#include "ECS/Component/Bonus.hpp"

namespace srd::ECS::Component {
    Bonus::Bonus(Type _type, bool _used)
        : type(_type), used(_used)
    {}

    srd::net::Packet &operator<<(srd::net::Packet &_packet, const Bonus::Type _type)
    {
        _packet << static_cast<uint8_t>(_type);
        return _packet;
    }

    srd::net::Packet &operator>>(srd::net::Packet &_packet, Bonus::Type &_type)
    {
        uint8_t type = 0;

        _packet >> type;
        _type = static_cast<Bonus::Type>(type);
        return _packet;
    }

    srd::net::Packet &operator<<(srd::net::Packet &_packet, const Bonus &_bonus)
    {
        _packet << _bonus.type << _bonus.used;
        return _packet;
    }

    srd::net::Packet &operator>>(srd::net::Packet &_packet, Bonus &_bonus)
    {
        _packet >> _bonus.type >> _bonus.used;
        return _packet;
    }
}
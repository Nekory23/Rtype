/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-chloe.chauvin
** File description:
** Vie
*/

#include "ECS/Component/Vie.hpp"

namespace srd::ECS::Component {
    Vie::Vie(uint8_t _pv)
        : pv(_pv)
    {}

    srd::net::Packet &operator<<(srd::net::Packet &_packet, const Vie &_vie)
    {
        _packet << _vie.pv;
        return _packet;
    }

    srd::net::Packet &operator>>(srd::net::Packet &_packet, Vie &_vie)
    {
        _packet >> _vie.pv;
        return _packet;
    }
}
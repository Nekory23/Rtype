/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-chloe.chauvin
** File description:
** Velocity
*/

#include "ECS/Component/Velocity.hpp"

namespace srd::ECS::Component {
    Velocity::Velocity(sf::Vector2f _dir, float _speed)
        : dir(_dir), speed(_speed)
    {}

    srd::net::Packet &operator<<(srd::net::Packet &_packet, const Velocity &_velocity)
    {
        _packet << _velocity.dir << _velocity.speed;
        return _packet;
    }

    srd::net::Packet &operator>>(srd::net::Packet &_packet, Velocity &_velocity)
    {
        _packet >> _velocity.dir >> _velocity.speed;
        return _packet;
    }
}
/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-chloe.chauvin
** File description:
** Position
*/

#include "ECS/Component/Position.hpp"

namespace srd::ECS::Component {
    Position::Position(sf::Vector2f _pos)
        : pos(_pos)
    {}

    srd::net::Packet &operator<<(srd::net::Packet &_packet, const Position &_position)
    {
        _packet << _position.pos;
        return _packet;
    }

    srd::net::Packet &operator>>(srd::net::Packet &_packet, Position &_position)
    {
        _packet >> _position.pos;
        return _packet;
    }
}
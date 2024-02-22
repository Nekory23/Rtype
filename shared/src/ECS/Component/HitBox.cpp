/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-chloe.chauvin
** File description:
** HitBox
*/

#include "ECS/Component/HitBox.hpp"

namespace srd::ECS::Component {
    HitBox::HitBox(sf::Vector2f _size)
        : size(_size)
    {}

    srd::net::Packet &operator<<(srd::net::Packet &_packet, const HitBox &_hitbox)
    {
        _packet << _hitbox.size;
        return _packet;
    }

    srd::net::Packet &operator>>(srd::net::Packet &_packet, HitBox &_hitbox)
    {
        _packet >> _hitbox.size;
        return _packet;
    }
}

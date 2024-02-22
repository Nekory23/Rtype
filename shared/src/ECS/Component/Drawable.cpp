/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-chloe.chauvin
** File description:
** Drawable
*/

#include "ECS/Component/Drawable.hpp"

namespace srd::ECS::Component {
    Drawable::Drawable(const srd::asset::Container &_container, std::size_t _id)
        : id(_id)
    {
        sprite.setTexture(*_container.textureAt(_id));
    }

    srd::net::Packet &operator<<(srd::net::Packet &_packet, const Drawable &_drawable)
    {
        _packet << _drawable;
        return _packet;
    }

    srd::net::Packet &operator>>(srd::net::Packet &_packet, Drawable &_drawable)
    {
        _packet >> _drawable;
        return _packet;
    }
}
/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-chloe.chauvin
** File description:
** Drawable
*/

#pragma once

#include <SFML/Graphics/Sprite.hpp>

#include "Asset/Container.hpp"
#include "Network/Packet.hpp"

namespace srd::ECS::Component {
    class Drawable {
        public:
            Drawable() = default;
            Drawable(const srd::asset::Container &_container, std::size_t _id = 0);
            ~Drawable() = default;

            sf::Sprite sprite;
            std::size_t id = 0;
    };

    srd::net::Packet &operator<<(srd::net::Packet &_packet, const Drawable &_drawable);
    srd::net::Packet &operator>>(srd::net::Packet &_packet, Drawable &_drawable);
}
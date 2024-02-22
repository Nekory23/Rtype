/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-chloe.chauvin
** File description:
** Event
*/

#pragma once

#include <map>
#include <SFML/Window/Keyboard.hpp>

#include "ECS/Action.hpp"
#include "Network/Packet.hpp"

namespace srd::ECS::Component {
    class Event {
        public:

            using Map = std::map<sf::Keyboard::Key, ::srd::ECS::ActionType>;

            Event(Map&_map);
            ~Event() = default;

               Map map;
     };

    srd::net::Packet &operator<<(srd::net::Packet &_packet, const Event &_event);
    srd::net::Packet &operator>>(srd::net::Packet &_packet, Event &_event);
     srd::net::Packet &operator<<(srd::net::Packet &_packet, const ActionType &_action);
     srd::net::Packet &operator>>(srd::net::Packet &_packet, ActionType &_action);
}
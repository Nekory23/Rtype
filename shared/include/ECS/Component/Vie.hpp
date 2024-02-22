/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-chloe.chauvin
** File description:
** Vie
*/

#pragma once

#include "Network/Packet.hpp"

namespace srd::ECS::Component {
    class Vie {
        public:
            Vie(uint8_t _pv = 0);
            ~Vie() = default;

            uint8_t pv;
    };

    srd::net::Packet &operator<<(srd::net::Packet &_packet, const Vie &_vie);
    srd::net::Packet &operator>>(srd::net::Packet &_packet, Vie &_vie);
}
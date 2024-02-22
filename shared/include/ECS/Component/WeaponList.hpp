/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-chloe.chauvin
** File description:
** WeaponList
*/

#pragma once

#include "Network/Packet.hpp"

namespace srd::ECS::Component {
    class WeaponList {
        public:
            WeaponList(std::vector<std::size_t> &_list);
            ~WeaponList() = default;

            std::vector<std::size_t> list;
    };

    srd::net::Packet &operator<<(srd::net::Packet &_packet, const WeaponList &_lweapon);
    srd::net::Packet &operator>>(srd::net::Packet &_packet, WeaponList &_lweapon);
}
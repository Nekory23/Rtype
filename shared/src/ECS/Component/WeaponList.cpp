/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-chloe.chauvin
** File description:
** WeaponList
*/

#include "ECS/Component/WeaponList.hpp"

namespace srd::ECS::Component {
    WeaponList::WeaponList(std::vector<std::size_t> &_list)
        : list(_list) {}

    srd::net::Packet &operator<<(srd::net::Packet &_packet, const WeaponList &_lweapon)
    {
        _packet << _lweapon.list;
        return _packet;
    }

    srd::net::Packet &operator>>(srd::net::Packet &_packet, WeaponList &_lweapon)
    {
        _packet >> _lweapon.list;
        return _packet;
    }
}
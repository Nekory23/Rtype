/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-chloe.chauvin
** File description:
** AI
*/

#include "ECS/Component/AI.hpp"

namespace srd::ECS::Component {
    AI::AI(Strat _strat)
        : strat(_strat)
    {}

    srd::net::Packet &operator<<(srd::net::Packet &_packet, const AI::Strat _strat)
    {
        _packet << static_cast<uint8_t>(_strat);
        return _packet;
    }

    srd::net::Packet &operator>>(srd::net::Packet &_packet, AI::Strat &_strat)
    {
        uint8_t strat = 0;

        _packet >> strat;
        _strat = static_cast<AI::Strat>(strat);
        return _packet;
    }

    srd::net::Packet &operator<<(srd::net::Packet &_packet, const AI &_ai)
    {
        _packet << _ai.strat;
        return _packet;
    }

    srd::net::Packet &operator>>(srd::net::Packet &_packet, AI &_ai)
    {
        _packet >> _ai.strat;
        return _packet;
    }
}
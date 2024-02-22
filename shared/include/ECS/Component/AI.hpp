/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-chloe.chauvin
** File description:
** AI
*/

#pragma once

#include "Network/Packet.hpp"

namespace srd::ECS::Component {
    class AI {
        public:
            enum class Strat {
                RunIn,
                Safe,
                Forward,
                Static
            };

            AI(Strat _strat = Strat::Static);
            ~AI() = default;

            Strat strat;
    };

    srd::net::Packet &operator<<(srd::net::Packet &_packet, const AI::Strat _strat);
    srd::net::Packet &operator>>(srd::net::Packet &_packet, AI::Strat &_strat);
    srd::net::Packet &operator<<(srd::net::Packet &_packet, const AI &_ai);
    srd::net::Packet &operator>>(srd::net::Packet &_packet, AI &_ai);
}
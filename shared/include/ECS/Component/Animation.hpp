/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-chloe.chauvin
** File description:
** Animation
*/

#pragma once

#include "Network/Packet.hpp"

#include <SFML/System/Clock.hpp>

namespace srd::ECS::Component {
    class Animation {
        public:
            Animation(sf::Vector2u _tsize = sf::Vector2u(0, 0),
                sf::Vector2u _ntsize = sf::Vector2u(0, 0), sf::Vector2u _act = sf::Vector2u(0, 0),
                float _time = 1.f, bool _run = false);
            ~Animation() = default;

            sf::Vector2u tsize;
            sf::Vector2u ntsize;
            sf::Vector2u act;
            float time;
            sf::Clock clock;
            bool run;
    };

    srd::net::Packet &operator<<(srd::net::Packet &_packet, const Animation &_anim);
    srd::net::Packet &operator>>(srd::net::Packet &_packet, Animation &_anim);

    namespace AnimationType {
        class OnDeath : public Animation {
            public:
                OnDeath(sf::Vector2u _tsize = sf::Vector2u(0, 0),
                    sf::Vector2u _ntsize = sf::Vector2u(0, 0), sf::Vector2u _act = sf::Vector2u(0, 0),
                    float _time = 1.f, bool _run = false);
                ~OnDeath() = default;
        };

        class OnSpwan : public Animation {
            public:
                OnSpwan(sf::Vector2u _tsize = sf::Vector2u(0, 0),
                    sf::Vector2u _ntsize = sf::Vector2u(0, 0), sf::Vector2u _act = sf::Vector2u(0, 0),
                    float _time = 1.f, bool _run = false);
                ~OnSpwan() = default;
        };

        class Continue : public Animation {
            public:
                Continue(sf::Vector2u _tsize = sf::Vector2u(0, 0),
                    sf::Vector2u _ntsize = sf::Vector2u(0, 0), sf::Vector2u _act = sf::Vector2u(0, 0),
                    float _time = 1.f, bool _run = false);
                ~Continue() = default;
        };
    }
}
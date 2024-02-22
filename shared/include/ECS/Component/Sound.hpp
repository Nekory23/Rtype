/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-chloe.chauvin
** File description:
** Sound
*/

#pragma once

#include <memory>
#include <SFML/Audio/Music.hpp>

#include "Asset/Container.hpp"
#include "Network/Packet.hpp"

namespace srd::ECS::Component {
    class Sound {
        public:
            Sound() = default;
            Sound(const srd::asset::Container &_container, std::size_t _id = 0);
            virtual ~Sound() = default;

            std::size_t id;
            std::shared_ptr<sf::Music> sound;
    };

    srd::net::Packet &operator<<(srd::net::Packet &_packet, const Sound &_sound);
    srd::net::Packet &operator>>(srd::net::Packet &_packet, Sound &_sound);

    namespace SoundType {
        class OnDeath : public Sound {
            public:
                OnDeath() = default;
                OnDeath(const srd::asset::Container &_container, std::size_t _id = 0, bool _played = false);
                ~OnDeath() = default;

                bool played;
        };

        class OnSpwan : public Sound {
            public:
                OnSpwan() = default;
                OnSpwan(const srd::asset::Container &_container, std::size_t _id = 0, bool _played = false);
                ~OnSpwan() = default;

                bool played;
        };

        class Continue : public Sound {
            public:
                Continue() = default;
                Continue(const srd::asset::Container &_container, std::size_t _id = 0);
                ~Continue() = default;
        };
    }
}
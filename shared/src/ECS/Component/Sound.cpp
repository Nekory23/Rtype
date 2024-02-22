/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-chloe.chauvin
** File description:
** Sound
*/

#include "ECS/Component/Sound.hpp"

namespace srd::ECS::Component {
    Sound::Sound(const srd::asset::Container &_container, std::size_t _id)
        : id(_id), sound(_container.musicdAt(id))
    {}

    srd::net::Packet &operator<<(srd::net::Packet &_packet, const Sound &_sound)
    {
        _packet << _sound.id;
        return _packet;
    }

    srd::net::Packet &operator>>(srd::net::Packet &_packet, Sound &_sound)
    {
        _packet >> _sound.id;
        return _packet;
    }

    namespace SoundType {
        OnDeath::OnDeath(const srd::asset::Container &_container, std::size_t _id, bool _played)
            : Sound(_container, _id), played(_played)
        {}

        OnSpwan::OnSpwan(const srd::asset::Container &_container, std::size_t _id, bool _played)
            : Sound(_container, _id), played(_played)
        {}

        Continue::Continue(const srd::asset::Container &_container, std::size_t _id)
            : Sound(_container, _id)
        {}
    }
}
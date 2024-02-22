/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-chloe.chauvin
** File description:
** Animation
*/

#include "ECS/Component/Animation.hpp"

namespace srd::ECS::Component {
    Animation::Animation(sf::Vector2u _tsize, sf::Vector2u _ntsize,
        sf::Vector2u _act, float _time, bool _run)
        : tsize(_tsize), ntsize(_ntsize), act(_act), time(_time), run(_run)
    {
        clock.restart();
    }

    srd::net::Packet &operator<<(srd::net::Packet &_packet, const Animation &_anim)
    {
        _packet << _anim.tsize << _anim.ntsize << _anim.act << _anim.time << _anim.run;
        return _packet;
    }

    srd::net::Packet &operator>>(srd::net::Packet &_packet, Animation &_anim)
    {
        _packet >> _anim.tsize >> _anim.ntsize >> _anim.act >> _anim.time >> _anim.run;
        return _packet;
    }

    namespace AnimationType {
        OnDeath::OnDeath(sf::Vector2u _tsize, sf::Vector2u _ntsize,
        sf::Vector2u _act, float _time, bool _run)
            : Animation(_tsize, _ntsize, _act, _time, _run)
        {}

        OnSpwan::OnSpwan(sf::Vector2u _tsize, sf::Vector2u _ntsize,
        sf::Vector2u _act, float _time, bool _run)
            : Animation(_tsize, _ntsize, _act, _time, _run)
        {}

        Continue::Continue(sf::Vector2u _tsize, sf::Vector2u _ntsize,
        sf::Vector2u _act, float _time, bool _run)
            : Animation(_tsize, _ntsize, _act, _time, _run)
        {}
    }
}
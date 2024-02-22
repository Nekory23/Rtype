/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-chloe.chauvin
** File description:
** Animation
*/

#include "ECS/System.hpp"

namespace srd::ECS::System {
    void animation(srd::ECS::Registry &_reg)
    {
        animationContinue(_reg);
        animationOnDeath(_reg);
        animationOnSpawn(_reg);
    }

    void animationContinue(srd::ECS::Registry &_reg)
    {
        auto& anim = _reg.getComponents<Component::AnimationType::Continue>();
        auto& animod = _reg.getComponents<Component::AnimationType::OnDeath>();
        auto& animos = _reg.getComponents<Component::AnimationType::OnSpwan>();
        auto& draw = _reg.getComponents<Component::Drawable>();

        for (std::size_t it = 0; it < anim.size(); it++) {
            if (!anim[it] || !draw[it] || !anim[it].value().run)
                continue;
            if ((it < animod.size() && !animod[it] && animod[it].value().run)
                || (it < animos.size() && !animos[it] && animos[it].value().run))
                continue;
            Component::AnimationType::Continue *_anim = &anim[it].value();

            std::cout << _anim->clock.getElapsedTime().asSeconds() << std::endl;
            if (_anim->clock.getElapsedTime().asSeconds() >= _anim->time) {
                _anim->act.x += 1;
                if (_anim->act.x >= _anim->ntsize.x)
                    _anim->act.x = 0;
                draw[it].value().sprite.setTextureRect(
                    sf::IntRect(_anim->act.x * _anim->tsize.x, _anim->act.y * _anim->tsize.y,
                        _anim->tsize.x, _anim->tsize.y));
                _anim->clock.restart();
            }
        }
    }

    void animationOnDeath(srd::ECS::Registry &_reg)
    {
        auto& anim = _reg.getComponents<Component::AnimationType::Continue>();
        auto& animod = _reg.getComponents<Component::AnimationType::OnDeath>();
        auto& animos = _reg.getComponents<Component::AnimationType::OnSpwan>();
        auto& draw = _reg.getComponents<Component::Drawable>();

        for (std::size_t it = 0; it < animod.size(); it++) {
            if (!animod[it] || !draw[it] || !animod[it].value().run)
                continue;
            if (it < animos.size() && !animos[it] && animos[it].value().run)
                continue;
            Component::AnimationType::OnDeath *_anim = &animod[it].value();

            if (_anim->clock.getElapsedTime().asSeconds() >= _anim->time) {
                _anim->act.x += 1;
                if (_anim->act.x >= _anim->ntsize.x)
                    _anim->act.x = 0;
                draw[it].value().sprite.setTextureRect(
                    sf::IntRect(_anim->act.x * _anim->tsize.x, _anim->act.y * _anim->tsize.y,
                        _anim->tsize.x, _anim->tsize.y));
                _anim->clock.restart();
            }
        }
    }

    void animationOnSpawn(srd::ECS::Registry &_reg)
    {
        auto& anim = _reg.getComponents<Component::AnimationType::Continue>();
        auto& animod = _reg.getComponents<Component::AnimationType::OnDeath>();
        auto& animos = _reg.getComponents<Component::AnimationType::OnSpwan>();
        auto& draw = _reg.getComponents<Component::Drawable>();

        for (std::size_t it = 0; it < animos.size(); it++) {
            if (!animos[it] || !draw[it] || !animos[it].value().run)
                continue;
            if (it < animod.size() && !animod[it] && animod[it].value().run)
                continue;
            Component::AnimationType::OnDeath *_anim = &animod[it].value();

            if (_anim->clock.getElapsedTime().asSeconds() >= _anim->time) {
                _anim->act.x += 1;
                if (_anim->act.x >= _anim->ntsize.x)
                    _anim->act.x = 0;
                draw[it].value().sprite.setTextureRect(
                    sf::IntRect(_anim->act.x * _anim->tsize.x, _anim->act.y * _anim->tsize.y,
                        _anim->tsize.x, _anim->tsize.y));
                _anim->clock.restart();
            }
        }
    }
}
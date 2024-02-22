/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-chloe.chauvin
** File description:
** Sound
*/

#include "ECS/System.hpp"

namespace srd::ECS::System {
    void sound(srd::ECS::Registry &_reg)
    {
        soundContinue(_reg);
        soundOnDeath(_reg);
        soundOnSpawn(_reg);
    }

    void soundContinue(srd::ECS::Registry &_reg)
    {
        auto &sound = _reg.getComponents<Component::SoundType::Continue>();

        for (std::size_t it = 0; it < sound.size(); it++) {
            if (!sound[it])
                continue;
            if (sound[it].value().sound->getStatus() != sf::Music::Status::Playing) {
                sound[it].value().sound->play();
                sound[it].value().sound->setLoop(true);
            }
        }
    }

    void soundOnDeath(srd::ECS::Registry &_reg)
    {
        auto &sound = _reg.getComponents<Component::SoundType::OnDeath>();
        const auto &vie = _reg.getComponents<Component::Vie>();

        for (std::size_t it = 0; it < sound.size() && it < vie.size(); it++) {
            if (!sound[it] || !vie[it])
                continue;
            if (vie[it].value().pv <= 0) {
                if (sound[it].value().sound->getStatus() == sf::Music::Status::Stopped
                    && sound[it].value().played) {
                    // kill entity;
                } else if (sound[it].value().sound->getStatus() != sf::Music::Status::Playing) {
                    sound[it].value().sound->play();
                    sound[it].value().played = true;
                }
            }
        }
    }

    void soundOnSpawn(srd::ECS::Registry &_reg)
    {
        auto &sound = _reg.getComponents<Component::SoundType::OnSpwan>();

        for (std::size_t it = 0; it < sound.size(); it++) {
            if (!sound[it] || sound[it].value().played)
                continue;
            if (sound[it].value().sound->getStatus() != sf::Music::Status::Playing) {
                sound[it].value().sound->play();
                sound[it].value().played = true;
            }
        }
    }
}
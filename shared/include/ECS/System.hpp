/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-chloe.chauvin
** File description:
** System
*/

#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

#include "ECS/Registry.hpp"
#include "ECS/Component/Component.hpp"
#include "ECS/EventQueue.hpp"

namespace srd::ECS::System {
    void animation(srd::ECS::Registry &_reg);
    void animationContinue(srd::ECS::Registry &_reg);
    void animationOnDeath(srd::ECS::Registry &_reg);
    void animationOnSpawn(srd::ECS::Registry &_reg);

    void actionEvent(srd::ECS::Registry &_reg, srd::ECS::EventQueue &_qevent, srd::ECS::Event &_event);

    void draw(sf::RenderWindow &_win, srd::ECS::Registry &_reg);

    void event(srd::ECS::Registry &_reg, srd::ECS::EventQueue &_event);

    void move(srd::ECS::Registry &_reg);

    void sound(srd::ECS::Registry &_reg);
    void soundContinue(srd::ECS::Registry &_reg);
    void soundOnDeath(srd::ECS::Registry &_reg);
    void soundOnSpawn(srd::ECS::Registry &_reg);
}
/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-chloe.chauvin
** File description:
** Move
*/

#include "ECS/System.hpp"

namespace srd::ECS::System {
    void move(srd::ECS::Registry &_reg)
    {
        auto &pos = _reg.getComponents<Component::Position>();
        auto &vel = _reg.getComponents<Component::Velocity>();

        for (std::size_t it = 0; it < pos.size() && it < vel.size(); it++) {
            if (!vel[it] || !pos[it])
                continue;
            pos[it].value().pos.x += vel[it].value().speed * vel[it].value().dir.x;
            pos[it].value().pos.y += vel[it].value().speed * vel[it].value().dir.y;
        }
    }
}
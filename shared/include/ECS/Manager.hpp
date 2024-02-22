/*
** EPITECH PROJECT, 2021
** R-Type
** File description:
** Manager
*/

#pragma once

#include "ECS/Container.hpp"
#include "ECS/Entity.hpp"

namespace srd::ECS {
    class Manager {
        public:

            Manager() = default;
            ~Manager() = default;

            Entity spaw();
            Entity at(std::size_t _pos);
            void kill(const Entity &_entity);

        protected:
            std::vector<Entity> m_entity;
    };
}
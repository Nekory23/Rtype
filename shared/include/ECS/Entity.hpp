/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-chloe.chauvin
** File description:
** Entity
*/

#pragma once

#include <cstdlib>

namespace srd::ECS {
    class Entity {
        friend class Manager;
        public:
            ~Entity() = default;

            void kill();

            std::size_t m_id;
            bool m_alive;

        private:
            Entity(std::size_t _id);
    };
}
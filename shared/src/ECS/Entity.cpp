/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-chloe.chauvin
** File description:
** Entity
*/

#include "ECS/Entity.hpp"

namespace srd::ECS {
    Entity::Entity(std::size_t _id)
        : m_id(_id), m_alive(true)
    {}

    void Entity::kill()
    {
        m_alive = false;
    }
}
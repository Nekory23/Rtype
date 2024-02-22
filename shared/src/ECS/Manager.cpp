/*
** EPITECH PROJECT, 2021
** R-Type
** File description:
** Manager
*/

#include <algorithm>

#include "ECS/Manager.hpp"

namespace srd::ECS {
    Entity Manager::spaw()
    {
        static std::size_t id = 0;

        m_entity.push_back(Entity(id++));
        return m_entity.back();
    }

    Entity Manager::at(std::size_t _pos)
    {
        return m_entity.at(_pos);
    }

    void Manager::kill(const Entity &_entity)
    {
        std::vector<Entity>::iterator it = std::find_if(m_entity.begin(), m_entity.end(), [_entity] (const Entity &_nentity) {
            return (_entity.m_id == _nentity.m_id);
        });
        (*it).m_alive = false;
    }
}

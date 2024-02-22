/*
** EPITECH PROJECT, 2021
** R-Type
** File description:
** Registry
*/

#include "ECS/Registry.hpp"

namespace srd::ECS {
    template<class Component>
    Container<Component> &Registry::registerComponent()
    {
        std::type_index index = std::type_index(typeid(Component));

        if (!m_comp.contains(index)) {
            m_comp[index] = Container<Component>();
            m_del[index] = [](Registry &_reg, Entity &_entity) {
                _reg.getComponents<Component>().erase(_entity.m_id);
            };
        }
        return getComponents<Component>();
    }

    template<class Component>
    Container<Component> &Registry::getComponents()
    {
        std::type_index index = std::type_index(typeid(Component));

        return std::any_cast<Container<Component> &>(m_comp[index]);
    }

    template <class Component>
    const Container<Component> &Registry::getComponents() const
    {
        std::type_index index = std::type_index(typeid(Component));

        return std::any_cast<Container<Component> &>(m_comp.at(index));
    }

    template<typename Component>
    typename Container<Component>::ref_type Registry::addComponent(const Entity &_entity, Component &&_comp)
    {
        return getComponents<Component>().insert_at(_entity.m_id, _comp);
    }

    template<typename Component, typename... Params>
    typename Container<Component>::ref_type Registry::emplaceComponent(const Entity &_entity, Params &&..._param)
    {
        return getComponents<Component>().emplace_at(_entity.m_id, std::forward<Params>(_param)...);
    }

    template<typename Component>
    void Registry::removeComponent(const Entity &_entity)
    {
        for (auto &[index, func] : m_del)
            func(*this, _entity);
    }
}
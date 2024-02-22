/*
** EPITECH PROJECT, 2021
** R-Type
** File description:
** Registry
*/

#pragma once

#include <any>
#include <functional>
#include <typeindex>
#include <unordered_map>
#include <iostream>

#include "ECS/Container.hpp"

namespace srd::ECS {
    class Registry {
        public :
            template<class Component>
            Container<Component> &registerComponent();

            template<class Component>
            [[nodiscard]] Container<Component> &getComponents();
            template <class Component>
            [[nodiscard]] const Container<Component> &getComponents() const;

            template<typename Component>
            typename Container<Component>::ref_type addComponent(const Entity &_entity, Component &&_comp);
            template<typename Component, typename... Params>
            typename Container<Component>::ref_type emplaceComponent(const Entity &_entity, Params &&..._param);
            template<typename Component>
            void removeComponent(const Entity &_entity);

        private:
            std::unordered_map<std::type_index, std::any> m_comp;
            std::unordered_map<std::type_index, std::function<void(Registry &, Entity &)>> m_del;
    };
}

#include "Registry.inl"
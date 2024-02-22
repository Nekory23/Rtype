/*
** EPITECH PROJECT, 2021
** R-Type
** File description:
** Container
*/

#pragma once

#include <optional>
#include <memory>
#include <type_traits>
#include <vector>

#include "ECS/Entity.hpp"

namespace srd::ECS {
    template<typename Component>
    class Container {
        public:
            using type = std::optional<Component>;
            using ref_type = type &;
            using const_ref_type = const type &;
            using container_t = std::vector<type>;
            using size_type = typename container_t::size_type;
            using iterator = typename container_t::iterator;
            using const_iterator = typename container_t::const_iterator;

            Container() = default;
            Container(Container const &_cont);
            Container(Container &&_cont) noexcept;
            ~Container() = default;

            Container &operator=(Container const &_cont);
            Container &operator=(Container &&_cont) noexcept;
            ref_type operator[](size_t _pos);
            const_ref_type operator[](size_t _pos) const;

            iterator begin();
            const_iterator begin() const;
            const_iterator cbegin() const;
            iterator end();
            const_iterator end() const;
            const_iterator cend() const;

            [[nodiscard]] size_type size() const;
            // get_index?
            [[nodiscard]] size_type get_index(type const &_type) const;

            ref_type insert_at(size_type _pos, Component const &_comp);
            ref_type insert_at(size_type _pos, Component &&_comp);
            template<class... Params>
            ref_type emplace_at(size_type _pos, Params &&..._comp);
            void erase(size_type _pos);

        private:
            container_t m_data;
    };
}

#include "Container.inl"
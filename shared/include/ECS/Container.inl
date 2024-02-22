/*
** EPITECH PROJECT, 2021
** R-Type
** File description:
** Container
*/

#include "ECS/Container.hpp"

namespace srd::ECS {
    template<typename Component>
    Container<Component>::Container(Container const &_cont)
        : m_data(_cont.m_data)
    {}

    template<typename Component>
    Container<Component>::Container(Container &&_cont) noexcept
        : m_data(std::move(_cont.m_data))
    {}

    template<typename Component>
    Container<Component> &Container<Component>::operator=(Container<Component> const &_cont)
    {
        m_data = _cont.m_data;
    }

    template<typename Component>
    Container<Component> &Container<Component>::operator=(Container<Component> &&_cont) noexcept
    {
        m_data = std::move(_cont.m_data);
    }

    template<typename Component>
    typename Container<Component>::ref_type Container<Component>::operator[](size_t _pos)
    {
        return m_data[_pos];
    }

    template<typename Component>
    typename Container<Component>::const_ref_type Container<Component>::operator[](size_t _pos) const
    {
        return m_data[_pos];
    }

    template<typename Component>
    typename Container<Component>::iterator Container<Component>::begin()
    {
        return m_data.begin();
    }

    template<typename Component>
    typename Container<Component>::const_iterator Container<Component>::begin() const
    {
        return m_data.begin();
    }

    template<typename Component>
    typename Container<Component>::const_iterator Container<Component>::cbegin() const
    {
        return m_data.cbegin();
    }

    template<typename Component>
    typename Container<Component>::iterator Container<Component>::end()
    {
        return m_data.end();
    }

    template<typename Component>
    typename Container<Component>::const_iterator Container<Component>::end() const
    {
        return m_data.end();
    }

    template<typename Component>
    typename Container<Component>::const_iterator Container<Component>::cend() const
    {
        return m_data.cend();
    }

    template<typename Component>
    typename Container<Component>::size_type Container<Component>::size() const
    {
        return m_data.size();
    }

    template<typename Component>
    typename Container<Component>::ref_type Container<Component>::insert_at(size_type _pos, Component const &_comp)
    {
        if (_pos > m_data.size())
            m_data.resize(_pos);
        else
            erase(_pos);
        m_data.insert_at(_pos, _comp);
    }

    template<typename Component>
    typename Container<Component>::ref_type Container<Component>::insert_at(size_type _pos, Component &&_comp)
    {
        if (_pos + 1 > m_data.size())
            m_data.resize(_pos + 1);
        else
            erase(_pos);
        m_data.insert_at(_pos, _comp);
    }

    template<typename Component>
    template<class... Params>
    typename Container<Component>::ref_type Container<Component>::emplace_at(size_type _pos, Params &&..._comp)
    {
        if (_pos + 1 > m_data.size())
            m_data.resize(_pos + 1);
        m_data.at(_pos) = std::make_optional<Component>(std::forward<Params>(_comp)...);
        return m_data.at(_pos);
    }

    template<typename Component>
    void Container<Component>::erase(size_type _pos)
    {
        m_data.at(_pos) = std::nullopt;
    }

    template<typename Component>
    typename Container<Component>::size_type Container<Component>::get_index(type const &_type) const
    {
        size_type index = 0;

        for (; index < m_data.size(); index++)
            if (std::is_same<decltype(_type), decltype(m_data[index])>::value)
                return index;
        return std::numeric_limits<size_type>::max();
    }
}
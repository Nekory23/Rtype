/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-chloe.chauvin
** File description:
** Packet
*/

#include "Network/Packet.hpp"
#include "ECS/Component/Component.hpp"

namespace srd::net {
    template<class T>
    Packet &Packet::operator<<(const std::vector<T> &_vec)
    {
        (*this) << static_cast<uint32_t>(_vec.size());
        for (T _elem : _vec)
            (*this) << _elem;
        return (*this);
    }

    template<class T>
    Packet &Packet::operator>>(std::vector<T> &_vec)
    {
        uint32_t size = 0;
        T elem;

        (*this) << size;
        _vec.resize(size);
        for (uint32_t it = 0; it < size; it++) {
            (*this) >> elem;
            _vec.push_back(elem);
        }
        return (*this);
    }

    template<class T>
    Packet &Packet::operator<<(const sf::Vector2<T> &_vec)
    {
        (*this) << _vec.x << _vec.y;
        return (*this);
    }

    template<class T>
    Packet &Packet::operator>>(sf::Vector2<T> &_vec)
    {
        (*this) >> _vec.x >> _vec.y;
        return (*this);
    }

    template<class T, class _T>
    Packet &Packet::operator<<(const std::map<T, _T> &_map)
    {
        (*this) << static_cast<uint32_t>(_map.size());
        for (const std::pair<T, _T> _pair : _map)
            (*this) << _pair.first << _pair.second;
        return (*this);
    }

    template<class T, class _T>
    Packet &Packet::operator>>(std::map<T, _T> &_map)
    {
        uint32_t size = 0;
        T first;
        _T second;

        (*this) >> size;
        for (uint32_t it = 0; it < size; it++) {
            (*this) >> first >> second;
            _map[first] = std::move(second);
        }
        return (*this);
    }
}
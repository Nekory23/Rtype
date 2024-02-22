/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-chloe.chauvin
** File description:
** Event
*/

#pragma once

#include "ECS/Action.hpp"

namespace srd::ECS {
    class Event {
        public:
            enum class Type {
                Position,
                Damage,
                Spawn,
                Action
            };

            enum class ActionState {
                Release,
                Presse
            };

            struct _Action {
                ActionType type;
                ActionState state;
            };

            struct _Damage {
                uint8_t hp;
            };

            struct _Position {
                sf::Vector2f pos;
            };

            struct _Spawn {
                _Position pos;
                uint16_t compid;
            };

            Type type;
            std::size_t entity;

            union {
                _Damage dmg;
                _Position pos;
                _Spawn spawn;
                _Action action;
            };
    };
}
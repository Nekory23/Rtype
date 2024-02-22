/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-chloe.chauvin
** File description:
** Event
*/

#include "ECS/System.hpp"

namespace srd::ECS::System {
    void event(srd::ECS::Registry &_reg, srd::ECS::EventQueue &_event)
    {
		srd::ECS::Event event = { .type = Event::Type::Action, .entity = 0 };

        while (!_event.empty()) {
            event = _event.pop();
            switch (event.type) {
                case srd::ECS::Event::Type::Action:
					actionEvent(_reg, _event, event);
                    break;
            }
        }
    }

    void actionEvent(srd::ECS::Registry &_reg, srd::ECS::EventQueue &_qevent, srd::ECS::Event &_event)
    {
        auto &vel = _reg.getComponents<Component::Velocity>();

        if (!vel[_event.entity] || _event.action.type == srd::ECS::ActionType::None)
            return;
        if (_event.action.state == srd::ECS::Event::ActionState::Presse) {
            if (_event.action.type == srd::ECS::ActionType::Up)
                vel[_event.entity].value().dir.y = -1;
            else if (_event.action.type == srd::ECS::ActionType::Down)
                vel[_event.entity].value().dir.y = 1;
            else if (_event.action.type == srd::ECS::ActionType::Right)
                vel[_event.entity].value().dir.x = 1;
            else if (_event.action.type == srd::ECS::ActionType::Left)
                vel[_event.entity].value().dir.x = -1;
        } else {
            if (_event.action.type == srd::ECS::ActionType::Up
                || _event.action.type == srd::ECS::ActionType::Down)
                vel[_event.entity].value().dir.y = 0;
            else if (_event.action.type == srd::ECS::ActionType::Right
                || _event.action.type == srd::ECS::ActionType::Left)
                vel[_event.entity].value().dir.x = 0;
        }
        if (_event.action.type == srd::ECS::ActionType::Fire) {}
    }
}
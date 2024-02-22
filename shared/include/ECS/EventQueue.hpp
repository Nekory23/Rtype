/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-chloe.chauvin
** File description:
** EventQueue
*/

#pragma once

#include <queue>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

#include "Event.hpp"
#include "Registry.hpp"

namespace srd::ECS {
    class EventQueue {
        public:
            EventQueue() = default;
            ~EventQueue() = default;

            void pollEvent(Registry &_reg, sf::RenderWindow &_win);

            Event pop();
            void push(Event _ev);

            [[nodiscard]] bool empty() const;

        private:
            std::queue<Event> m_queue;
    };
}
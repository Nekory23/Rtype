/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-chloe.chauvin
** File description:
** EventQueue
*/

#include "ECS/EventQueue.hpp"

#include "ECS/Component/Component.hpp"

namespace srd::ECS {
    void EventQueue::pollEvent(Registry &_reg, sf::RenderWindow &_win)
    {
        sf::Event sfevent;
        std::map<Event::ActionState, sf::Keyboard::Key> lkey;
        auto &cevent = _reg.getComponents<Component::Event>();

        while (_win.pollEvent(sfevent)) {
            if (sfevent.type == sf::Event::Closed)
                _win.close();
            else if (sfevent.type == sf::Event::KeyPressed)
                lkey.insert(std::pair<Event::ActionState, sf::Keyboard::Key>(Event::ActionState::Presse, sfevent.key.code));
            else if (sfevent.type == sf::Event::KeyReleased)
                lkey.insert(std::pair<Event::ActionState, sf::Keyboard::Key>(Event::ActionState::Release, sfevent.key.code));
        }
        for (std::size_t it = 0; it < cevent.size(); it++) {
            if (!cevent[it])
                continue;
            for (auto [key, val] : lkey) {
                Event sevent = { .type = Event::Type::Action, .entity = it };
                if (cevent[it].value().map.contains(val)) {
                    sevent.action.type = cevent[it].value().map[val];
                    sevent.action.state = key;
                    push(sevent);
                }
            }
        }
    }

    Event EventQueue::pop()
    {
        Event event = m_queue.front();

        m_queue.pop();
        return event;
    }

    void EventQueue::push(Event _ev)
    {
        m_queue.push(_ev);
    }

    bool EventQueue::empty() const
    {
        return m_queue.empty();
    }
}

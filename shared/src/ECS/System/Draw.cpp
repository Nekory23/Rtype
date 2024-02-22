/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-chloe.chauvin
** File description:
** Draw
*/

#include "ECS/System.hpp"

namespace srd::ECS::System {
    void draw(sf::RenderWindow &_win, srd::ECS::Registry &_reg)
    {
        auto const &pos = _reg.getComponents<Component::Position>();
        auto &draw = _reg.getComponents<Component::Drawable>();

        for (std::size_t it = 0; it < pos.size() && it < draw.size(); it++) {
            if (!draw[it] || !pos[it])
                continue;
            draw[it].value().sprite.setPosition(pos[it].value().pos);
            _win.draw(draw[it].value().sprite);
        }
    }
}
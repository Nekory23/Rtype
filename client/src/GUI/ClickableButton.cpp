/*
** EPITECH PROJECT, 2021
** 
** File description:
** 
*/

#include "Widget.hpp"

rtype::ClickableButton::ClickableButton(std::shared_ptr<sf::Texture> texture): AWidget<1, 2>(texture)
{
    auto &eventTriggerType0 = std::get<0>(_eventsTriggers[0]);
    eventTriggerType0 = sf::Event::MouseButtonPressed;
}

void rtype::ClickableButton::draw(sf::RenderWindow &window)
{
    auto &[eventTriggerType, isTriggered, sfEvent, func] = _eventsTriggers[0];
    if (isTriggered && this->isHovering(sfEvent)) {
            window.draw(_sprites[1]);
            if (func) {
                func(window);
            }
            return;
    }
    window.draw(_sprites[0]);
}

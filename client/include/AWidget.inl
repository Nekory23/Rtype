/*
** EPITECH PROJECT, 2021
** AWidget
** File description:
** AWidget template class implementation
*/

#ifndef _RTYPE_AWIDGET_INL
#define _RTYPE_AWIDGET_INL

#include "Widget.hpp"

template<std::size_t E, std::size_t S>
void AWidget<E, S>::bind(const sf::Event::EventType &eventType, const std::function<void(sf::RenderWindow &window)> &func) {
    for (auto &[eventTriggerType, _, __, callback]: _eventsTriggers) {
        if (eventTriggerType == eventType)
            callback = func;
    }
}

template<std::size_t E, std::size_t S>
void AWidget<E, S>::handleEvent(const sf::Event &event) {
    for (auto &[eventTriggerType, isTriggered, internalEvent, _]: _eventsTriggers) {
        if (eventTriggerType == event.type) {
            isTriggered = true;
            internalEvent = event;
        } else {
            isTriggered = false;
        }
    }
}

template<std::size_t E, std::size_t S>
void AWidget<E, S>::createSprite(const sf::IntRect &spriteCoordinates, const std::size_t &spriteIndx) {
    _sprites[spriteIndx].setTextureRect(spriteCoordinates);
}

template<std::size_t E, std::size_t S>
void AWidget<E, S>::setPosition(const sf::Vector2f &pos, const std::size_t &spriteIndx) {
    _sprites[spriteIndx].setPosition(pos);
}

template<std::size_t E, std::size_t S>
bool AWidget<E, S>::isHovering(const sf::Event &event) {
    // if (!event.type == sf::Event::MouseButtonPressed || !event.type == sf::Event::MouseButtonReleased)
    //     throw error;
    sf::FloatRect rect = _sprites[0].getGlobalBounds();
    return rect.contains(event.mouseButton.x, event.mouseButton.y);
}

template<std::size_t E, std::size_t S>
void ATextWidget<E, S>::setPosition(const sf::Vector2f &spritePos, const sf::Vector2f &textPos, const std::size_t &spriteIndx) {
    this->AWidget<E, S>::setPosition(spritePos, spriteIndx);
    _text.setPosition(textPos);
    _savedText.setPosition(textPos);
}

#endif /* _RTYPE_AWIDGET_INL */
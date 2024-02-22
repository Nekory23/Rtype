/*
** EPITECH PROJECT, 2021
** B-CPP_Rtype
** File description:
** Slider
*/

#include "Widget.hpp"

rtype::Slider::Slider(std::shared_ptr<sf::Texture> texture) : AWidget<2, 2>(texture)
{
    auto &eventTriggerType0 = std::get<0>(_eventsTriggers[0]);
    auto &eventTriggerType1 = std::get<0>(_eventsTriggers[1]);
    eventTriggerType0 = sf::Event::MouseButtonPressed;
    eventTriggerType1 = sf::Event::MouseMoved;
    _value = 50;
}

static float computeValue(float position, int left)
{
    float res = ((position - left) * 100) / 530;

    return res;
}

static sf::Vector2f moveSprite(sf::Event event, sf::Vector2f curPos)
{
    sf::Vector2f newPos = {static_cast<float>(event.mouseMove.x), curPos.y};

    return newPos;
}

bool rtype::Slider::checkPositions(sf::Event event) const
{
    if (event.mouseMove.x >= _leftBorder && event.mouseMove.x <= _rightBorder)
        return true;
    return false;
}

void rtype::Slider::draw(sf::RenderWindow &window)
{
    auto &[eventTriggerType0, isTriggered0, sfEvent0, func0] = _eventsTriggers[0];
    auto &[eventTriggerType1, isTriggered1, sfEvent1, func1] = _eventsTriggers[1];
    
    if (isTriggered0 && this->isHovering(sfEvent0)) {
        if (checkPositions(sfEvent1)) {
            _sprites[1].setPosition(moveSprite(sfEvent1, _sprites[1].getPosition()));
        }
        _value = computeValue(_sprites[1].getPosition().x, _leftBorder);
        if (func0)
            func0(window);
        std::cout << "value = " << _value << std::endl;
    }
    window.draw(_sprites[0]);
    window.draw(_sprites[1]);
}

const float &rtype::Slider::getValue() const
{
    return _value;
}

void rtype::Slider::setRightBorder(int right)
{
    _rightBorder = right;
}

void rtype::Slider::setLeftBorder(int left)
{
    _leftBorder = left;
}

void rtype::Slider::setCenterCircle(int x, int y)
{
    _sprites[1].setOrigin(x, y);
}
/*
** EPITECH PROJECT, 2021
** B-CPP_Rtype
** File description:
** UpdateButton
*/

#include "Widget.hpp"

rtype::UpdateButton::UpdateButton(std::shared_ptr<sf::Texture> texture, std::shared_ptr<sf::Font> font) : ATextWidget<3, 1>(texture, font)
{
    auto &eventTriggerType0 = std::get<0>(_eventsTriggers[0]);
    auto &eventTriggerType1 = std::get<0>(_eventsTriggers[1]);
    auto &eventTriggerType2 = std::get<0>(_eventsTriggers[2]);
    eventTriggerType0 = sf::Event::MouseButtonPressed;
    eventTriggerType1 = sf::Event::TextEntered;
    eventTriggerType2 = sf::Event::KeyPressed;
    _isFocused = false;
}

void rtype::UpdateButton::draw(sf::RenderWindow &window)
{
    static bool isTextBeingEntered = false;

    auto &[_0, isMousePressed_E, sfEvent0, __0] = _eventsTriggers[0];
    auto &[_1, isTextEntered_E, sfEvent1, __1] = _eventsTriggers[1];
    auto &[_2, isKeyPressed_E, sfEvent2, func2] = _eventsTriggers[2];

    if (isMousePressed_E && isHovering(sfEvent0))
        _isFocused = true;
    if (_isFocused && isKeyPressed_E && sfEvent2.key.code == sf::Keyboard::Escape) {
        _isFocused = false;
        _inputBuffer = _savedText.getString();
        _text.setString(_inputBuffer);
    }
    if (_isFocused) {
        window.draw(_sprites[0]);
        if (isTextEntered_E) {
            //if (sfEvent1.text.unicode != ANSI_ENTER_CODE && sfEvent1.text.unicode != ANSI_ESCAPE_CODE)
            //    _inputBuffer = static_cast<std::string>(sfEvent1.text.unicode);
            isTextEntered_E = false;
            _text.setString(_inputBuffer);
        }
        window.draw(_text);
        return;
    }
}

void rtype::UpdateButton::setLabel(const std::string &label)
{
    _label = label;
}

void rtype::UpdateButton::setTextColor(const sf::Color &color)
{
    _text.setFillColor(color);
    _savedText.setFillColor(color);
}

const char &rtype::UpdateButton::getKey() const
{
    return _key;
}
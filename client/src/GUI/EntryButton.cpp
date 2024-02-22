/*
** EPITECH PROJECT0, 2021
** EntryButton
** File description:
** Methods implementation for EntryButton, a widget class
** that handles input text from the user
*/

#include "Widget.hpp"

rtype::EntryButton::EntryButton(std::shared_ptr<sf::Texture> texture, std::shared_ptr<sf::Font> font): ATextWidget<3, 1>(texture, font), _isFocused(false)
{
    auto &eventTriggerType0 = std::get<0>(_eventsTriggers[0]);
    auto &eventTriggerType1 = std::get<0>(_eventsTriggers[1]);
    auto &eventTriggerType2 = std::get<0>(_eventsTriggers[2]);
    eventTriggerType0 = sf::Event::MouseButtonPressed;
    eventTriggerType1 = sf::Event::TextEntered;
    eventTriggerType2 = sf::Event::KeyPressed;
}

void rtype::EntryButton::draw(sf::RenderWindow &window)
{
    static bool isTextBeingEntered = false;

    auto &[_0, isMouseButtonPressed_E, sfEvent0, __0] = _eventsTriggers[0];
    auto &[_1, isTextEntered_E, sfEvent1, __1] = _eventsTriggers[1];
    auto &[_2, isKeyPressed_E, sfEvent2, func2] = _eventsTriggers[2];

    if (isMouseButtonPressed_E && this->isHovering(sfEvent0)) {
        _isFocused = true;
    }
    if (_isFocused && isKeyPressed_E && sfEvent2.key.code == sf::Keyboard::Escape) {
        _isFocused = false;
        _inputBuffer = _savedText.getString();
        _text.setString(_inputBuffer);
    }
    if (_isFocused) {
        window.draw(_sprites[0]);
        if (isTextEntered_E) {
            if (sfEvent1.text.unicode != ANSI_ENTER_CODE && sfEvent1.text.unicode != ANSI_ESCAPE_CODE)
                _inputBuffer += sfEvent1.text.unicode;
            isTextBeingEntered = true;
            isTextEntered_E = false;
            _text.setString(_inputBuffer);
        }
        if (isTextBeingEntered) {
            isTextBeingEntered = false;
            if (sfEvent1.text.unicode ==  ANSI_ENTER_CODE) {
                _isFocused = false;
                _savedText.setString(_text.getString());
                if (func2)
                    func2(window);
            } else if (sfEvent1.text.unicode == ANSI_ESCAPE_CODE) {
                _inputBuffer.erase(_inputBuffer.getSize() - 1);
                _text.setString(_inputBuffer);
            }
        }
        window.draw(_text);
        return;
    }
    if (_savedText.getString().isEmpty())
        window.draw(_sprites[0]);
    else
        window.draw(_savedText);
}

void rtype::EntryButton::setTextColor(const sf::Color &color)
{
    _text.setFillColor(color);
    _savedText.setFillColor(color);
}

std::string rtype::EntryButton::getText() const
{
    return this->_savedText.getString();
}

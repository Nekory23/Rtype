/*
** EPITECH PROJECT, 2021
** Widget.cpp
** File description:
** Widget class implementation based on SFML lib
*/

#include "IMenu.hpp"

void rtype::Menu::draw(sf::RenderWindow &window)
{
    for (auto &widget : _widgets)
        widget->draw(window);
}

void rtype::Menu::addWidget(IWidget *widget)
{
    this->_widgets.emplace_back(widget);
}

void rtype::Menu::handleEvent(const sf::Event &event)
{
    for (auto &widget: _widgets)
        widget->handleEvent(event);
}
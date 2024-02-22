/*
** EPITECH PROJECT, 2021
** 
** File description:
** 
*/

#ifndef _RTYPE_IMENU_HPP
#define _RTYPE_IMENU_HPP

#include "Widget.hpp"

namespace rtype {

class IMenu {
    public:
        virtual ~IMenu() = default;
        virtual void draw(sf::RenderWindow &window) = 0;
        virtual void addWidget(IWidget *widget) = 0;
        virtual void handleEvent(const sf::Event &event) = 0;
};

class Menu : public IMenu {
    private:
        std::vector<IWidget*> _widgets{};
    public:
        Menu() = default;
        ~Menu() = default;
        void draw(sf::RenderWindow &window) override final;
        void addWidget(IWidget *widget) override final;
        void handleEvent(const sf::Event &event) override final;
};

}

#endif /* _RTYPE_IMENU_HPP */
/*
** EPITECH PROJECT, 2021
** Widget.cpp
** File description:
** IWidget, AWidget and subsequent class declarations
*/

#ifndef _RTYPE_WIDGET_HPP
#define _RTYPE_WIDGET_HPP

#include <functional>
#include <array>
#include <tuple>
#include <utility>
#include <memory>
#include <string>
#include <iostream>

#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderTexture.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/System/String.hpp>

namespace rtype {

static const int ANSI_ENTER_CODE = 10;
static const int ANSI_ESCAPE_CODE = 8;

class IWidget {
    public:
        virtual ~IWidget() = default;
        virtual void bind(const sf::Event::EventType &eventType, const std::function<void(sf::RenderWindow &window)> &func) = 0;
        virtual void handleEvent(const sf::Event &event) = 0;           //inside pollEvent loop - implemented in AWidget
        virtual void createSprite(const sf::IntRect &spriteCoordinates, const std::size_t &spriteIndx = 0) = 0;
        virtual void setPosition(const sf::Vector2f &pos, const std::size_t &spriteIndx = 0) = 0;
        virtual void draw(sf::RenderWindow &window) = 0;                //after pollEvent loop - implemented in AWidget
        virtual bool isHovering(const sf::Event &event) = 0;
};

/*
** Widgets Abstract Classes
*/

template<std::size_t E, std::size_t S>
class AWidget : public IWidget {
    protected:
        using event_trigger_tup = std::tuple<sf::Event::EventType, bool, sf::Event, std::function<void(sf::RenderWindow &)>>;
        /*
        ** template parameters: E = number of events that widget will handle
        **                      S = number of sprites that widget is gonna contain
        */
        std::array<sf::Sprite, S> _sprites{};
        std::array<event_trigger_tup, E> _eventsTriggers{};

        explicit AWidget<E, S>(std::shared_ptr<sf::Texture> texture) {
            for (auto &sprite : _sprites)
                sprite.setTexture(*texture);
        }
        ~AWidget() = default;

    public:
        void bind(const sf::Event::EventType &eventType, const std::function<void(sf::RenderWindow &window)> &func) override;
        void handleEvent(const sf::Event &event) override;
        void createSprite(const sf::IntRect &spriteCoordinates, const std::size_t &spriteIndx = 0) override;
        void setPosition(const sf::Vector2f &pos, const std::size_t &spriteIndx = 0) override;
        bool isHovering(const sf::Event &event) override;
        virtual void draw(sf::RenderWindow &window) override = 0;
}; 

template <std::size_t E, std::size_t S>
class ATextWidget : public AWidget<E, S> {
    using AWidget<E, S>::setPosition;
    protected:
        sf::Text _text{};
        sf::Text _savedText{};
        ATextWidget(std::shared_ptr<sf::Texture> texture, std::shared_ptr<sf::Font> font): AWidget<E, S>(texture) {
            // (if !_text.setFont(font))
            // throw Error
            _text.setFont(*font);
            _savedText.setFont(*font);
        }
        ~ATextWidget() = default;
    public:
        void draw(sf::RenderWindow &window) override = 0;
        void setPosition(const sf::Vector2f &spritePos, const sf::Vector2f &textPos, const std::size_t &spriteIndx = 0);
};

#include "AWidget.inl" /* Including template functions for AWidget class template */

/*
** Widgets Classes
*/

class ClickableButton : public AWidget<1, 2> {
    public:
        explicit ClickableButton(std::shared_ptr<sf::Texture> texture);
        ~ClickableButton() = default;
        void draw(sf::RenderWindow &window) override final;
};

class EntryButton : public ATextWidget<3, 1> {
    private:
        sf::String _inputBuffer{};
        bool _isFocused;
    public:
        EntryButton(std::shared_ptr<sf::Texture> texture, std::shared_ptr<sf::Font> font);
        ~EntryButton() = default;
        void draw(sf::RenderWindow &window) override final;
        void setTextColor(const sf::Color &color);
        std::string getText() const;
};

class UpdateButton : public ATextWidget<3, 1> {
    public:
        explicit UpdateButton(std::shared_ptr<sf::Texture> texture, std::shared_ptr<sf::Font> font);
        ~UpdateButton() = default;
        void draw(sf::RenderWindow &window) override final;

        void setLabel(const std::string &label);
        void setTextColor(const sf::Color &color);
        const char &getKey() const;

    private:
        std::string _label;
        std::string _inputBuffer;
        char _key;
        bool _isFocused;
};

class Slider : public AWidget<2, 2> {
    public:
        explicit Slider(std::shared_ptr<sf::Texture> texture);
        ~Slider() = default;
        void draw(sf::RenderWindow &window) override final;
        bool checkPositions(sf::Event event) const;

        const float &getValue() const;
        void setRightBorder(int right);
        void setLeftBorder(int left);
        void setCenterCircle(int x, int y);
    
    private:
        float _value;
        int _rightBorder;
        int _leftBorder;
};

/*
Widgets to be implemented:
  - Bouton                    simple bouton cliquable
  - Slider                    curseur qui glisse entre le maximum et minimum
  - Bouton d'entré            bouton cliquable, qui quand il est cliqué permet d'entre du texte
  - Bouton de mise à jour     bouton cliquable, qui quand il est cliqué permet d'enregistre une entré clavier
  - Menu                      class de gestion de menu
*/

/*
** Donc pour créer un widget:
** - Déclarer sa classe dans ce fichier, en faisant attention aux paramètres des templates
** puis créer un <nom_du_widget>.cpp, dans lequel:
** définir le constructeur:
** - en appelant le constructeur de AWidget
** - en assignant les sf::Event::<event_type> au premier parametre des tuples dans l'array des tuples _eventsTriggers
** définir draw:
** qui va se charger de definir ce que le widget va draw selon l'event qui été triggered dans _eventsTriggers
*/

}


#endif /* _RTYPE_WIDGET_HPP */


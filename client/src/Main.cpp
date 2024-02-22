/*
** EPITECH PROJECT, 2021
** Rtype
** File description:
** Main
*/

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

#include "Asset/Container.hpp"
// #include "ECS/Manager.hpp"
// #include "ECS/System.hpp"
// #include "ECS/EventQueue.hpp"
#include "IMenu.hpp"

int main()
{
    sf::RenderWindow win({ 2560, 1600 }, "test");
    srd::asset::Container data;
    // srd::ECS::Registry reg;
    // srd::ECS::Manager manager;
    // srd::ECS::Entity entity = manager.spaw();
    // srd::ECS::EventQueue event;
    // std::map<sf::Keyboard::Key, srd::ECS::ActionType> map = {
    //     { sf::Keyboard::Key::Z, srd::ECS::ActionType::Up },
    //     { sf::Keyboard::Key::S, srd::ECS::ActionType::Down },
    //     { sf::Keyboard::Key::Q, srd::ECS::ActionType::Left },
    //     { sf::Keyboard::Key::D, srd::ECS::ActionType::Right }
    // };

    // reg.registerComponent<srd::ECS::Component::Position>();
    // reg.registerComponent<srd::ECS::Component::Velocity>();
    // reg.registerComponent<srd::ECS::Component::Drawable>();
    // reg.registerComponent<srd::ECS::Component::Event>();
    // reg.registerComponent<srd::ECS::Component::Vie>();
    // reg.registerComponent<srd::ECS::Component::SoundType::Continue>();
    // reg.registerComponent<srd::ECS::Component::SoundType::OnSpwan>();
    // reg.registerComponent<srd::ECS::Component::SoundType::OnDeath>();
    // reg.registerComponent<srd::ECS::Component::AnimationType::Continue>();
    // reg.registerComponent<srd::ECS::Component::AnimationType::OnSpwan>();
    // reg.registerComponent<srd::ECS::Component::AnimationType::OnDeath>();

    // reg.emplaceComponent<srd::ECS::Component::Position>(entity, sf::Vector2f(10, 10));
    // reg.emplaceComponent<srd::ECS::Component::Velocity>(entity, sf::Vector2f(1, 0), 1.f);
    // reg.emplaceComponent<srd::ECS::Component::Drawable>(entity, data, 1);
    // reg.emplaceComponent<srd::ECS::Component::Event>(entity, map);
    // reg.emplaceComponent<srd::ECS::Component::Vie>(entity, 10);
    // // reg.emplaceComponent<srd::ECS::Component::SoundType::Continue>(entity, data, 1);
    // reg.emplaceComponent<srd::ECS::Component::SoundType::OnSpwan>(entity, data, 2);
    // reg.emplaceComponent<srd::ECS::Component::AnimationType::Continue>(entity, sf::Vector2u(64, 64), sf::Vector2u(5, 1), sf::Vector2u(0, 0), 0.5, true);

    // auto buttonTexture = ;
    rtype::ClickableButton button(data.textureAt(2));
    button.createSprite({0, 0, 180, 180}, 0);        // This is the function to define the rectangle
    button.createSprite({0, 180, 180, 185}, 1);   // that the sprite occupies on the texture, I don't know the exact shapes sizes (on the texture), I wanted to be able to run to correctly define them
    button.setPosition({500, 500});
    button.setPosition({500, 500}, 1);
    rtype::EntryButton entryButton(data.textureAt(3), data.fontAt(1));
    entryButton.createSprite({150, 200, 950, 150}, 0);
    entryButton.setPosition({500, 800}, {575, 850}, 0);
    entryButton.setTextColor(sf::Color::Black);
    rtype::Slider slider(data.textureAt(4));
    slider.createSprite({20, 20, 530, 20}, 0);
    slider.setPosition({100, 100}, 0);
    slider.setLeftBorder(50);
    slider.setRightBorder(580);
    slider.createSprite({250, 40, 60, 60}, 1);
    slider.setPosition({360, 105}, 1);
    slider.setCenterCircle(30, 30);
    rtype::Menu mainMenu;
    mainMenu.addWidget(&button);
    mainMenu.addWidget(&entryButton);
    mainMenu.addWidget(&slider);
    std::size_t lastSize = 0;
    std::size_t size = 0;
    while (win.isOpen()) {
        sf::Event sfEvent;
        // event.pollEvent(reg, win);
        // srd::ECS::System::event(reg, event);
        // srd::ECS::System::move(reg);
        // srd::ECS::System::sound(reg);
        // srd::ECS::System::animation(reg);
        while (win.pollEvent(sfEvent))
        {
            if (sfEvent.type == sf::Event::Closed)
                win.close();
            mainMenu.handleEvent(sfEvent);
        }
        win.clear(sf::Color::White);
        // srd::ECS::System::draw(win, reg);
        try {
            mainMenu.draw(win);
            if ((size = entryButton.getText().size()) != lastSize) {
                std::cout << "Text inside widget = " << entryButton.getText() << std::endl;
                lastSize = size;
            }
        } catch (std::exception &e) {
            std::cerr << e.what() << std::endl;
        }
        win.display();
    }
    return 0;
}
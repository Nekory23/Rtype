/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-chloe.chauvin
** File description:
** Container
*/

#pragma once

#include <map>
#include <memory>
#include <SFML/Audio/Music.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <string>

#include "Asset/Exception.hpp"

namespace srd::asset {
    class Container {
        public:
            Container(const std::string &_path = "bin/asset.config");
            ~Container() = default;

            void clear();
            void load(const std::string &_path);

            [[nodiscard]] std::shared_ptr<sf::Texture> textureAt(std::size_t _pos) const;
            [[nodiscard]] std::shared_ptr<sf::Music> musicdAt(std::size_t _pos) const;
            [[nodiscard]] std::shared_ptr<sf::Font> fontAt(std::size_t _pos) const;

        private:
            std::string getFolder(const std::string &_path);

            std::map<std::size_t, std::shared_ptr<sf::Font>> m_font;
            std::map<std::size_t, std::shared_ptr<sf::Texture>> m_txtr;
            std::map<std::size_t, std::shared_ptr<sf::Music>> m_music;
    };
}
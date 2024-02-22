/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-chloe.chauvin
** File description:
** Container
*/

#include <fstream>
#include <sstream>

#include "Asset/Container.hpp"

namespace srd::asset {
    Container::Container(const std::string &_path)
    {
        load(_path);
    }

    void Container::clear()
    {
        m_font.clear();
        m_txtr.clear();
        m_music.clear();
    }

    void Container::load(const std::string &_path)
    {
        std::fstream file(_path, std::ios::in);
        std::string line, fpath, type;
        std::istringstream stream;
        std::size_t id;
        std::string folder = getFolder(_path);

        if (!file.is_open())
            throw Exception("[Container]", "can't open the file: \"" + _path + "\"");
        while (std::getline(file, line)) {
            stream.str(line);
            stream >> type;
            if (type.empty())
                continue;
            stream >> id >> fpath;
            if (!id)
                throw Exception("[Container]", "can't parse the id", _path, line);
            if (fpath.empty())
                throw Exception("[Container]", "no path found", _path, line);
            if (type == "[texture]") {
                if (m_txtr.contains(id))
                    throw Exception("[Container][Texture]", "id already used", _path, line);
                m_txtr[id] = std::make_shared<sf::Texture>();
                if (!m_txtr[id]->loadFromFile(folder + fpath))
                    throw Exception("[Container][Texture]", "can't open the file: \"" + folder + fpath + "\"", _path, line);
            } else if (type == "[music]") {
                if (m_music.contains(id))
                    throw Exception("[Container][Music]", "id already used", _path, line);
                m_music[id] = std::make_shared<sf::Music    >();
                if (!m_music[id]->openFromFile(folder + fpath))
                    throw Exception("[Container][Music]", "can't open the file: \"" + folder + fpath + "\"", _path, line);
            } else if (type == "[font]") {
                if (m_font.contains(id))
                    throw Exception("[Container][Font]", "id already used", _path, line);
                m_font[id] = std::make_shared<sf::Font>();
                if (!m_font[id]->loadFromFile(folder + fpath))
                    throw Exception("[Container][Font]", "can't open the file: \"" + folder + fpath + "\"", _path, line);
            }
            stream.clear();
        }
        file.close();
    }

    std::shared_ptr<sf::Texture> Container::textureAt(std::size_t _pos) const
    {
        if (!m_txtr.contains(_pos))
            throw Exception("[Container][Texture]", "unknow id: " + _pos);
        return m_txtr.at(_pos);
    }

    std::shared_ptr<sf::Music> Container::musicdAt(std::size_t _pos) const
    {
        if (!m_music.contains(_pos))
            throw Exception("[Container][Sound]", "unknow id: " + _pos);
        return m_music.at(_pos);
    }

    std::shared_ptr<sf::Font> Container::fontAt(std::size_t _pos) const
    {
        if (!m_font.contains(_pos))
            throw Exception("[Container][Font]", "unknow id: " + _pos);
        return m_font.at(_pos);
    }

    std::string Container::getFolder(const std::string &_path)
    {
        std::size_t pos = _path.find_last_of("/\\");

        if (pos == std::string::npos)
            return "./";
        return _path.substr(0, pos + 1);
    }
}
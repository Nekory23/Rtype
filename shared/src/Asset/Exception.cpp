/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-chloe.chauvin
** File description:
** AssetException
*/

#include "Asset/Exception.hpp"
#include <iostream>

namespace srd::asset {
    Exception::Exception(const std::string &_type, const std::string &_desc, const std::string &_path, const std::string &_line)
        : ::srd::Exception(_type), m_desc(_desc), m_path(_path), m_line(_line)
    {}

    char const *Exception::what() const noexcept
    {
        std::string error = m_type + " error: " + m_desc;

        if (!m_path.empty())
            error += ",\n\tin file: \"" + m_path + "\"";
        if (!m_line.empty())
            error += ",\n\tat line: \"" + m_line + "\"";
        std::cout << error << std::endl;
        return error.c_str();
    }
}
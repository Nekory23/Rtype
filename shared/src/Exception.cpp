/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-chloe.chauvin
** File description:
** Exception
*/

#include "Exception.hpp"

namespace srd {
    Exception::Exception(const std::string &_type)
        : m_type(_type)
    {}

    const char *Exception::what() const noexcept
    {
        std::string error = m_type + "";

        return error.c_str();
    }
}
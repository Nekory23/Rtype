/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-chloe.chauvin
** File description:
** Exception
*/

#include "Network/Exception.hpp"

namespace srd::net {
    Exception::Exception(const std::string &_type, const std::string &_desc, const std::string &_packet)
        : ::srd::Exception(_type), m_desc(_desc), m_packet(_packet)
    {}

    const char *Exception::what() const noexcept
    {
        std::string error = m_desc + " " + m_desc;

        if (!m_packet.empty())
            error += "\n\tpacket: " + m_packet;
        return error.c_str();
    }
}
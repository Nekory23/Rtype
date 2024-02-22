/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-chloe.chauvin
** File description:
** Exception
*/

#pragma once

#include "../Exception.hpp"

namespace srd::net {
    class Exception : public ::srd::Exception {
        public:
            Exception(const std::string &_type, const std::string &_desc, const std::string &_packet = "");
            virtual ~Exception() = default;

            virtual const char *what() const noexcept override;
        protected:
            std::string m_desc;
            std::string m_packet;
    };
}

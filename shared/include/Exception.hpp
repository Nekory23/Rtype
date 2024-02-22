/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-chloe.chauvin
** File description:
** Exception
*/

#pragma once

#include <exception>
#include <string>

namespace srd {
    class Exception : std::exception {
        public:
            Exception(const std::string &_type);
            virtual ~Exception() =default;

            virtual const char *what() const noexcept override;

        protected:
            std::string m_type;
    };
}
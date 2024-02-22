/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-chloe.chauvin
** File description:
** AssetException
*/

#pragma once

#include "../Exception.hpp"

namespace srd::asset {
    class Exception : public ::srd::Exception {
        public:
            Exception(const std::string &_type, const std::string &_desc, const std::string &_path = "", const std::string &_line = "");
            virtual ~Exception() = default;

            virtual char const *what() const noexcept override;

        protected:
            std::string m_desc;
            std::string m_path;
            std::string m_line;
    };
}
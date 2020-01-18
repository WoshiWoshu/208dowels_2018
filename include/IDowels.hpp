/*
** EPITECH PROJECT, 2019
** dowels
** File description:
** IDowels.hpp
*/

#pragma once

#include <sstream>

static const bool SUCCESS = true;
static const bool FAILURE = false;

template<typename T>
T stringToNumber(const std::string &str)
{
    std::istringstream strStream(str);
    T nb;

    return strStream >> nb ? nb : 0;
};

// template<typename T>
// T numberToString(const std::string &str)
// {
//     std::istringstream strStream(str);
//     T nb;

//     return strStream >> nb ? nb : 0;
// };

// class IDowels {
// public:
//     virtual ~IDowels
// }

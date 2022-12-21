#pragma once

#include <string>

#include "library.hpp"

namespace stx
{
    std::list<std::string> split(std::string line, char separator); // разделяет по сепаратору
    bool isBounded(std::string line, char bound);                   // с кавычками?
    std::string toUppercase(std::string line);                      // в капс переводит

    template <typename T>
    T STOI(const lib::line_type &line); // string to int
}

template <typename T>
T stx::STOI(const lib::line_type &line) // string to int
{
    return lib::line_to_int(line);
}

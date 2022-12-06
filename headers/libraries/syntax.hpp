#pragma once

#include <string_view>
#include <string>
#include <algorithm>
#include <string>

#include "library.hpp"
namespace stx
{
    std::list<std::string> split(std::string_view line, char separator); //разделяет
    bool isBounded(std::string_view line, char bound);                   //с кавычками?
    std::string toUppercase(std::string line);

    template <typename T>
    T STOI(const lib::line_type &line); // string to int
}

std::string stx::toUppercase(std::string line) // caps
{
    std::transform(line.begin(), line.end(), line.begin(), ::toupper);
    return line;
}
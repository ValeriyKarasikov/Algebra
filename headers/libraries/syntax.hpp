#pragma once

#include "/home/KhamzD/Документы/CPP/Algebra-libraries/headers/variables/library.hpp"
namespace stx
{
    std::list<std::string> split(std::string_view line, char separator);
    bool isBounded(std::string_view line, char bound);
    std::string toUppercase(std::string_view line);

    template <typename T>
    T STOI(const lib::line_type &line);
}

std::string stx::toUppercase(std::string_view line)
{

}
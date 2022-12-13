#pragma once

// #include <string_view>
#include <string>
#include <algorithm>
#include <string>

#include "library.hpp"
namespace stx
{
    std::list<std::string> split(std::string line, char separator); // разделяет
    bool isBounded(std::string line, char bound);                   // с кавычками?
    std::string toUppercase(std::string line);

    template <typename T>
    T STOI(const lib::line_type &line); // string to int
}

std::list<std::string> split(std::string line, char sep)
{
    std::list<std::string> list;
    lib::integer_number_type i = 0;
    lib::line_type stroka;
    char sep2 = 34;
    while (i < line.size())
    {
        if (line[i] == sep2)
        {
            while (line[i] != sep2)
            {
                i++;
                stroka.push_back(line[i]);
            }
            stroka.push_back(line[i - 1]);
            list.push_back(stroka);
            stroka.clear();
        }
        else if (line[i] != sep)
        {
            stroka.push_back(line[i]);
        }
        else if (line[i] == sep)
        {
            stroka.push_back(line[i]);
            list.push_back(stroka);
            stroka.clear();
        }
        i++;
    }
    return list;
}

std::string stx::toUppercase(std::string line) // caps
{
    std::transform(line.begin(), line.end(), line.begin(), ::toupper);
    return line;
}

bool stx::isBounded(std::string line, char bound)
{
    if (line[0] == bound)
    {
        return true;
    }
    return false;
}

template <typename T>
T stx::STOI(const lib::line_type &line) // string to int
{
    return lib::line_to_int(line);
}

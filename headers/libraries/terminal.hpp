#pragma once

#include <fstream>
#include <iostream>

namespace term
{
    // prefix -- некоторое сообщение перед вводом, например, текст "enter here >> "
    void input(std::string &line, std::string_view prefix);
    template <char end = '\n', char sep = ' ', typename... T>
    void display(const T &...t);
}

void term::input(std::string &line, std::string_view prefix /*,std::string_view changed_prefix*/)
{
    std::cout << prefix << ": "; // тут допустим введите значение
    std::cin >> line;
    // std::cout << changed_prefix << line << std::endl; а тут допустим это значение =
    // break;
    return;
}

template <char end = '\n', char sep = ' ', typename... T>
void term::display(const T &...t)
{
    while (t != end)
    {
        std::cout << t << sep;
    }
    return;
}
#pragma once

#include <fstream>
#include <iostream>

struct Pass
{
    template <typename... T>
    Pass(const T &...) {}
};

namespace term
{
    // prefix -- некоторое сообщение перед вводом, например, текст "enter here >> "
    void input(std::string &line, std::string prefix);
    
    template <char end = '\n', char sep = ' ', typename... T>
    void display(const T &...t);
}

void term::input(std::string &line, std::string prefix)
{
    std::cout << prefix << ": "; // тут допустим введите значение
    std::cin >> line;
}

template <char end = '\n', char sep = ' ', typename... T>
void term::display(const T &...t)
{
    Pass{(std::cout << t << sep, 1)...};
    std::cout << end;
}

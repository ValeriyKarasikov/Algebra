#pragma once

#include <fstream>

namespace term
{
    // prefix -- некоторое сообщение перед вводом, например, текст "enter here >> "
    void input(std::string &line, std::string_view prefix);
    template <char end = '\n', char sep = ' ', typename... T>
    void display(const T &...t);
}

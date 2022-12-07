#pragma once
#include "library.hpp"


namespace stx 
{
    lib::lines_type split (const lib::line_type &line,  const char separator);
    bool IsTrue (const lib::line_type line); //проверка корректности написания строки
}

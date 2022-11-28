#pragma once

#include <string>
#include <list>

#include "database.hpp"

namespace lib
{
    using floating_point_type = double;
    using integer_number_type = std::intmax_t;
    using line_type = std::string;
    using lines_type = std::list<line_type>;
    using library_type = Database<floating_point_type, integer_number_type, line_type>;
    using size_type = std::size_t;

    // set, path, "/home/..."
    void line_to_line(line_type &line);
    // set, x, 4.2f -> x = 4.2: std::stof
    void line_to_float(line_type &line);
    // set, x, 4i -> x = 4
    void line_to_int(line_type &line);

    void interpret(floating_point_type &value, lines_type string/*, const library_type &library*/);
    void interpret(integer_number_type &value, lines_type string/*, const library_type &library*/);
    void interpret(line_type &path, lines_type string/*, const library_type &library*/);
}

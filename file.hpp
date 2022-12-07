#pragma once

#include "library.hpp"
#include <fstream>

namespace file
{
    std::ifstream input;

    void read(std::string &line, std::string_view path);
    void write(const std::string &line, std::string_view path);
    template <typename Op> // Op -- operation (predicate)
    void stream(std::filesystem::path path, std::ios_base::openmode om, Op op);
}

#pragma once

#include "/home/KhamzD/Документы/CPP/Algebra-libraries/headers/variables/library.hpp"
#include <fstream>

namespace file
{
    void read(std::ifstream input, std::string &line, std::string_view path);
    void write(std::ofstream output, const std::string &line, std::string_view path);
    // template <typename Op> // Op -- operation (predicate)
    // void stream(std::filesystem::path path, std::ios_base::openmode om, Op op);
}

void file::read(std::ifstream input, std::string &line, std::string_view path)
{
    // while (line != '\n')
    // {
    // }
}
void file::write(std::ofstream output, const std::string &line, std::string_view path)
{
}

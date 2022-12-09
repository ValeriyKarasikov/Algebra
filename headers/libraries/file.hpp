#pragma once

#include "library.hpp"

// #include <filesystem> //прикол
#include <fstream>

namespace file
{
    void read(std::fstream &input, std::string &line, std::string_view path);
    void write(std::fstream &output, const std::string &line, std::string_view path);

    // template <typename Op> // Op -- operation (predicate)
    //  void stream(std::filesystem::path path, std::ios_base::openmode om, Op op);
}

void file::read(std::fstream &input, std::string &line) //, std::string_view path)
{
    input >> line;
}

void file::write(std::fstream &output, const std::string &line) //, std::string_view path)
{
    output << line;
}
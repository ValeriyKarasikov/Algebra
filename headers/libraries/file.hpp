#pragma once

#include <fstream>

namespace file
{
    void read(std::fstream &input, std::string &line);
    void write(std::fstream &output, const std::string &line);
    
}

void file::read(std::fstream &input, std::string &line)
{
    input >> line;
}

void file::write(std::fstream &output, const std::string &line)
{
    output << line;
}

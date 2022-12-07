#include "interpreter.hpp"

Interpreter::Interpreter (int argc, char**argv) : library_ {
    // {'f', 'i', '\"'}, {&stx::stof, &stx::stoi, &stx::stos}
    },   preprocessor_{library_},   processor_{library_},   postprocessor_{library_}
{
    if (argc==0)
    {
        this->term_();
    }
    else
    {
        this->file_(argv[1]);
    }
}
Interpreter::~Interpreter(){}

void Interpreter::term_()
{
    std::string line;
    while(line != "EXIT")
    {
        //term::read(line);
    }
}
void Interpreter::file_(const std::string &path_to_log)
{
    std::string line;
    while(line != "EXIT")
    {
        //file::read(line, path_to_log);
    }
}

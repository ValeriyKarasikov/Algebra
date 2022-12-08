#pragma once

#include "terminal.hpp"
#include "database.hpp"
#include "library.hpp"
#include <map>
#include <string>
#include <list>

class Postprocessor 
{
public:
    Postprocessor(const lib::library_type& library);

    using key_type=std::string;
    using function_type = void(Postprocessor::*)(const lib::lines_type &);

    const lib::library_type &library_;
    std::map<key_type, function_type> commands_;

private:
    void size (const lib::lines_type &lines); //размер листа (кол-во переменных)
    void allNameConsol (const lib::lines_type &lines);//вывод в консоль все имена переменных
    void allNameFile (const lib::lines_type &lines); //вывод в файл все имена переменных
    void clearPost(const lib::lines_type &lines); //отчистка файла/консоли

};


void Postprocessor::size (const lib::lines_type &lines)
{term::display(lib::library_type::size);}

void Postprocessor::allNameConsol (const lib::lines_type &lines)
{term::display(lib::library_type::allNames);}

void Postprocessor::allNameFile (const lib::lines_type &lines)
{}    

void Postprocessor::clearPost(const lib::lines_type &lines)
{}   

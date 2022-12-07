#pragma once

#include "file.hpp"
#include "terminal.hpp"
#include <iostream>
#include "terminal.hpp"
#include "database.hpp"
#include "library.hpp"
#include <map>
#include <string>
using namespace std;

class Postprocessor 
{
public:
    Postprocessor(const lib::library_type& library);

protected:
private:

    using key_type=std::string;
    using function_type = void(Postprocessor::*)(const lib::lines_type &);

    const lib::library_type &library_;
    std::map<key_type, function_type> commands_;

    void size (const lib::lines_type &lines); //размер листа (кол-во переменных)
    void allNameConsol (const lib::lines_type &lines);//вывод в консоль все имена переменных
    void allNameFile (const lib::lines_type &lines); //вывод в файл все имена переменных
    void clear(const lib::lines_type &lines); //отчистка файла/консоли



};


void Postprocessor::size (const lib::lines_type &lines)
{
   cout << lib::library_type::size <<endl; //делать класс шаблонным????
}
void Postprocessor::allNameConsol (const lib::lines_type &lines)
{
   // cout << lib::library_type::allNames << endl; //делать класс шаблонным????
}
void Postprocessor::allNameFile (const lib::lines_type &lines)
{
    //cout << Database</*lib::size_type*/>::allNames() << endl; //делать класс шаблонным????
}
void Postprocessor::clear(const lib::lines_type &lines)
{
   // Database</*lib::size_type*/>::~Database(); //делать класс шаблонным????
}
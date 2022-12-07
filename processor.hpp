#pragma once


#include "algebra.hpp"
#include "terminal.hpp"
#include "file.hpp"
#include "library.hpp"
#include <map>
#include <fstream>
#include <iostream>
using namespace std;

class Processor 
{
public:
    Processor (const lib::library_type& library);
    using key_type=std::string;
    using function_type = void(Processor::*)(const lib::lines_type &);
    
    const lib::library_type &library_;
    std::map<key_type, function_type> commands_;
protected:

private:
    

    void pow (const lib::lines_type &lines); //возведение в степень
    void inc (const lib::lines_type &lines); //прибавление числа
   // void sqrt (const lib::lines_type &lines); //корень от числа
    void sum (const lib::lines_type &lines); //сумма переменных
   // void dec (const lib::lines_type &lines); //вычитание числа
    void del (const lib::lines_type &lines); //разность перменных
   // void RemVar (const lib::lines_type &lines); // функция удаляет переменные 



};


void Processor::pow (const lib::lines_type &lines)
{
    
    term::display(lines);
}

void Processor::inc (const lib::lines_type &lines)
{
    term::display(lines);
}

void Processor::sum (const lib::lines_type &lines)
{
    term::display(lines);
} 

void Processor::del (const lib::lines_type &lines)
{
    term::display(lines);
} 


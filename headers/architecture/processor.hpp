#pragma once

#include "database.hpp"
#include "syntax.hpp"
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
    //template <typename T1, typename T2>
    using function_type = void (Processor::*)(lib::lines_type &);

    
    lib::line_type TypeValue,value,ValueName,ValueName1,ValueName2,value1,value2;
    const lib::library_type &library_;
    std::map<key_type, function_type> commands_;
    
    
    template <typename T1, typename T2>
    void pow ( lib::lines_type &lines); //возведение в степень

    template <typename T1, typename T2>
    void inc ( lib::lines_type &lines); //прибавление числа  
   // void sqrt (const lib::lines_type &lines); //корень от числа

    template <typename T1 , typename T2>
    void sum ( lib::lines_type &lines); //сумма переменных
   // void dec (const lib::lines_type &lines); //вычитание числа

    template <typename T1 , typename T2>
    void del ( lib::lines_type &lines); //разность перменных
   // void RemVar (const lib::lines_type &lines); // функция удаляет переменные 
  
};

template <typename T1, typename T2>
void Processor::pow ( lib::lines_type &lines)
{   
    lib::integer_number_type pow;
    pow = stx::STOI(lines.back());

    lines.pop_front();
    ValueName =lines.front();
    value = library_.get(ValueName);

    value = alg::pow(value,pow);

    library_.assign(value,ValueName);

    term::display(value);
    
    /*
    lib::line_type TypeValue = lines.back();
    lines.pop_back();
    lib::line_type value = lines.back();
    term::display(alg::pow(stx::STOI(value))); 
    */
}

template <typename T1, typename T2>
void Processor::inc ( lib::lines_type &lines)
{   
    /*
    lib::size_type inc;
    inc = stx::STOI(lines.back());*/

    lines.pop_front();
    ValueName = lines.front();
    value = library_.get(ValueName);
    value = alg::inc(value);

    library_.assign(value,ValueName);

    term::display(value);

    /*
    lib::line_type TypeValue = lines.back();
    lines.pop_back();
    lib::line_type value = lines.back();
    term::display(alg::inc(stx::STOI(value)));
    */
}


template <typename T1 , typename T2>
void Processor::sum ( lib::lines_type &lines)
{
    lines.pop_front();
    list<lib::line_type>::iterator it = lines.begin(); 
    
    ValueName1 = *it;
    ValueName2 = *++it;

    value1 = library_.get(ValueName1);
    value2 = library_.get(ValueName2);

    lib::size_type ValueSum = alg::sum(value1,value2);

    term::display(ValueSum);

} 

template <typename T1 , typename T2>
void Processor::del ( lib::lines_type &lines)
{
    lines.pop_front();
    list<lib::line_type>::iterator it = lines.begin(); 
    
    ValueName1 = *it;
    ValueName2 = *++it;

    value1 = library_.get(ValueName1);
    value2 = library_.get(ValueName2);

    lib::size_type ValueDel =  alg::del(value1, value2);

    term::display(ValueDel);
    /*
    int x = library_.get(lines.front());
    int y = library_.get(lines.back());
    term::display(alg::del(x,y));
    */
} 


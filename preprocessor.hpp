#pragma once

#include "database.hpp"
#include "library.hpp"
#include <map>
#include <string>
#include <iostream>
#include <fstream>


class Preprocessor 
{
public:
    

    Preprocessor(const lib::library_type& library);
    void invoke(const lib::lines_type::value_type &head, const lib::lines_type &other);

protected:
private:
    using key_type=std::string;
    using function_type = void(Preprocessor::*)(const lib::line_type &);

    const lib::library_type &library_;
    std::map < key_type , function_type > commands_;
    
    
    void set(const lib::line_type &lines); //создание переменной
    void dir(const lib::line_type &lines); //хранение пути к папке с результатом  
    void clear(const lib::line_type &lines);

};


void Preprocessor::set(const lib::line_type &lines)
{
  // Database<lib::size_type>::set(); // нестатическая ссылка не член должна указываться относительно заданного объекта/ что означает 
}
void Preprocessor::dir(const lib::line_type &lines) //???????
{}
void Preprocessor::clear(const lib::line_type &lines) //?????
{}
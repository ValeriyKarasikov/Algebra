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

    using key_type=std::string;
    using function_type = void(Preprocessor::*)( lib::lines_type &);

    lib::line_type KeyWord,TypeValue,Value,Name;
    const lib::library_type &library_;
    std::map < key_type , function_type > commands_;

private:

    template <typename T>
    void set(lib::lines_type &lines); //создание переменной
    template <typename T>
    void del( lib::lines_type &lines); //удаление переменной 
    template <typename T>
    void clearPre( lib::lines_type &lines);

};

 template <typename T>
void Preprocessor::set(lib::lines_type &lines)
{  
  KeyWord = lines.front();
  lines.pop_front();
  lines.pop_back();
  
  Value = lines.back();
  Name = lines.front();
  
  library_.set(Name,Value);
  
}

template <typename T>
void Preprocessor::del(lib::lines_type &lines) 
{
  KeyWord = lines.front();
  lines.pop_front();

  Name = lines.front();

  library_.erase(Name);
}

template <typename T>
void Preprocessor::clearPre(lib::lines_type &lines) //?????
{}

#pragma once
#include <iostream>
#include<iostream>
#include<fstream>
#include "library.hpp"
#include "preprocessor.hpp"
#include "processor.hpp"
#include "postprocessor.hpp"
#include "syntax.hpp"
using namespace std;

class Interpreter
{
public:
    Interpreter (int argc, char**argv);
    ~Interpreter();
    //iostream& operator>> (istream& is); 


private:
    lib::library_type library_;
    void term_( lib::line_type &path_to_log); //работа с терминалом 
    void file_( lib::line_type &path_to_log);//работа с файлом

    Preprocessor preprocessor_;
    Processor processor_;
    Postprocessor postprocessor_;
    fstream input_file_;
    iostream input_term_;
    //lib::line_type path;

   // void ReadFromFile(const lib::lines_type &lines); //считывание из файла
   // void ReadFromConsol(const lib::lines_type &lines); //считывание с консоли

};


void Interpreter::term_( lib::line_type &path_to_log)
{
    /*
    lib::integer_number_type size = input_term.gcount();
    char *path = new char [size];
    cin.get(path,size);

    char *LineTerminal = new char [size];
    cin.get(LineTerminal,size);
    */
    
// set,x=42i;    
 lib::lines_type LineTerminalList;
 lib::line_type LineTerminal ;
 getline(input_term_,path_to_log);

 if (stx::IsTrue(path_to_log))
 {
    while (LineTerminal != "EXIT", )
    {
        getline(input_term_,LineTerminal);
        term::input(LineTerminal,/* откуда мы возьмем префикс если построчно делит Данил?????ааааааааа?? */);
        term::display();// Что она принимает?
    }
 }
 else
 {
    cout << "error path  file" << endl;
    exit;
 }
}

void Interpreter::file_(lib::line_type &path_to_log)
{
    lib::line_type LineFile;
    input_file_.open(path_to_log);


    if (input_file_.is_open())
    {
        while (LineFile != "EXIT")
        {
            getline(input_file_,LineFile);
            file::read(LineFile,path_to_log);
            file::write(LineFile,path_to_log);
        }
    }
    else
    {
        cout << "error open file" << endl;
        exit;
        Interpreter::term_(path_to_log);
    }
}

/*
template <typename T, typename Q>
iostream& operator>> (T is, Q x)
{}
 */
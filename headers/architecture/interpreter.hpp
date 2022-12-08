#pragma once
#include <cstdlib>
#include <iostream>
#include<fstream>
#include "library.hpp"
#include "Preprocessor.hpp"
#include "Processor.hpp"
#include "Postprocessor.hpp"
#include "syntax.hpp"
#include "exception.hpp"
#include "terminal.hpp"
using namespace std;

class Interpreter
{
public:
    Interpreter (int argc, char**argv);
    ~Interpreter();
    //iostream& operator>> (istream& is);
private:
    lib::library_type library_;

    template <typename T1, typename T2>
    void term_( lib::line_type path_to_log); //работа с терминалом 

    void file_(const lib::line_type &path_to_log);//работа с файлом

    Preprocessor preprocessor_;
    Processor processor_;
    Postprocessor postprocessor_;
    fstream input_file_;
    iostream input_term_;
    //lib::line_type path;
   // void ReadFromFile(const lib::lines_type &lines); //считывание из файла
   // void ReadFromConsol(const lib::lines_type &lines); //считывание с консоли

};

template <typename T1, typename T2>
void Interpreter::term_( lib::line_type path_to_log )
{
    /*
    lib::integer_number_type size = input_term.gcount();
    char *path = new char [size];
    cin.get(path,size);

    char *LineTerminal = new char [size];
    cin.get(LineTerminal,size);
    */
    
 lib::lines_type ListLineTerm;
 lib::line_type LineTerminal ;
 lib::line_type KeywordsTerminal;
 //getline(input_term_,path_to_log);


term::input(path_to_log,"specify the location of the file you want to read");

input_file_.open(path_to_log);

if ( false /*input_file_.is_open()*/)
{/*Interpreter::file_(path_to_log);*/}
else
{
    cout << "File not found" << endl;
    input_file_.close();

 while (LineTerminal != "EXIT")
    {
               
        getline(input_term_,LineTerminal);

        if (ListLineTerm.empty())
        {exit;}

        ListLineTerm = stx::split(LineTerminal, ',');
        KeywordsTerminal = ListLineTerm.front();
        stx::toUppercase(KeywordsTerminal);

        if (processor_.commands_.count(KeywordsTerminal))
        {//term::display(processor_.commands_.at(KeywordsTerminal));
            if (KeywordsTerminal == "POW")
            {processor_.pow(ListLineTerm);}

            if (KeywordsTerminal == "INC")
            {processor_.inc(ListLineTerm);} 

            if (KeywordsTerminal == "SUM")
            {
                term::input(LineTerminal,"enter the two variables you want to add separated by commas");
                ListLineTerm = stx::split(LineTerminal,',');
                Processor::sum(ListLineTerm);
            }

            if (KeywordsTerminal == "DEL")
            {
                term::input(LineTerminal,"enter variables in order of subtraction (Example: a, b => a-b)");
                ListLineTerm = stx::split(LineTerminal,',');
                processor_.del(ListLineTerm);
            }              
        
        }

        if (preprocessor_.commands_.count(KeywordsTerminal))
        {//term::display(preprocessor_.commands_.at(KeyWordFile));
            if (KeywordsTerminal == "SET")
            {preprocessor_.set(ListLineTerm);}

            if (KeywordsTerminal == "DEL")
            {preprocessor_.del(ListLineTerm);}                      

            if (KeywordsTerminal == "CLEARPRE")
            {system("clc");}             
        }
        
        if (postprocessor_.commands_.count(KeyWordFile))
        {
            if (KeywordsTerminal == "SIZE")
            {postprocessor_.size();}
              
            if (KeywordsTerminal == "ALLNAMECONSOLE" )
            {postprocessor_.allNameConsol();}
              
            if (KeywordsTerminal == "ALLNAMEFILE" )
            {cout<<"File not found"<<endl;}

            if (KeywordsTerminal == "CLEARPOST")
            {system("clc");}
        }

        ListLineTerm.clear();
        

        /*
        getline(input_term_,LineTerminal);
        term::input(LineTerminal,/* откуда мы возьмем префикс если построчно делит Данил?????ааааааааа?? */
       // term::display();// Что она принимает?*/
    }

}
}



void Interpreter::file_( const lib::line_type &path_to_log)
{
    
    lib::lines_type ListLineFile;
    lib::line_type LineFile ;
    lib::line_type KeywordsFile;

   // input_file_.open(path_to_log);

        while (LineFile != "EXIT")
        {
            /*
            getline(input_file_,LineFile);
            ListLineFile = stx::split(LineFile, ',');
            KeywordsFile = ListLineFile.front();*/
            
            
            
            file::read(input_file_,LineFile);

            if (ListLineFile.empty())
            {
                input_file_.close();
                exit;
            }

            ListLineFile = stx::split (LineFile, ',');
            KeywordsFile = ListLineFile.front();
            stx::toUppercase (KeywordsFile);

              if (processor_.commands_.count(KeywordsFile))
        {//term::display(processor_.commands_.at(KeywordsTerminal));
            if (KeywordsFile == "POW")
            {

            }

            if (KeywordsFile == "INC")
            {} 

            if (KeywordsFile == "SUM")
            {
              
            }

            if (KeywordsFile == "DEL")
            {
               
            }              
        
        }

        if (preprocessor_.commands_.count(KeywordsFile))
        {//term::display(preprocessor_.commands_.at(KeywordsFile));
            if (KeywordsFile == "SET")
            {}

            if (KeywordsFile == "DEL")
            {}                      

            if (KeywordsFile == "CLEARPRE")
            {}             
        }
        
        if (postprocessor_.commands_.count(KeywordsFile))
        {
            if (KeywordsFile == "SIZE")
            {}
              
            if (KeywordsFile == "ALLNAMECONSOLE" )
            {}
              
            if (KeywordsFile == "ALLNAMEFILE" )
            {

            }

            if (KeywordsFile == "CLEARPOST")
            {}
        }
            
            ListLineFile.clear();
            
            //file::read(LineFile,path_to_log);
            //file::write(LineFile,path_to_log);
        }
    
    input_file_.close();
}

/*
template <typename T, typename Q>
iostream& operator>> (T is, Q x)
{}
 */

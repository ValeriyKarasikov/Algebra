#include "library.hpp"
#include <map>
#include "Preprocessor.hpp"
#include <fstream>

Preprocessor::Preprocessor(const lib::library_type &library) : library_{library}, commands_ 
                { {"SET",&Preprocessor::set},
                {"DEL",&Preprocessor::del},
                {"CLEARPRE",&Preprocessor::clearPre}}
{}


/*
void Preprocessor::invoke(const lib::lines_type::value_type &head, 
                                    const lib::lines_type &others)
{
    if (this->commands_.find(head) !=this->commands_.end())
    {
        (this->*this->commands_[head])(others);
    }
    else
    {
        //throw something
    }
}
 
*/

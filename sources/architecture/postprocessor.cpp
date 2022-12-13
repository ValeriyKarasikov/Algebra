#include "library.hpp"
#include <map>
#include "Postprocessor.hpp"

//template <typename T>
Postprocessor::Postprocessor (const lib::library_type &library) : library_{library}, commands_
    { {"SIZE", &Postprocessor::size},
    {"ALLNAMECONSOLE",&Postprocessor::allNameConsol},
    {"ALLNAMEFILE",&Postprocessor::allNameFile},    
    {"CLEARPOST",&Postprocessor::clearPost}}
{}

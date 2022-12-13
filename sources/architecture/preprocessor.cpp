#include "library.hpp"
#include <map>
#include "Processor.hpp"

//template <typename T>
Processor::Processor(const lib::library_type &library) : library_{library} ,commands_ 
{{"POW", &Processor::pow},
{"INC",&Processor::inc},
{"SUM",&Processor::sum},
{"DEL",&Processor::del}}
{}

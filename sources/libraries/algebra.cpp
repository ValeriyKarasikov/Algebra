#include "library.hpp"

lib::floating_point_type lib::line_to_float(line_type &line)
{
  line.pop_back();
  return std::stof(line);
}

lib::integer_number_type lib::line_to_int(line_type &line)
{
  line.pop_back();
  return std::stoi(line);
}

void lib::interpret(floating_point_type &value, line_type &string, library_type &library)
{
  try {
    value = std::stof(string);
  }
  catch(...){
    value = library.get<floating_point_type>(string);
  }
}

void lib::interpret(integer_number_type &value, line_type &string, library_type &library)
{
  try {
    value = std::stoi(string);
  }
  catch(...){
    value = library.get<integer_number_type>(string);
  }
}

void lib::interpret(line_type &value, line_type &string, library_type &library)
{
  if ((string.back()) == '"')
  {
    value = string;
  }
  else
  {
    value = library.get<line_type>(string);
  }
}

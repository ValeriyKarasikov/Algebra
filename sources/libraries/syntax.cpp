#include "syntax.hpp"

std::list<std::string> split(std::string line, char sep)
{
    std::list<std::string> list;    // создаём лист
    lib::integer_number_type i = 0; // итератор для проходки по стрингу
    lib::line_type stroka;          // хранит временную строку для записи в лист
    char sep2 = '\"';
    while (i < line.size())
    {
        if (line[i] == sep2)
        {
            i++;
            stroka.push_back('\"');
            while (line[i] != sep2)
            {
                stroka.push_back(line[i]);
                i++;
            }
            stroka.push_back('\"');
            list.push_back(stroka);
            stroka.clear();
        }
        else if (line[i] != sep)
        {

            if (line[i] != ' ')
            {
                stroka.push_back(line[i]);
            }
        }
        else if (line[i] == sep or i == '\0')
        {
            if (stroka.size() != 0)
            {
                list.push_back(stroka);
                stroka.clear();
            }
        }
        i++;
    }
    if (i == line.size())
    {
        list.push_back(stroka);
    }
    stroka.clear();
    return list;
}

std::string stx::toUppercase(std::string line) // caps
{
    std::transform(line.begin(), line.end(), line.begin(), ::toupper);
    return line;
}

bool stx::isBounded(std::string line, char bound)
{
    if (line[0] == bound)
    {
        return true;
    }
    return false;
}

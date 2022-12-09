#pragma once

#include <exception>
#include <string>

namespace exc
{
    class Exception : public std::exception
    {
    public:
        const char *what() const noexcept;

    protected:
        explicit Exception(const std::string &message) noexcept;

    private:
        const std::string message_;
    };

    struct invalid_data : public Exception // указаны неверные входные данные команды
    {
        invalid_data(const std::string &message) : Exception{
                                                       "Invalid data. Code: " + message + "."} {}
    };

    struct unknown_data : public Exception // указано неизвестное значение параметра команды
    {
        unknown_data(const std::string &message) : Exception{
                                                       "Unknown data. Code: " + message + "."} {}
    };

    struct unspecified_data : public Exception // не указано значение параметра команды
    {
        unspecified_data(const std::string &message) : Exception{
                                                           "Unspecified data. Code: " + message + "."} {}
    };

    struct undefined_data : public Exception // не задано значение параметра команды
    {
        undefined_data(const std::string &message) : Exception{
                                                         "Undefined data. Code: " + message + "."} {}
    };
}
const char *exc::Exception::what() const noexcept
{
    this->message_.c_str();
}

exc::Exception::Exception(const std::string &msg) noexcept : message_{msg}
{
}
#pragma once

#include <cstdint>       // std::size_t
#include "library.hpp"   // подключаем библеотеку Дамира
#include "exception.hpp" // подключаем наш файл

namespace alg
{

    template <typename T>
    T inc(T &t) noexcept; // инкрементация

    template <typename T>
    T pow(T &t, const std::size_t &n); // степень

    template <typename T1, typename T2>
    auto sum(const T1 &t1, const T2 &t2) noexcept(true);

    template <typename T1, typename T2>
    auto del(const T1 &t1, const T2 &t2) noexcept(false); // деление

}

template <typename T>
T alg::inc(T &t) noexcept
{
    return ++t;
}

template <typename T>
T alg::pow(T &t, const lib::integer_number_type &n) // только степень int
{
    if (n < 0)
    {
        return 1 / alg::pow(t, -n);
    }
    else if (n > 0)
    {
        return t * alg::pow(t, n - 1);
    }
    else if (n == 0)
    {
        return 1;
    }
}

template <typename T1, typename T2>
auto alg::sum(const T1 &t1, const T2 &t2) noexcept(true)
{
    return t1 + t2;
}

template <typename T1, typename T2>
auto alg::del(const T1 &t1, const T2 &t2) noexcept(false)
{
    if (t2 == 0)
    {
        throw exc::invalid_data("Divisor is zero.");
    }
    else
    {
        return t1 / t2;
    }
}
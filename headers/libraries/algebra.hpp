#pragma once

// #include <concepts>

#include <cstdint> // std::size_t
#include "/home/KhamzD/Документы/CPP/Algebra-libraries/headers/variables/library.hpp"
#include "exception.hpp"

namespace alg
{
    using value_type = lib::floating_point_type;

    // value_type sum(const value_type &first, const value_type &second);

    template <typename T>
    void inc(T &t) noexcept;

    template <typename T>
    void pow(T &t, const std::size_t &n);

    template <typename T1, typename T2>
    void sum(const T1 &t1, const T2 &t2) noexcept(true);

    template <typename T1, typename T2>
    void del(const T1 &t1, const T2 &t2) noexcept(false);

}

template <typename T>
T alg::inc(T &t) noexcept
{
    return t++;
}

template <typename T>
void alg::pow(T &t, const std::size_t &n)
{
    {
        std::size_t i = 0;
        if (n = 0)
        {
            t = 1;
            return;
        }
        else if (n > 0)
        {
            while (n > i)
            {
                t *= t;
                i += 1;
            }
            return;
        }
        else if (n < 0)
        {
            while (n < i)
            {
                t *= t;
                i -= 1;
            }
            t = 1 / t;
            return;
        }
    }
}

template <typename T1, typename T2>
void alg::sum(const T1 &t1, const T2 &t2) noexcept(true)
{
    t1+=t2;
    break;
}

template <typename T1, typename T2>
void alg::del(const T1 &t1, const T2 &t2) noexcept(false)
{
    if (t2==0)
    {
        exc::invalid_data("Divisor is zero.");
        break;
    }
    t1=t1/t2;
    break;
}
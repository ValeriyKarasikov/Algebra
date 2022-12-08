#pragma once

// #include <concepts>

#include <cstdint> // std::size_t
#include "library.hpp"
#include "exception.hpp"

namespace alg
{
    using value_type = lib::floating_point_type;

    // value_type sum(const value_type &first, const value_type &second);

    template <typename T>
    void inc(T &t) noexcept;

    template <typename T>
    void pow(T &t, const std::size_t &n);

    template <typename T>
    void sum(const T &t1, const T &t2) noexcept(true);

    template <typename T, typename T1, typename T2>
    void del(const T1 &t1, const T2 &t2) noexcept(false);

}

template <typename T>
T alg::inc(T &t) noexcept
{
    return ++t;
}

template <typename T>
T alg::pow(T &t, const lib::integer_number_type &n)
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

template <typename T>
T alg::sum(const T &t1, const T &t2) noexcept(true)
{
    return t1 + t2;
}

template <typename T, typename T1, typename T2>
T alg::del(const T1 &t1, const T2 &t2) noexcept(false)
{
    if (t2 == 0)
    {
        throw exc::invalid_data("Divisor is zero.");
    }
    return t1 / t2;
}
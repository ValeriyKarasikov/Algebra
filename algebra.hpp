#pragma once

// #include <concepts>

#include <cstdint> // std::size_t
#include "library.hpp"

namespace alg
{
    using value_type = lib::floating_point_type;

    // value_type sum(const value_type &first, const value_type &second);

    template <typename T>
    void inc(T &t) noexcept;

    template <typename T>
    T sum(const T &first, const T &second);

    template <typename T, std::size_t N>
    void pow(T &t, const N &n);

    template <typename T1, typename T2>
    void sum(const T1 &t1, const T2 &t2) noexcept(true);

    template <typename T1, typename T2>
    void del(const T1 &t1, const T2 &t2) noexcept(false);
    // template <class T>
    // concept Value = std::floating_point<T>;
    // template <Value V>
    // V sum(const V &first, const V &second);

    /*
 template <typename T>
 class function
 {
 public:
     using size_type = std::size_t;
     template <typename T>
     void inc(T &t) noexcept;
     template <typename T, std::size_t N>
     void pow(T &t, const N &n);
     template <typename T1, typename T2>
     void sum(const T1 &t1, const T2 &t2) noexcept(true);
     template <typename T1, typename T2>
     void del(const T1 &t1, const T2 &t2) noexcept(false);
 protected:
 private:
 };
}
template <typename T>
void inc(T &t) noexcept;
template <typename T, std::size_t N>
void pow(T &t, const N &n)
{
 i=0;
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
template <typename T1, typename T2>
void sum(const T1 &t1, const T2 &t2) noexcept(true);
template <typename T1, typename T2>
void del(const T1 &t1, const T2 &t2) noexcept(false);
*/
}

template <typename T>
T alg::sum(const T &first, const T &second)
{
    return first + second;
}

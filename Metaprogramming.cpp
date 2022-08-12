//
// Created by philippe on 25/07/2022.
//

#include "Metaprogramming.h"

// In C++ Metaprogramming refers to the use of macros or templates to generate code at compile-time.

#include <iostream>
#include <type_traits>
#include <utility>
#include <tuple>

// factorial is a struct, but in template metaprogramming it is treated as a template metafunction.
// By convention, template metafunctions are evaluated by checking a particular member,
// either ::type for metafunctions that result in types, or ::value for metafunctions that generate values.

// Template metaprogramming has most of the restrictions of a functional programming language,
// so recursion is the primary "looping" construct.

// Calculating Factorials

template<unsigned int n>
struct factorial
{
    enum
    {
        value = n * factorial<n - 1>::value
    };
};

template<>
struct factorial<0>
{
    enum { value = 1 };
};

// C++11

template<long long n>
struct factorial2 :
        std::integral_constant<long long, n * factorial2<n - 1>::value> {};

template<>
struct factorial2<0> :
        std::integral_constant<long long, 1> {};

// C++11

constexpr long long factorial3(long long n)
{
    return (n == 0) ? 1 : n * factorial3(n - 1);
}

// C++14

constexpr long long factorial4(long long n)
{
    if (n == 0)
        return 1;
    else
        return n * factorial4(n - 1);
}

constexpr long long factorial5(int n)
{
    long long result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

// C++17
/*
template <class T, T N, class I = std::make_integer_sequence<T, N>>
struct factorial6;

template <class T, T N, T... Is>
struct factorial6<T,N,std::index_sequence<T, Is...>> {
    static constexpr T value = (static_cast<T>(1) * ... * (Is + 1));
};
*/

void Test160()
{
    std::cout << factorial<7>::value << std::endl; // prints "5040"

    std::cout << factorial2<7>::value << std::endl; // prints "5040"

    std::cout << factorial3(7) << std::endl;

    // Since template metafunctions execute at compile time, their results can be used
    // in contexts that require compile time values. For example:
    int my_array[factorial<5>::value];

    char test[factorial3(3)];
}

// Iterating over a parameter pack

// C++11

void print_all(std::ostream& os) {
// base case
}

template <class T, class... Ts>
void print_all(std::ostream& os, T const& first, Ts const&... rest) {
    os << first;
    print_all(os, rest...);
}

template <class... Ts>
void print_all2(std::ostream& os, Ts const&... args) {
    using expander = int[];
    (void)expander{0,
                   (void(os << args), 0)...
    };
}

// C++17

template <class... Ts>
void print_all3(std::ostream& os, Ts const&... args) {
    ((os << args), ...);
}

template <class T, class... Ts>
void print_all4(std::ostream& os, T const& first, Ts const&... rest) {
    os << first;
    if constexpr (sizeof...(rest) > 0) {
        // this line will only be instantiated if there are further
        // arguments. if rest... is empty, there will be no call to
        // print_all4(os).
        print_all4(os, rest...);
    }
}

// Iterating with std::integer_sequence

int f(int a, char b, double c)
{
    std::cout << a << " " << b << " "  << c << std::endl;
}

void Test161()
{
    auto some_args = std::make_tuple(42, 'x', 3.14);
    int r = apply(f, some_args); // calls f(42, 'x', 3.14)
}


// Tag Dispatching


// Detect Whether Expression is Valid

// If-then-else


// This struct contains a pointer to T if T is larger than the size of a pointer, or T itself if it is smaller or equal to a
//pointer's size. Therefore sizeof(ValueOrPointer) will always be <= sizeof(void*).

template<typename T>
struct ValueOrPointer
{
    typename std::conditional<(sizeof(T) > sizeof(void*)), T*, T>::type vop;
};

void Test162()
{
    ValueOrPointer<double> some_args;
    some_args.vop = 3.14;
}

// Manual distinction of types when given any type T


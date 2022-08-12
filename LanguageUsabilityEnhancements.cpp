//
// Created by philippe on 12/08/2022.
//

#include "LanguageUsabilityEnhancements.h"

#include <iostream>
#include <type_traits>
#include <vector>
#include <algorithm>
#include <initializer_list>
#include <tuple>

void foo(char *);
void foo(int);

// Chapter 02: Language Usability Enhancements

// 2.1 Constants

// std::nullptr_t and nullptr

int TestNullptr() {

    if (std::is_same<decltype(NULL), decltype(0)>::value)
        std::cout << "NULL == 0" << std::endl;

    if (std::is_same<decltype(NULL), decltype((void*)0)>::value)
        std::cout << "NULL == (void *)0" << std::endl;

    if (std::is_same<decltype(NULL), std::nullptr_t>::value)
        std::cout << "NULL == nullptr" << std::endl;

    foo(0); // will call foo(int)

    // foo(NULL); // doesn't compile

    foo(nullptr); // will call foo(char*)

    return 0;
}

void foo(char *) {
    std::cout << "foo(char*) is called" << std::endl;
}

void foo(int i) {
    std::cout << "foo(int) is called" << std::endl;
}

// constexpr

#define LEN 10

int len_foo() {
    int i = 2;
    return i;
}

constexpr int len_foo_constexpr() {
    return 5;
}

constexpr int fibonacci(const int n) {
    return n == 1 || n == 2 ? 1 : fibonacci(n-1) + fibonacci(n-2);
}

// Only C++14
constexpr int fibonacci2(const int n) {
    if(n == 1) return 1;
    if(n == 2) return 1;
    return fibonacci(n-1) + fibonacci(n-2);
}

int TestConstexpr() {
    char arr_1[10]; // legal
    char arr_2[LEN]; // legal

    int len = 10;
// char arr_3[len]; // illegal
    const int len_2 = len + 1;
    constexpr int len_2_constexpr = 1 + 2 + 3;
// char arr_4[len_2]; // illegal, but ok for most of the compilers
    char arr_4[len_2_constexpr]; // legal
// char arr_5[len_foo()+5]; // illegal
    char arr_6[len_foo_constexpr() + 1]; // legal
// 1, 1, 2, 3, 5, 8, 13, 21, 34, 55
    std::cout << fibonacci(10) << std::endl;
    return 0;
}

// 2.2 Variables and initialization

// if-switch

int TestIfSwitch() {

    std::vector<int> vec = {1, 2, 3, 4};

    // since c++17, can be simplified by using `auto`
    const std::vector<int>::iterator itr = std::find(vec.begin(), vec.end(), 2);
    if (itr != vec.end()) {
        *itr = 3;
    }

    if (const std::vector<int>::iterator itr = std::find(vec.begin(), vec.end(), 3);
            itr != vec.end()) {
        *itr = 4;
    }

    // should output: 1, 4, 3, 4. can be simplified using `auto`
    for (std::vector<int>::iterator element = vec.begin(); element != vec.end();
         ++element) {
        std::cout << *element << std::endl;
    }

    return 0;
}

// Initializer list

class Foo {
public:
    int value_a;
    int value_b;
    Foo(int a, int b) : value_a(a), value_b(b) {}
};

int TestInitializerList() {
    // before C++11
    int arr[3] = {1, 2, 3};
    Foo foo(1, 2);
    std::vector<int> vec = {1, 2, 3, 4, 5};
    std::cout << "arr[0]: " << arr[0] << std::endl;
    std::cout << "foo:" << foo.value_a << ", " << foo.value_b << std::endl;
    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << std::endl;
    }
    return 0;
}

class MagicFoo {
public:
    std::vector<int> vec;
    MagicFoo(std::initializer_list<int> list) {
        for (std::initializer_list<int>::iterator it = list.begin();
             it != list.end(); ++it)
            vec.push_back(*it);
    }

public:
    void foo(std::initializer_list<int> list) {
        for (std::initializer_list<int>::iterator it = list.begin();
             it != list.end(); ++it)
            vec.push_back(*it);
    }
};

int TestInitializerList2() {
    // after C++11
    MagicFoo magicFoo = {1, 2, 3, 4, 5};

    magicFoo.foo({6,7,8,9});

    std::cout << "magicFoo: ";
    for (std::vector<int>::iterator it = magicFoo.vec.begin();
         it != magicFoo.vec.end(); ++it)
        std::cout << *it << std::endl;

    MagicFoo foo2 {3, 4};
    for (std::vector<int>::iterator it = foo2.vec.begin();
         it != foo2.vec.end(); ++it)
        std::cout << *it << std::endl;

    return 0;
}

// Structured binding

std::tuple<int, double, std::string> f() {
    return std::make_tuple(1, 2.3, "456");
}

int TestStructuredBinding() {
    auto [x, y, z] = f();
    std::cout << x << ", " << y << ", " << z << std::endl;
    return 0;
}
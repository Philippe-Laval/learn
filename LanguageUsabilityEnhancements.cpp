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

// 2.3 Type inference

// auto

int add(auto x, auto y) {
    return x+y;
}

int TestInitializerList3() {
    MagicFoo magicFoo = {1, 2, 3, 4, 5};
    std::cout << "magicFoo: ";
    for (auto it = magicFoo.vec.begin(); it != magicFoo.vec.end(); ++it) {
        std::cout << *it << ", ";
    }
    std::cout << std::endl;

    auto i = 5; // type int
    auto j = 6; // type int

    auto arr = new auto(10); // arr as int *

    std::cout << add(i, j) << std::endl;

    return 0;
}

// decltype

int TestDecltype()
{
    auto x = 1;
    auto y = 2;
    decltype(x+y) z;

    if (std::is_same<decltype(x), int>::value)
        std::cout << "type x == int" << std::endl;
    if (std::is_same<decltype(x), float>::value)
        std::cout << "type x == float" << std::endl;
    if (std::is_same<decltype(x), decltype(z)>::value)
        std::cout << "type z == type x" << std::endl;


    return 0;
}

// tail type inference

template<typename R, typename T, typename U>
R add(T x, U y) {
    return x+y;
}

template<typename T, typename U>
auto add2(T x, U y) -> decltype(x+y){
    return x + y;
}

template<typename T, typename U>
auto add3(T x, U y){
    return x + y;
}

int TestTailTypeInference() {

    auto w = add2<int, double>(1, 2.0);
    if (std::is_same<decltype(w), double>::value) {
        std::cout << "w is double: ";
    }
    std::cout << w << std::endl;

    // after c++14
    auto q = add3<double, int>(1.0, 2);
    std::cout << "q: " << q << std::endl;

    return 0;
}

// decltype(auto)

std::string lookup1()
{
    return "test1";
}

std::string test2 = "test2";

std::string& lookup2()
{
    return test2;
}

std::string look_up_a_string_1() {
    return lookup1();
}

std::string& look_up_a_string_2() {
    return lookup2();
}

decltype(auto) look_up_a_string_3() {
    return lookup1();
}

decltype(auto) look_up_a_string_4() {
    return lookup2();
}

int TestDecltypeAuto()
{
    auto result1 = look_up_a_string_1();
    auto result2 = look_up_a_string_2();
    auto result3 = look_up_a_string_3();
    auto result4 = look_up_a_string_4();

    return 0;
}

// 2.4 Control flow

// if constexpr

template<typename T>
auto print_type_info(const T& t) {
    if constexpr (std::is_integral<T>::value) {
        return t + 1;
    } else {
        return t + 0.001;
    }
}

int TestIfConstexpr() {
    std::cout << print_type_info(5) << std::endl;
    std::cout << print_type_info(3.14) << std::endl;

    return 0;
}

// Range-based for loop

int TestLoop() {

    std::vector<int> vec = {1, 2, 3, 4};

    if (auto itr = std::find(vec.begin(), vec.end(), 3); itr != vec.end())
    {
        *itr = 4;
    }

    for (auto element: vec) {
        std::cout << element << std::endl; // read only
    }

    for (auto &element : vec) {
        element += 1; // writeable
    }

    for (auto element : vec)
        std::cout << element << std::endl; // read only

    return 0;
}

// 2.5 Templates

template<bool T>
class MagicType {
public:
    bool magic = T;
};

int TestTemplate()
{
    MagicType<true> a1;
    MagicType<true> a2;
    MagicType<false> b;
    MagicType<(1>2)> c;

    std::vector<MagicType<true>> magic1 { a1, a2 };
    std::vector<MagicType<false>> magic2 { b, c };

    std::cout << magic1[0].magic << std::endl;
    std::cout << magic2[0].magic << std::endl;

    return 0;
}

// Type alias templates

template<typename T, typename U>
class MagicType2 {
public:
    T dark;
    U magic;
};

template<typename T>
using TrueDarkMagic = MagicType2<std::vector<T>, std::string>;

int TestTypeAliasTemplates() {
    TrueDarkMagic<bool> you;

    you.magic = "test";
    you.dark.push_back(true);
    you.dark.push_back(false);

    std::cout << you.magic << std::endl;
    std::cout << you.dark[0] << std::endl;

    return 0;
}

// Variadic templates

template<typename... Ts> class Magic1;

/*
class Magic1<int,
        std::vector<int>,
        std::map<std::string, std::vector<int>>> darkMagic;
*/

template<typename Require, typename... Args> class Magic2;

template<typename... Args> void printf(const std::string &str, Args... args);

template<typename... Ts>
void magic(Ts... args) {
    std::cout << "Parameter count: " << sizeof...(args) << std::endl;
}

int TestVariadicTemplates()
{
    magic(); // 0
    magic(1); // 1
    magic(1, ""); // 2

    return 0;
}

// Recursive template function

template<typename T0>
void printf1(T0 value) {
    std::cout << value << std::endl;
}

template<typename T, typename... Ts>
void printf1(T value, Ts... args) {
    std::cout << value << std::endl;
    printf1(args...);
}

int TestRecursiveTemplateFunction() {
    printf1(1, 2, "123", 1.1);
    return 0;
}

// Variable parameter template expansion

template<typename T0, typename... T>
void printf2(T0 t0, T... t) {
    std::cout << t0 << std::endl;
    if constexpr (sizeof...(t) > 0) printf2(t...);
}

int TestVariableParameterTemplateExpansion() {
    printf2(1, 2, "123", 1.1);
    return 0;
}

// Initialize list expansion

template<typename T, typename... Ts>
auto printf3(T value, Ts... args) {
    std::cout << value << std::endl;
    (void) std::initializer_list<T>{([&args] {
        std::cout << args << std::endl;
    }(), value)...};
}

// Fold expression

template<typename ... T>
auto sum(T ... t) {
    return (t + ...);
}

int TestFold() {
    std::cout << sum(1, 2, 3, 4, 5, 6, 7, 8, 9, 10) << std::endl;
    return 0;
}

// Non-type template parameter deduction

template <typename T, typename U>
auto add(T t, U u) {
    return t+u;
}

template <typename T, int BufSize>
class buffer_t {
public:
    T& alloc();
    void free(T& item);
private:
    T data[BufSize];
};

int TestNonTypeTemplateParameterDeduction1() {
    buffer_t<int, 100> buf; // 100 as template parameter
    return 0;
}

template <auto value> void foo() {
    std::cout << value << std::endl;
    return;
}

int TestNonTypeTemplateParameterDeduction2() {
    foo<10>(); // value as int
    return 0;
}

// 2.6 Object-oriented

// Delegate constructor

class Base {
public:
    int value1;
    int value2;

    Base() {
        value1 = 1;
    }

    Base(int value) : Base() { // delegate Base() constructor
        value2 = value;
    }
};

int TestDelegateConstructor() {
    Base b(2);
    std::cout << b.value1 << std::endl;
    std::cout << b.value2 << std::endl;

    return 0;
}

// Inheritance constructor

class Subclass : public Base {
public:
    using Base::Base; // inheritance constructor
};

int TestInheritanceConstructor() {
    Subclass s(3);
    std::cout << s.value1 << std::endl;
    std::cout << s.value2 << std::endl;

    return 0;
}

// Explicit virtual function overwrite

// override

struct Base2 {
    virtual void foo(int)
    {
        return;
    }
};

struct SubClass: Base2 {
    virtual void foo(int) override; // legal
    //virtual void foo(float) override; // illegal, no virtual function in super class
};

// final

struct Base3 {
    virtual void foo() final;
};

struct SubClass1 final: Base3 {
}; // legal

//struct SubClass2 : SubClass1 {
//}; // illegal, SubClass1 has final
//
//struct SubClass3: Base3 {
//    void foo(); // illegal, foo has final
//};

// Explicit delete default function

class Magic {
public:
    Magic() = default; // explicit let compiler use default constructor
    Magic& operator=(const Magic&) = delete; // explicit declare refuse constructor
    Magic(int magic_number);
};

// Strongly typed enumerations

enum class new_enum : unsigned int {
    value1,
    value2,
    value3 = 100,
    value4 = 100
};

template<typename T>
std::ostream& operator<<(
        typename std::enable_if<std::is_enum<T>::value,
        std::ostream>::type& stream, const T& e)
{
    return stream << static_cast<typename std::underlying_type<T>::type>(e);
}

int TestStronglyTypedEnumerations()
{
    if (new_enum::value3 == new_enum::value4) { // true
        std::cout << "new_enum::value3 == new_enum::value4" << std::endl;
    }

    std::cout << new_enum::value3 << std::endl;

    return 0;
}





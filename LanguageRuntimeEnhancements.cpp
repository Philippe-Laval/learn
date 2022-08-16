//
// Created by philippe on 16/08/2022.
//

#include "LanguageRuntimeEnhancements.h"

#include <iostream>
#include <type_traits>
#include <vector>
#include <algorithm>
#include <initializer_list>
#include <tuple>
#include <memory> // std::make_unique
#include <utility> // std::move
#include <functional>

// Chapter 03: Language Runtime Enhancements

// 3.1 Lambda Expression

// Basics

// [capture list] (parameter list) mutable(optional) exception attribute -> return type {
// function body
// }

// 1. Value capture

void lambda_value_capture() {
    int value = 1;
    auto copy_value = [value] {
        return value;
    };
    value = 100;

    auto stored_value = copy_value();
    std::cout << "stored_value = " << stored_value << std::endl;
    // At this moment, stored_value == 1, and value == 100.
    // Because copy_value has copied when its was created.
}

// 2. Reference capture

void lambda_reference_capture() {
    int value = 1;
    auto copy_value = [&value] {
        return value;
    };
    value = 100;
    auto stored_value = copy_value();
    std::cout << "stored_value = " << stored_value << std::endl;
// At this moment, stored_value == 100, value == 100.
// Because copy_value stores reference
}

// 3. Implicit capture

// [] empty capture list
// [name1, name2, …] captures a series of variables
// [&] reference capture, let the compiler deduce the reference list by itself
// [=] value capture, let the compiler deduce the value list by itself

// 4. Expression capture

void lambda_expression_capture() {
    auto important = std::make_unique<int>(1);
    auto add = [v1 = 1, v2 = std::move(important)](int x, int y) -> int {
        return x+y+v1+(*v2);
    };
    std::cout << add(3,4) << std::endl;
}

// Generic Lambda

void lambda_generic() {
    auto generic = [](auto x, auto y) {
        return x+y;
    };
    std::cout << generic(1, 2) << std::endl;
    std::cout << generic(1.1, 2.2) << std::endl;
}

// 3.2 Function Object Wrapper

// std::function

using foo = void(int); // function pointer
void functional(foo f) {
    f(1);
}

void TestFunctionObjectWrapper()
{
    auto f = [](int value) {
        std::cout << value << std::endl;
    };

    // When the capture list of a Lambda expression is empty,
    // the closure object can also be converted to a function pointer value for delivery

    functional(f); // call by function pointer
    f(1); // call by lambda expression
}


int foo2(int para) {
    return para;
}

void TestFunctionObjectWrapper2() {

    // std::function wraps a function that take int parameter and returns int value
    std::function<int(int)> func = foo2;
    int important = 10;

    std::function<int(int)> func2 = [&](int value) -> int {
        return 1+value+important;
    };

    std::cout << func(10) << std::endl;
    std::cout << func2(10) << std::endl;
}

// std::bind and std::placeholder

void foo3(int a, int b, int c) {
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << c << std::endl;
}

void TestBind() {
    // bind parameter 1, 2 on function foo,
    // and use std::placeholders::_1 as placeholder for the first parameter.
    auto bindFoo = std::bind(foo3, std::placeholders::_1, 2, 3);
    // when call bindFoo, we only need one param left
    bindFoo(1);

    auto bindFoo2 = std::bind(foo3, 1, 2, 3);
    // call bindFoo2
    bindFoo2();
}


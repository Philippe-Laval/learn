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
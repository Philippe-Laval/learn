//
// Created by philippe on 20/07/2022.
//

#include <iostream>

#include "FloatingPointArithmetic.h"

void Test40() {

    float total = 0;

    for (float a = 0; a != 2; a += 0.01f) {
        total += a;
    }
}

void Test41()
{
    double a = 0.1;
    double b = 0.2;
    double c = 0.3;
    if(a + b == c)
//This never prints on IEEE754-compliant machines
        std::cout << "This Computer is Magic!" << std::endl;
    else
        std::cout << "This Computer is pretty normal, all things considered." << std::endl;
}
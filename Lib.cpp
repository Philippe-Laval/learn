//
// Created by philippe on 20/07/2022.
//

#include "Lib.h"

int add2(int i) // Data that is passed into (int i) will be referred to by the name i
{ // while in the function's curly brackets or "scope."
    int j = i + 2; // Definition of a variable j as the value of i+2.
    return j; // Returning or, in essence, substitution of j for a function call to
// add2.
}

int add2(int i, int j) // However, when add2() is called with two parameters, the
{ // code from the initial declaration will be overloaded,
    int k = i + j + 2 ; // and the code in this declaration will be evaluated
    return k; // instead.
}

int operatorMul(int a, int b)
{
    return a*b;
}


int multiply(int a, int b)
{
    return a * b;
    // If multiply() is called with one parameter, the
    // value will be multiplied by the default, 7.
}
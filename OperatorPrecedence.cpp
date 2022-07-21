//
// Created by philippe on 20/07/2022.
//

#include "OperatorPrecedence.h"

#include <iostream>
#include <string>
#include <math.h>

using namespace std;

bool True(string id){
    cout << "True" << id << endl;
    return true;
}

bool False(string id){
    cout << "False" << id << endl;
    return false;
}

void Test30()
{
    bool result;
//let's evaluate 3 booleans with || and && to illustrate operator precedence
//precedence does not mean that && will be evaluated first but rather where
//parentheses would be added
//example 1
    result = False("A") || False("B") && False("C");
            // eq. False("A") || (False("B") && False("C"))

    result = True("A") || False("B") && False("C");
            // eq. True("A") || (False("B") && False("C"))
    cout << result << " :=====================" << endl;
}

void TestUnary()
{
    int a = 1;
    ++a; // result: 2
    a--; // result: 1
    int minusa = -a; // result: -1
    bool b = true;
    !b; // result: true
    a=4;
    int c = a++/2; // equal to: (a==4) 4 / 2 result: 2 ('a' incremented postfix)
    cout << a << endl; // prints 5!
    int d = ++a/2; // equal to: (a+1) == 6 / 2 result: 3

    int arr[4] = {1,2,3,4};
    int *ptr1 = &arr[0]; // points to arr[0] which is 1
    int *ptr2 = ptr1++; // ptr2 points to arr[0] which is still 1; ptr1 incremented
    std::cout << *ptr1++ << std::endl; // prints 2
    int e = arr[0]++; // receives the value of arr[0] before it is incremented
    std::cout << e << std::endl; // prints 1
    std::cout << *ptr2 << std::endl; // prints arr[0] which is now 2
}

void TestArithmeticOperators()
{
    double R = 10;
    double r = 5;
// volume of a spherical shell = 4 pi R^3 - 4 pi r^3
    double vol = 4.0*M_PI*R*R*R/3.0 - 4.0*M_PI*r*r*r/3.0;
//Addition:
    int a = 2+4/2; // equal to: 2+(4/2) result: 4
    int b = (3+3)/2; // equal to: (3+3)/2 result: 3
//With Multiplication
    int c = 3+4/2*6; // equal to: 3+((4/2)*6) result: 15
    int d = 3*(3+6)/9; // equal to: (3*(3+6))/9 result: 3
//Division and Modulo
    int g = 3-3%1; // equal to: 3 % 1 = 0 3 - 0 = 3
    int h = 3-(3%1); // equal to: 3 % 1 = 0 3 - 0 = 3

    int i = 3-3/1%3; // equal to: 3 / 1 = 3 3 % 3 = 0 3 - 0 = 3
    int l = 3-(3/1)%3; // equal to: 3 / 1 = 3 3 % 3 = 0 3 - 0 = 3
    int m = 3-(3/(1%3)); // equal to: 1 % 3 = 1 3 / 1 = 3 3 - 3 = 0
}

void TestLogical()
{
//These operators have the usual precedence in C++: AND before OR
}
//
// Created by philippe on 21/07/2022.
//

#include <iostream>
#include <vector>

#include "Loops.h"

/// Range-Based For
void Test110()
{
    std::vector<float> v = {0.4f, 12.5f, 16.234f};

    for(auto val: v)
    {
        // Does not change values in vector v
        val += 1.0;
        std::cout << val << " ";
    }

    std::cout << std::endl;
}

void Test111()
{
    std::vector<float> v = {0.4f, 12.5f, 16.234f};
    for(float &val: v)
    {
        // Change values in vector v
        val += 1.0;
        std::cout << val << " ";
    }

    const std::vector<float> v2 = {0.4f, 12.5f, 16.234f};
    for(const float &val: v2)
    {
        //val += 1.0;
        std::cout << val << " ";
    }

    std::vector<bool> v3(10);
    for(auto&& val: v3)
    {
        val = true;
    }

    std::cout << std::endl;
}

void Test112()
{
    float arr[] = {0.4f, 12.5f, 16.234f};
    for(auto val: arr)
    {
        std::cout << val << " ";
    }

    /*
    float *arr2 = new float[3]{0.4f, 12.5f, 16.234f};
    for(auto val2 : arr2) //Compile error.
    {
        std::cout << val2 << " ";
    }
     */

}

struct Rng
{
    float arr[3];
// pointers are iterators
    const float* begin() const {return &arr[0];}
    const float* end() const {return &arr[3];}
    float* begin() {return &arr[0];}
    float* end() {return &arr[3];}
};

void Test113()
{
    Rng rng = {{0.4f, 12.5f, 16.234f}};
    for(auto val: rng)
    {
        std::cout << val << " ";
    }
}

/// For loop
void Test114() {
    for (int i = 0; i < 10; i++) {
        std::cout << i << std::endl;
    }

    std::vector<std::string> names = {"Albert Einstein", "Stephen Hawking", "Michael Ellis"};
    for (std::vector<std::string>::iterator it = names.begin(); it != names.end(); ++it) {
        std::cout << *it << std::endl;
    }
}

/// While loop
void Test115()
{
    int i = 0;
    while (i < 10)
    {
        std::cout << i << " ";
        ++i; // Increment counter
    }
    std::cout << std::endl; // End of line; "0 1 2 3 4 5 6 7 8 9" is printed to the console
}

void f1(int x) {}
void f2(int x) {}
void f3(int x) {}


#define GOOD_MACRO(x) do { f1(x); f2(x); f3(x); } while(0)

/// Do-while loop
void Test116()
{
    int i =0;
    do
    {
        std::cout << i;
        ++i; // Increment counter
    }
    while (i < 0);
    std::cout << std::endl; // End of line; 0 is printed to the console

    i = 0;
    do
    {
        std::cout << i;
        ++i; // Increment counter
        if (i > 5)
        {
            break;
        }
    }
    while (true);
    std::cout << std::endl; // End of line; 0 1 2 3 4 5 is printed to the console


    // All calls are protected here
    int x = 0;
    if (i < 10) GOOD_MACRO(x);
}

/// Loop Control statements : Break and Continue
void Test117()
{
    for (int i = 0; i < 10; i++)
    {
        if (i == 4)
            break; // this will immediately exit our loop
        std::cout << i << '\n';
    }

    for (int i = 0; i < 6; i++)
    {
        if (i % 2 == 0) // evaluates to true if i is even
            continue; // this will immediately go back to the start of the loop
/* the next line will only be reached if the above "continue" statement
does not execute */
        std::cout << i << " is an odd number\n";
    }
}





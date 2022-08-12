//
// Created by philippe on 25/07/2022.
//
#include <iostream>
#include <vector>
#include "FlowControl.h"

void Test150()
{
    try {
        const int n = 10;
        std::vector<int> v(n);
        // do something
    } catch (const std::bad_alloc&) {
        std::cout << "failed to allocate memory for vector!" << std::endl;
    } catch (const std::runtime_error& e) {
        std::cout << "runtime error: " << e.what() << std::endl;
    } catch (...) {
        std::cout << "unexpected exception!" << std::endl;
        throw;
    }
}

void print_asterisks(int count) {
    if (count < 0) {
        throw std::invalid_argument("count cannot be negative!");
    }
    while (count--) { putchar('*'); }
}

unsigned int predecessor(unsigned int x) {
    return (x > 0) ? (x - 1) : (throw std::invalid_argument("0 has no predecessor"));
}

void Test151()
{
    int x;

    std::cout << "Please enter a positive number." << std::endl;
    std::cin >> x;
    if (x <= 0) {
        std::cout << "You didn't enter a positive number!" << std::endl;
        abort();
    }

    std::cin >> x;
    if (x%2 == 0) {
        std::cout << "The number is even\n";
    } else {
        std::cout << "The number is odd\n";
    }
}

void Test152()
{
    // break, continue

    for(int i=0;i<10;i++){
        if(i%2==0)
            continue;
        std::cout<<"\n @"<<i;
    }
    std::cout << std::endl;

    exit(EXIT_SUCCESS);
    exit(EXIT_FAILURE);
}

int Test153(int argc) {
    if (argc < 2) {
        std::cout << "Missing argument\n";
        return EXIT_FAILURE; // equivalent to: exit(EXIT_FAILURE);
    }
}


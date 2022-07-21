//
// Created by philippe on 20/07/2022.
//

#include <iostream>

#include "BitOperators.h"

void Test50() {
    int a = 5; // 0101b (0x05)
    int b = 12; // 1100b (0x0C)
    int c = a | b; // 1101b (0x0D)
    std::cout << "a = " << a << ", b = " << b << ", c = " << c << std::endl;

    a = 5; // 0101b (0x05)
    a |= 12; // a = 0101b | 1101b
}

void Test51()
{
    int a = 5; // 0101b (0x05)
    int b = 9; // 1001b (0x09)
    int c = a ^ b; // 1100b (0x0C)
    std::cout << "a = " << a << ", b = " << b << ", c = " << c << std::endl;

}

void Test52()
{
    int a = 6; // 0110b (0x06)
    int b = 10; // 1010b (0x0A)
    int c = a & b; // 0010b (0x02)
    std::cout << "a = " << a << ", b = " << b << ", c = " << c << std::endl;
}

void Test53()
{
    int a = 1; // 0001b
    int b = a << 1; // 0010b
    std::cout << "a = " << a << ", b = " << b << std::endl;

    a = 2147483647; // 0111 1111 1111 1111 1111 1111 1111 1111
    b = a << 1; // 1111 1111 1111 1111 1111 1111 1111 1110
    std::cout << "a = " << a << ", b = " << b << std::endl;
}

void Test54()
{
    int a = 2; // 0010b
    int b = a >> 1; // 0001b
    std::cout << "a = " << a << ", b = " << b << std::endl;
}


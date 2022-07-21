//
// Created by philippe on 20/07/2022.
//
#include <iostream>
#include <type_traits>
#include <bitset>

#include "BitManipulation.h"

template <typename T>
T rightmostSetBitRemoved(T n)
{
    // For c++11 and later
    static_assert(std::is_integral<T>::value && !std::is_signed<T>::value, "type should be unsigned");

    return n & (n - 1);
}

void Test60()
{
    unsigned n = 1;
    unsigned int a = rightmostSetBitRemoved(n);

    std::cout << "a = " << a << std::endl;
}

void Test61()
{
    std::bitset<10> x;
    x.set(); // Sets all bits to '1'
}

void Test62()
{
    std::bitset<4> num1(std::string("0100"));
    num1.flip(2); // num is now 0000
    num1.flip(0); // num is now 0001
    num1.flip(); // num is now 1110 (flips all bits)


    std::bitset<4> num2(std::string("0010"));
    bool bit_val = num2.test(1); // bit_val value is set to true;

    // Setting a bit
    std::bitset<5> num3(std::string("01100"));
    num3.set(0); // num is now 01101
    num3.set(2); // num is still 01101
    num3.set(4,true); // num is now 11110

    // Clearing a bit
    std::bitset<5> num4(std::string("01100"));
    num4.reset(2); // num is now 01000
    num4.reset(0); // num is still 01000
    num4.set(3,false); // num is now 00000

    // Changing the nth bit to x
    std::bitset<5> num5(std::string("00100"));
    num5.set(0,true); // num is now 00101
    num5.set(2,false); // num is now 00001
}

/// Counting bits set
//unsigned popcount(std::uint64_t x)
//{
//    const std::uint64_t m1 = 0x5555555555555555; // binary: 0101...
//    const std::uint64_t m2 = 0x3333333333333333; // binary: 00110011..
//    const std::uint64_t m4 = 0x0f0f0f0f0f0f0f0f; // binary: 0000111100001111
//    x -= (x >> 1) & m1; // put count of each 2 bits into those 2 bits
//    x = (x & m2) + ((x >> 2) & m2); // put count of each 4 bits into those 4 bits
//    x = (x + (x >> 4)) & m4; // put count of each 8 bits into those 8 bits
//    return (x * h01) >> 56; // left 8 bits of x + (x<<8) + (x<<16) + (x<<24) + ...
//}

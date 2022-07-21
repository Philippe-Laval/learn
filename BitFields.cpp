//
// Created by philippe on 20/07/2022.
//
#include <iostream>

#include "BitFields.h"

struct FileAttributes
{
    unsigned int ReadOnly: 1;
    unsigned int Hidden: 1;
};

struct Date
{
    unsigned int Year : 13; // 2^13 = 8192, enough for "year" representation for long time
    unsigned int Month: 4; // 2^4 = 16, enough to represent 1-12 month values.
    unsigned int Day: 5; // 32
};

void Test70()
{
    Date d;
    d.Year = 2016;
    d.Month = 7;
    d.Day = 22;
    std::cout << "Year:" << d.Year << std::endl <<
              "Month:" << d.Month << std::endl <<
              "Day:" << d.Day << std::endl;
}
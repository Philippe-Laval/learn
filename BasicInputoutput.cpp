//
// Created by philippe on 21/07/2022.
//

#include <iostream>

#include "BasicInputoutput.h"



int Test100()
{
    int value;
    std::cout << "Enter a value: " << std::endl;
    std::cin >> value;
    std::cout << "The square of entered value is: " << value * value << std::endl;
    return 0;
}
//
// Created by philippe on 21/07/2022.
//
#include <algorithm> // std::sort
#include <iostream>
#include <iomanip>
#include <vector> // std::vector

#include "Iterators.h"

void Test90()
{
    std::vector<std::string> a;

    a.push_back("test1");
    a.push_back("test2");
    a.push_back("test3");
    a.push_back("test4");
    a.push_back("test5");

    auto my_iterator = a.begin(); // position
    auto my_value = *my_iterator; // value

    auto first = a.begin();
    ++first; // advance the iterator 1 position

    std::advance(first, 1); // advance the iterator 1 position
    first = std::next(first); // returns iterator to the next element
    std::advance(first, -1); // advance the iterator 1 position backwards
    first = std::next(first, 2); // returns iterator to the element 2 position forward
    first = std::prev(first, 3); // returns iterator to the element 3 position backward
    auto dist = std::distance(a.begin(), first);
}

void Test91()
{
    std::vector<int> v = { 1, 2, 3, 4, 5 }; //initialize vector using an initializer_list
    for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it)
    {
        std::cout << *it << " ";
    }

}

void Test92() {

}
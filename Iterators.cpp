//
// Created by philippe on 21/07/2022.
//
#include <algorithm> // std::sort
#include <iostream>
#include <iomanip>
#include <vector> // std::vector
#include <map>

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
    std::cout << std::endl;

    std::vector<int> v2{1, 2, 3, 4, 5};
    for (std::vector<int>::reverse_iterator it = v2.rbegin(); it != v2.rend(); ++it)
    {
        std::cout << *it << " ";
    } // prints 54321

    std::cout << std::endl;
}

void Test92() {
    std::map<char,int> mymap;
    mymap['b'] = 100;
    mymap['a'] = 200;
    mymap['c'] = 300;

    // Iterate over all tuples
    for (std::map<char,int>::iterator it = mymap.begin(); it != mymap.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';

    std::cout << std::endl;
}

/// Stream Iterators
void Test93()
{
    // Data stream. Any number of various whitespace characters will be OK.
    std::istringstream istr("1\t 2 3 4");

    std::vector<int> v;
    // Constructing stream iterators and copying data from stream into vector.
    std::copy(
        // Iterator which will read stream data as integers.
        std::istream_iterator<int>(istr),
        // Default constructor produces end-of-stream iterator.
        std::istream_iterator<int>(),
        std::back_inserter(v));
    // Print vector contents.
    std::copy(v.begin(), v.end(),
        //Will print values to standard output as integers delimited by " -- ".
        std::ostream_iterator<int>(std::cout, " -- "));

    std::cout << std::endl;
}

/// C Iterators (Pointers)
void Test94()
{
    // This creates an array with 5 values.
    const int array[] = { 1, 2, 3, 4, 5 };

#ifdef BEFORE_CPP11
    // You can use `sizeof` to determine how many elements are in an array.
    const int* first = array;
    const int* afterLast = first + sizeof(array) / sizeof(array[0]);
    // Then you can iterate over the array by incrementing a pointer until
    // it reaches past the end of our array.
    for (const int* i = first; i < afterLast; ++i) {
        std::cout << *i << std::endl;
    }
#else
    // With C++11, you can let the STL compute the start and end iterators:
    for (auto i = std::begin(array); i != std::end(array); ++i) {
        std::cout << *i << std::endl;
    }
#endif

}
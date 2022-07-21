//
// Created by philippe on 20/07/2022.
//

#include <algorithm> // std::sort
#include <iostream>
#include <iomanip>
#include <vector> // std::vector

#include "Arrays.h"

using namespace std;

void Test80()
{
    // Array initialization
    int arrayOfInts[5] = {10, 20, 30, 40, 50};
    int arrayOfInts2[] = {10, 20, 30, 40, 50};
    int arrayOfInts3[5] = {10,20}; // means 10, 20, 0, 0, 0

    char arrayOfChars[5]; // declare the array and allocate the memory, don't initialize
    char arrayOfChars2[5] = { 'a', 'b', 'c', 'd', 'e' } ; //declare and initialize
    double arrayOfDoubles[5] = {1.14159, 2.14159, 3.14159, 4.14159, 5.14159};
    string arrayOfStrings[5] = { "C++", "is", "super", "duper", "great!"};

    int array[5] = { 10/*Element no.0*/, 20/*Element no.1*/, 30, 40, 50/*Element no.4*/};
    std::cout << array[4]; //outputs 50
    std::cout << array[0]; //outputs 10
}


void Test81()
{
    int const n_rows = 3;
    int const n_cols = 7;
    int const m[n_rows][n_cols] = // A raw array matrix.
            {
                    { 1, 2, 3, 4, 5, 6, 7 },
                    { 8, 9, 10, 11, 12, 13, 14 },
                    { 15, 16, 17, 18, 19, 20, 21 }
            };
    for( int y = 0; y < n_rows; ++y )
    {
        for( int x = 0; x < n_cols; ++x )
        {
            cout << setw( 4 ) << m[y][x]; // Note: do NOT use m[y,x]!
        }
        cout << '\n';
    }
}

auto int_from( istream& in ) -> int { int x = 0; in >> x; return x; }

auto Test82() -> int
{
    cout << "Sorting n integers provided by you.\\n";
    cout << "n? ";
    int const n = int_from( cin );
    int* a = new int[n]; // ← Allocation of array of n items.
    for( int i = 1; i <= n; ++i )
    {
        cout << "The #" << i << " number, please: ";
        a[i-1] = int_from( cin );
    }
    sort( a, a + n );
    for( int i = 0; i < n; ++i ) { cout << a[i] << ' '; }
    cout << '\\n';
    delete[] a;
}

void Test83()
{
    char MyArray[] = { 'X','o','c','e' };
    const auto n = std::extent<decltype(MyArray)>::value;
    std::cout << n << "\n"; // Prints 4

    int a[] = { -5, 10, 15 };
    std::cout << std::size(a) << '\n';
}

//int int_from( std::istream& in ) { int x = 0; in >> x; return x; }

/// Expanding dynamic size array by using std::vector
int Test84()
{
    cout << "Sorting integers provided by you.\n";
    cout << "You can indicate EOF via F6 in Windows or Ctrl+D in Unix-land.\n";
    vector<int> a; // ← Zero size by default.
    while( cin )
    {
        cout << "One number, please, or indicate EOF: ";
        int const x = int_from( cin );
        if( !cin.fail() ) { a.push_back( x ); } // Expands as necessary.
    }
    sort( a.begin(), a.end() );

    int const n = a.size();
    for( int i = 0; i < n; ++i ) { cout << a[i] << ' '; }
    cout << '\n';
}


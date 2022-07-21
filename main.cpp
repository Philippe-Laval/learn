#include <iostream>

#include "Lib.h"
#include "Literals.h"
#include "OperatorPrecedence.h"
#include "FloatingPointArithmetic.h"
#include "BitOperators.h"
#include "BitManipulation.h"
#include "Arrays.h"
#include "Iterators.h"
#include "BasicInputoutput.h"
#include "Loops.h"

int main() {
    // This is a single-line comment.
    int a; // this also is a single-line comment
    int i; // this is another single-line comment

    /*
     * This is a block comment.
     */

    std::cout << "Hello, World!" << std::endl;

    std::cout << add2(2) << std::endl; // add2(2) will be evaluated at this point,
// and the result is printed.

    std::cout << add2(1, 3) << std::endl;

#define something true

#if something == true
    std::cout << TRUE << std::endl;
#else
    std::cout << FALSE << std::endl;
#endif

#ifdef something
    std::cout << TRUE << std::endl;
#endif

    //std::cout << i Mul j << std::endl;

    //struct S s1;
    // s1 = new S();

    //T t1;

    Test30();
    TestUnary();

    Test41();

    Test60();
    Test61();
    Test62();

    Test81();
    //int result = Test82();
    Test83();

    Test90();
    Test91();
    Test92();
    Test93();

    // Test100();
    Test110();
    Test111();



    return 0;
}



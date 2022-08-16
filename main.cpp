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
#include "FileIO.h"
#include "Metaprogramming.h"

#include "LanguageUsabilityEnhancements.h"
#include "LanguageRuntimeEnhancements.h"

void Book();

int main() {
    // This is a single-line comment.
    int a; // this also is a single-line comment
    int i; // this is another single-line comment

    Book();
    return 0;

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

    Test120();
    Test123();
    Test125();
    Test128();

    Test160();
    Test161();

    return 0;
}



void Chapter02()
{
    TestNullptr();
    TestConstexpr();
    TestIfSwitch();
    TestInitializerList();
    TestInitializerList2();
    TestStructuredBinding();
    TestInitializerList3();
    TestDecltype();
    TestTailTypeInference();
    TestDecltypeAuto();
    TestIfConstexpr();
    TestLoop();
    TestTemplate();
    TestTypeAliasTemplates();
    TestVariadicTemplates();
    TestRecursiveTemplateFunction();
    TestVariableParameterTemplateExpansion();
    TestFold();
    TestDelegateConstructor();
    TestInheritanceConstructor();
    TestStronglyTypedEnumerations();
}

void Chapter03()
{
    lambda_value_capture();
    lambda_reference_capture();
    lambda_expression_capture();
    lambda_generic();
}

void Book() {
    //Chapter02();
    Chapter03();
}

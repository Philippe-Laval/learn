//
// Created by philippe on 23/07/2022.
//

#include "ClassesStructures.h"

/// Class basics

struct Vector1
{
    int x;
    int y;
    int z;
};
// are equivalent to
class Vector2
{
public:
    int x;
    int y;
    int z;
};

void Test340() {
    Vector1 my_vector;

    my_vector.x = 10;
    my_vector.y = my_vector.x + 1; // my_vector.y = 11;
    my_vector.z = my_vector.y - 4; // my:vector.z = 7;

}

/// Final classes and structs

class A final {
};

// Compilation error: cannot derive from final class:
//class B : public A {
//};

class A2 {
};

class B final : public A2 {
};

struct MyStruct {
    int x;
};

class MyClass {
public:
    int x; };

void Test341() {
    MyStruct s;
    s.x = 9; // well formed, because x is public
    MyClass c;
    c.x = 9;
}

class MyClass2 {
public: /* Methods: */
    int x() const noexcept { return m_x; }
    void setX(int const x) noexcept { m_x = x; }
private: /* Fields: */
    int m_x;
};

struct Plus2Base {
    int value() noexcept { return calculateValue() + 2; }
protected: /* Methods: */
    virtual int calculateValue() noexcept = 0;
};

struct FortyTwo: Plus2Base {
protected: /* Methods: */
    int calculateValue() noexcept final override { return 40; }
};

/// Inheritance


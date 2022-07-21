//
// Created by philippe on 20/07/2022.
//

struct S {
    int x;
    S& operator=(const S& other) {
        x = other.x;
        // return a reference to the object being assigned to
        return *this;
    }

  //  T t{this};
};

struct T {
    int a;
    int b;

  //  T(const S* s);
// ...
};

bool f()
{
    return false;
}

int Test()
{
    int d = 42;
    int o = 052;
    int x = 0x2a;
    int X = 0X2A;
    int b = 0b101010; // C++14
    unsigned int u_1 = 42u;

    unsigned long long l1 = 18446744073709550592ull; // C++11
    unsigned long long l2 = 18'446'744'073'709'550'592llu; // C++14
    unsigned long long l3 = 1844'6744'0737'0955'0592uLL; // C++14
    unsigned long long l4 = 184467'440737'0'95505'92LLU; // C++14

    bool ok = true;
    if (!f()) {
        ok = false;
        goto end;
    }

    end:

    return 0;
}

class Widget
{

};

void Test2()
{
    Widget* p = new Widget();
    delete p;
    p = nullptr; // set the pointer to null after deletion
}
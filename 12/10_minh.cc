#include <iostream>

struct A
{
    virtual ~A() {}
    int i;
};

struct B: public A
{ };

struct C: public A
{};

struct D: public B, public C
{};

int main()
{
    D *d = new D;
    d->B::i = 2;
    std::cout<<d->C::i<<std::endl;
}

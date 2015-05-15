#include <iostream>

struct A
{
    virtual ~A() {}
    int i;
};

struct B: public virtual A
{ };

struct C: public virtual A
{};

struct D: public B, public C
{};

int main()
{
    D *d = new D;
    d->B::i = 2;
    std::cout<<d->C::i<<std::endl;
}

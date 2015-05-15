#include <iostream>

struct A
{
    virtual ~A() {}
    virtual void f() { std::cout<<"A"<<std::endl; }
};

struct B
{
    virtual ~B() {}
    virtual void f() { std::cout<<"B"<<std::endl; }
};

struct C: public A, public B
{};

int main()
{
    C *c = new C;
    c->f();
    c->A::f();
    c->B::f();
}

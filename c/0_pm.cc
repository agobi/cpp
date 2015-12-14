#include <iostream>

struct A
{
    A() { std::cout<<"A()"; }
    A(const A&) { std::cout<<"A(A)"; }
    ~A() { std::cout<<"~A()"; }
};

void f(A b)
{
}

int main()
{
    A v; std::cout<<std::endl;
    A v2 = v; std::cout<<std::endl;
    f(v); std::cout<<std::endl;
}

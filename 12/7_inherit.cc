#include <iostream>

struct A
{
    void f() {std::cout<<"a"<<std::endl;}
    virtual void g() {std::cout<<"a"<<std::endl;}
};

struct B: public A
{
    void f() {std::cout<<"b"<<std::endl;}
    void g() {std::cout<<"b"<<std::endl;}
};

struct sikidom
{
    virtual float terulet();
};

struct kor
{
    kor(float r): _r(r) {}
    float _r;
    float terulet() { return 3.14*_r*_r; }
};

struct negyzet
{
    negyzet(float a): _a(a) {}
    float _a;
    float terulet() { return _a*_a; }
};

int main()
{
    A *a = new B;
    A &ar = *a; // static vs. dynamic type
    a->f();
    a->g();

    delete a;
}



class A
{
    virtual void f() { std::cout<<"A::f()"<<std::endl; }
};

class B: public A
{
    void f() { std::cout<<"B::f()"<<std::endl; }
    int x;
};

void f(A a)
{
    a.f();
}

void g(A &a)
{
    a.f();
}

int main()
{
    B b;
    A &a = b;
    a.f();
    f(a);
    g(a);

    B &q = dynamic_cast<B&>(a);
}

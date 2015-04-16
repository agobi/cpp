#include <iostream>

struct T;
void f(int) {}
void f(T *) {}

int main()
{
    int *p = (int *)NULL; // C (void *)
    f(0);

    //void *q = p;
    //p = (int *)q; // C

    p = 0; // C++98
    p = nullptr; // C++11 (std::nullptr_t)

    if(p) // hamis
        std::cout<<*p<<std::endl;

    {
        int i;
        p = &i;
    }
    //std::cout<<*p<<std::endl;


    int j;
    p = &j;
    *p=42; // j=42;
    if(p)
        std::cout<<*p<<std::endl;

}

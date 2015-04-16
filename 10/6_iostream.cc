#include <iostream>

struct T
{
    // konverzio bool-ra
    operator bool ()
    {
        return true;
    }

    // konverzio void *-ra
    operator void * ()
    {
        // T* this;
        return 0;
    }
};

int main()
{
    T t;
    bool b = t;

    int i;
    while(std::cin >> i)
    { }
    /*
     while(operator >> (std::cin, i))
     { }
        ->
     while(std::cin)
     {}
     */

    while(i << std::cin)
    {}

}

#include <iostream>
#include <algorithm>

struct f
{
    bool
    operator () (int p) const
    {
        return p%2;
    }
};

bool ff(int p)
{
    return p%2;
}

int main()
{
    int x[] = {2,3,4,5,6};
    int *p = std::find_if(x, x+5, ff);
    std::cout<<*p<<std::endl;

    bool (*fp)(int) = ff; // fp-t deklaralom
    std::cout<<fp(3)<<std::endl;
}

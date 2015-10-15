#include <iostream>

// dangling!!!
int &g(int a)
{
//    int q = 64;
//    return q;
    return a;
}

int &f(int &a)
{
    return a;
}

int &h()
{
    static int a = 5;
    return a;
}

// nem okoz nevutkozest mas forditasi egyseggel
static int a;
// C++ -ban: namespace { }

int main(int argc, char *[])
{
    int i = 6;
    int j = 7;
    int &r = (argc % 2) ? i : j;
    r = 42;
    ((!(argc % 2)) ? i : j) = 42;

    int &q = g(i);
    f(i) = 137;
    h() = -1;
    std::cout<<i<<" "<<j<<" "<<q<<std::endl;
    std::cout<<h()<<std::endl;
}

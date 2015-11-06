#include <algorithm>
#include <iostream>

struct rational
{
    int num, den;
};

int gcd(int a, int b)
{
    if(a < b)
        std::swap(a, b);

    while(b != 0) {
        int tmp = b;
        b = a % b;
        a = tmp;
    }

    return a;
}

rational add(rational a, rational b)
{
    int g = gcd(a.den, b.den);
    rational r = {
        a.num * (b.den/g) + b.num * (a.den/g),
        (a.den/g) * b.den
    };
    return r;
}

int main() {
    rational r = {2,3};
    std::cout<< r.num << " " << r.den << std::endl;
}

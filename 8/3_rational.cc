#include <algorithm>
#include <iostream>

class rational
{
public:
    static int gcd(int a, int b)
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

    // 0/0, 0/1, 4/2
    // den != 0
    // gcd(num, den) == 1
    // num == 0 -> den == 1
    const int num, den;

    // d != 0
    rational(int n=0, int d=1)
        : num(n / gcd(n,d)), den(num==0?1:(d / gcd(n,d)))
    { }
};

rational operator + (const rational& lhs, const rational& rhs)
{
    int g = rational::gcd(lhs.den, rhs.den);
    return rational(
        lhs.num * (rhs.den/g) + rhs.num * (lhs.den/g),
        (lhs.den/g) * rhs.den
    );
}

bool operator == (const rational &lhs, const rational& rhs)
{
    return lhs.num * rhs.den == rhs.num * lhs.den;
}
//struct { int x, int y } p1, p2, p3;

int main() {
    rational r(2,3);
    rational r3 = 6+r;

    std::cout<< r3.num << " " << r3.den << std::endl;
}

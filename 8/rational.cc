#include <iostream>
#include "rational.h"

namespace numeric
{

int
gcd(int a, int b)
{
    if(a<0) a=-a;
    if(b<0) b=-b;
    if(a<b) std::swap(a,b);
    while(b!=0)
    {
        // (a / b)*b + a%b == a
        a %= b;
        std::swap(a,b);
    }
    return a;
}

rational &
rational::operator *= (const rational &b)
{
    int c = gcd(_num, b._den);
    int d = gcd(_den, b._num);
    _num /= c;
    _den /= d;
    _num *= b._num / d;
    _den *= b._den / c;

    return *this;
}

rational::rational(int n, int d)
{
    int c = gcd(n, d);
    if(d<0) c = -c;
    _num = n / c;
    _den = d / c;
}

rational
operator * (rational lhs, const rational &rhs)
{
    return lhs *= rhs;
}

std::ostream&
operator << (std::ostream& s, const rational &r) {
    s<<r.num()<<"/"<<r.den();
    return s;
}

}

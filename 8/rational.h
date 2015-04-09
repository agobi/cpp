#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>

namespace numeric
{

extern "C"
int
gcd(int a, int b);

class rational
{
private:
    // gcd(num, den) == 1
    // den >= 1
    int _num, _den;

public:
    inline const int &
    num() const
    {
        return _num;
    }

    inline const int &
    den() const
    {
        return _den;
    }

    rational &
    operator *= (const rational &b);

    // d != 0
    rational(int n = 0, int d = 1);

    inline rational &
    operator ++ ()
    {
        _num += _den;
        return *this;
    }

    inline rational
    operator ++ (int)
    {
        rational ret = *this;
        ++*this;
        return ret;
    }
};

rational
operator * (rational lhs, const rational &rhs);

std::ostream&
operator << (std::ostream& s, const rational &r);

} // namespace rational

#endif//RATIONAL_H

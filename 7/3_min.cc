#include <iostream>

template <typename T, typename Q>
const T&
min(const T &a, const T &b, Q q)
{
    return q(a,b)?a:b;
}

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

class rational
{
private:
    // gcd(num, den) == 1
    // den >= 1
    int _num, _den;

public:
    const int &
    num() const
    {
        return _num;
    }

    const int &
    den() const
    {
        return _den;
    }

    rational &
    operator *= (const rational &b)
    {
        int c = gcd(_num, b._den);
        int d = gcd(_den, b._num);
        _num /= c;
        _den /= d;
        _num *= b._num / d;
        _den *= b._den / c;

        return *this;
    }

    // d != 0
    rational(int n = 0, int d = 1)
    {
        int c = gcd(n, d);
        if(d<0) c = -c;
        _num = n / c;
        _den = d / c;
    }


    rational &
    operator ++ ()
    {
        _num += _den;
        return *this;
    }

    rational
    operator ++ (int)
    {
        rational ret = *this;
        ++*this;
        return ret;
    }

/*
    rational
    operator * (rational rhs) const
    {
        return rhs *= (*this):
    }
    */
};

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

struct lt
{
    bool
    operator () (const rational& lhs, const rational &rhs)
    {
        return lhs.num() * rhs.den() < rhs.num() * lhs.den();
    }
};

int main()
{
    rational r(3, 7), q(2, 5);
    std::cout<<min(r, q, lt())<<std::endl;
    lt x;
    x(2,3);
}

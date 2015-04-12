#include <iostream>
#include <fstream>

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

int
main()
{
    rational r(2, 3);
    rational q(6, 4);
    rational p(2); // p = 2
    rational n;
    std::ofstream f("alma.txt");

    //r.num = 4;

    ++q++;
    r *= q;
    const rational& z = r;
    // rational q2 = z;
    std::cout<<z<<std::endl;

    n = r * 2;
    std::cout<<r<<std::endl;
    f<<r<<std::endl;
}

#include <algorithm>
#include <iostream>

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

class rational
{
private:
    // 0/0, 0/1, 4/2
    // den != 0
    // gcd(num, den) == 1
    // num == 0 -> den == 1
    int _num, _den;

public:
    // d != 0
    rational(int num=0, int den=1)
    {
        int z = gcd(num, den);
        _num = num / z;
        _den = den / z;
        if(_num == 0) _den = 1;
    }

    rational operator +(rational b)
    {
        int g = gcd(_den, b._den);
        rational r(
            _num * (b._den/g) + b._num * (_den/g),
            (_den/g) * b._den
        );
        return r;
    }

    int num() { return _num; }
    int den() { return _den; }

};

//struct { int x, int y } p1, p2, p3;

int main() {
    rational r(2,3);
    rational r2(1);
    rational r3; // analogia: int x;

    r3 = r+r2+6; //<- add(r, r2);

    std::cout<< r3.num() << " " << r3.den() << std::endl;
}

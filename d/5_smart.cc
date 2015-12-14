#include <cmath>
#include <iostream>
#include <vector>
#include <memory>

class sikidom
{
public:
    virtual float kerulet() = 0;
    virtual float terulet() = 0;
    virtual inline ~sikidom() {}
};

class negyzet: public sikidom
{
    float _a;
public:
    negyzet(float a): _a(a) { /*new int[1024];*/ }
    ~negyzet() { /*delete[] ... */}
    float kerulet() { return 4*_a; }
    float terulet() { return _a*_a; }
};

class kor: public sikidom
{
    float _r;
public:
    kor(float r): _r(r) {}
    float kerulet() { return 2.0 * M_PI * _r; }
    float terulet() { return M_PI * _r * _r; }
};

int main()
{
    std::vector<std::unique_ptr<sikidom>> v;
    v.push_back(std::make_unique(new negyzet(2)));


}

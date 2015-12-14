#include <cmath>
#include <iostream>

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
    //sikidom s;
    //sikidom *s = new sikidom;
    sikidom *t = new negyzet(4);
    std::cout << t->terulet() << " " << t->kerulet() << std::endl;

    sikidom **p = new sikidom*[16]; // 0-val kitolti
    p[0] = new negyzet(2);
    p[1] = new kor(3);
    for(int i=0; i<16; ++i)
    {
        delete p[i]; // 0 ptr-re lehet delete
        p[i] = 0; // best practice, nincs dangling
    }
    delete[] p;

    std::vector<sikidom*> v;
    v.push_back(new negyzet(3));
    while(!v.empty())
    {
        delete v.back();
        v.pop_back();
    }

    delete t;
}

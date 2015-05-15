#include <iostream>

struct sikidom
{
    virtual float terulet() = 0;
    virtual ~sikidom() {}
};

struct kor: public sikidom
{
    kor(float r): _r(r) {}
    float _r;
    float terulet() { return 3.14*_r*_r; }
};

struct negyzet: public sikidom
{
    negyzet(float a): _a(a) {}
    float _a;
    float terulet() { return _a*_a; }
};

int main()
{
    sikidom *p[2] = {0, 0};
    p[0] = new negyzet(2);
    p[1] = new kor(1);
    for(int i=0; i<2; ++i)
    {
        std::cout<<p[i]->terulet()<<std::endl;
    }

    for(int i=0; i<2; ++i)
        delete p[i];
}

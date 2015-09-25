#ifndef DEF_H
#define DEF_H

// deklaracio
extern long double pi;

extern "C" void f();

// forward deklaracio
// == ostream, amit cout tipusa
namespace std
{
    template<typename T> class basic_ostream<T>;
}

namespace my
{
    // definicio
    class C {
    public:
        // deklaracio
        void f(std::basic_ostream<char> &);

        // overload == tulterheles
        void f();
    };
}

#endif//DEF_H

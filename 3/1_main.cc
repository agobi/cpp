#include <iostream>
#include "def.h"

int main()
{
    using namespace my;

    // s fv deklaracio
    std::string f();
    std::string s;
    {
        int s;
        // s mast mas  jelent
    } // int s megszunik

    /*my::*/C c;
    c.f(std::cout);
}

#include <iostream>

// globalis valtozok 0-ra inicializalodnak
int g; // = 0;

void func()
{
    // static (lexical) scoping
    // tehat:  v- Ez a g a globalis g
    std::cout<<g<<std::endl;

    // lehetne a hivas helyen levo g
    // pl perl (nem mindig) es shell script
}

int main()
{
    int l=1;

    {
        int l=2; // Javaban ez nem megengedett
        int g=2;
        func();
    }
};

#include <algorithm>

// A legkulso meret itt sem szamit, az konvertalodik pointerre
//void f(int a[][2])
void f(int (*x)[2])
{
}


int main()
{
    int a[][2] = {{0,1}, {2,3}, {4,5}};

    // tombre mutato pointer
    int (*p)[2] = a;
    f(a);

    // pointerekbol allo tomb
    int *q[] = {a[0], a[1], a[2]};


    int **m = new int *[16];
    for(int i=0; i<16; ++i)
        m[i] = new int[16];
    // m, mint matrix

    for(int i=0; i<16; ++i)
        delete[] m[i];
    delete[] m;
}

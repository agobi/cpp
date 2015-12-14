#include <algorithm>

// A kovetkezo deklaraciok ekvivalensek:
//void f(int x[10])
//void f(int x[])
void f(int *x)
{
}

// De ez egy referencia a tombre, itt mar szamit a meret
template<size_t N>
void g(int (&x)[N])
{
}

int main()
{
//          Ezt nem kell kiirni
//          v
//    int a[3] = {1,2,3};
    int a[] = {3,1,2};

    // + null character
    const char b[7] = "almafa";

    std::sort(a, a + sizeof(a)/sizeof(*a));

    // automatikusan konvertalodik pointerre
    int *p = a;
    f(a); g(a);

    // random access iterator:
    // ++p; p-=1; p != p2; *p
    p[2] == *(p+2); // szintaktikus cukor

    int *c = new int[10];
    c[2] = 3;
    delete [] c; // new[] -> delete[]
}

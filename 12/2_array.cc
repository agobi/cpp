#include <iostream>

//size_t == unsigned long
//size_t len(int t[2987])
size_t len(int *t)
{
    return sizeof(t)/sizeof(t[0]);
}

template<size_t N> // value template
size_t len2(int (&t)[N])
{
    return N;
    //return sizeof(t)/sizeof(t[0]);
}

int main()
{
    int x[] = {2,3,4,5,6};
    //int x[5] = {2,3,4,5,6};
    //      ^ felesleges

    std::cout<<sizeof(x)<<" "<<5*sizeof(int)<<std::endl;
    // nalam: sizeof(int) = 4

    std::cout<<sizeof(x)/sizeof(x[0])<<" "<<len(x)<<" "<<len2(x)<<std::endl;

    // 1 = sizeof(char) <= sizeof(short) <= sizeof(int) <= sizeof(long)
    // short min 16 bit, long min 32
    // sizeof(signed T) == sizeof(unsigned T)
    //
    std::cout<<*x<<std::endl;

    int *p = x;
    std::cout<<*(p+2)<<" "<<p[2]<<" "<<2[p]<<std::endl;
}

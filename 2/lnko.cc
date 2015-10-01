#include <algorithm>

int lnko(int a, int b)
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

#include <algorithm>
#include "lkkt.h"
#include "lnko.h"

int lkkt(int a, int b)
{
    int l = lnko(a, b);
    return a * (b / l);
}

#include <iostream>
#include <iterator>
#include <algorithm>

int main()
{
    int x[] = {2,3,4,5,6,7,8};
    std::copy(x, x+sizeof(x)/sizeof(x[0]),
            std::ostream_iterator<int>(std::cout, "\n"));
}

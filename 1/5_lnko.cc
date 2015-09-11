#include <iostream>

int main() {
    int a = 42;
    int b = 36;

    if(a < b)
        std::swap(a, b);

    while(b != 0) {
        int tmp = b;
        b = a % b;
        a = tmp;
    }

    std::cout<<a<<std::endl;

    return 0;
}

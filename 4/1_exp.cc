#include <iostream>

int main() {
    int x = (1 + 2) + 3;
    // int x = operator +(operator +(1,2), 3)
    int y = 1 + (2 * 3);
    int a, b;
    a = (b = 0);

    if(5 == a)
        std::cout<<"Ot"<<std::endl;

    // 5: int
    // 'a': char
    // "a": const char *
    // 349885794858724298579842476l: long
    // .0
    // 1e0
    // 6e23

    int hex = 0xf00d;
    int okt = 0123;

    std::cout<<hex<<" "<<okt<<std::endl;
    std::cout<<std::hex<<hex<<" "<<okt<<std::endl;

    std::cout<< (1 << 3) << std::endl;
    std::cout<< (1 & 3) << " " << (2 | 1) << std::endl; // bin
    std::cout<< (3 && 1) << " " << ((1 || 3)?"true":"false") << std::endl; // log

    0 && (std::cout<<"Hello world"<<std::endl);
    // Vigyazz Java!:
    // if(obj != null && obj.getName().equals("sdf"))

    char c;
    std::cin>>std::noskipws;
    while(std::cin>>c) {
        std::cout<<c;
    }

}

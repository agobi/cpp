#include <iostream>
#include <vector>

// linker + linker
// halmaz
// rendezes
int main()
{
//    int a[] = {1,2,3,6,7};
    std::vector<int> a;
    a.push_back(2);
    a.push_back(5);
    a.push_back(5);
    a.push_back(9);

    // ssize_t == long
    // size_t == unsigned long
    size_t i=0;
    for(;i<a.size() && a[i]!=6;++i);


    /*{
        int i=0;
        while(i<a.size()-1)
        {
            ...
            ++i;
        }
    }*/

    typedef unsigned long meret;
    // Nem szep: indexet hasznalunk!
    for(meret i=0; i<a.size()-1; ++i)
        for(size_t j=i+1; j<a.size(); ++j)
            if(a[i] == a[j])
                std::cout<<"Megvan: a["<<i<<"] = a["<<j<<"] = "<<a[i]<<std::endl;

}

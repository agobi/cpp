#include <unordered_map>
#include <string>
#include <iostream>

int main()
{
    typedef std::unordered_map<std::string, int> mymap;
    mymap m;

    m["egy"] = 1;
    //m["ketto"] = 2;
    m.insert(std::pair<std::string, int>("ketto", 2));
    //m["ot"] = 5;
    m.insert(std::make_pair("ot", 5));

    std::string s;
    while(std::cin>>s)
    {
        // std::cout<<m[s]<<std::endl; nem jo
        mymap::iterator it = m.find(s);
        // (*it).second == it->second
        // *(it.second) == *it.second
        if(it == m.end())
            std::cout<<"NOT FOUND"<<std::endl;
        else
            std::cout<<it->second<<std::endl;
    }
}

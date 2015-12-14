#include <iostream>
#include <unordered_map>
#include <string>

int main()
{
    typedef std::unordered_map<std::string, int> maptype;
    maptype m;
    m["egy"] = 1;
    m["ketto"] = 2;
    m.insert(std::pair<std::string,int>("harom", 3));
    m.insert(std::make_pair("negy", 4));

    std::string s;
    while(std::cin >> s)
    {
    //    std::cout<<m[s]<<std::endl;
        maptype::iterator it = m.find(s);
        if(it != m.end())
        {
            //std::cout<< (*it).second << std::endl;
            std::cout<< it->second << std::endl;
        }
    }

    std::cout<<m.size()<<std::endl;
}

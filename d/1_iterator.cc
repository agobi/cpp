int main()
{
    std::list<int> x = {1,4,6,2,3,4};

    for(std::list<int>::iterator i = x.begin(); i != x.end();)
    {
        if(*i % 2 != 0)
            i = x.erase(i);
        else
            ++i;
    }
}

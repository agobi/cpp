class wstat
{
    int i;
    static int s;
}

int &f()
{
    static int value;
    return value;
}

int main()
{
    static int a;
    wstat w;
    w.i;
    wstat::s;

    f() = 42;
    std::cout<<f()<<std::endl;

}

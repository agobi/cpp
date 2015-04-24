// Meg lehet mondani, hogy egy osztalyban a mezok
// melyik konstruktorral jojjenek letre: inicializator
struct s
{
    int &q;

    s(int &i)
        : q(i) // mezok konstruktorait hivom meg
    {
        q = 42;
    }
};

int main()
{
    int i;
    s o(i);
}

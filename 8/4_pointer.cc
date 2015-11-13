struct rational { int d,n; };

int main()
{
    int i = 6;
    int &ir = i;

    int *np = 0;
    int *np2 = nullptr;
    //int *ip = NULL;

    np = &i;
    *np == i;

    rational r1;
    rational *p = &r1;

    r1.n ==  (*p).n == p->n
};

int main()
{
    int i;
    int *pi= &i;
    *pi = 42;

    const int ci = 42;
    // pi = &ci; // type error
    const int * pci = &ci;
    // *pci = 137; // const assignment
    pci = &i;

    int * const cpi = &i;
    // pi = &i; // const assignment
    *cpi = 137;
}

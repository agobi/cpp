int main()
{
    int x[][2] = { {1,2}, {3,4}, {5,6} };
    int *p[] = { x[0], x[1], x[2] };

    int c = 0;
    int **m = new int *[3];
    for(int i=0; i<3; ++i)
    {
        m[i] = new int[2];
        m[i][0] = ++c;
        m[i][1] = ++c;
    }

    // delete m; <- nem jo
    for(int i=0; i<3; ++i)
        delete[] m[i];
    delete[] m;
}

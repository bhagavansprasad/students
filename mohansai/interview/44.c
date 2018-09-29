int *ch( int,  int);
int main()
{
    int *c;
    c = ch(10,15);
    printf("%d\n", *c);
    return 0;
}
int *ch( int i,  int j)
{
    int *a, *b;
    a=&i;
    b=&j;
    *b = *a + j;
    if(i>=20)
    return a;
    else
    return b;
}

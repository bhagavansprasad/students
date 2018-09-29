int main()
{
    union v
    {
         int a,b;
    };
    union v u;
    u.a = 10;
    u.b = 20;
    printf("%d\n", u.a);
    return 0;
}



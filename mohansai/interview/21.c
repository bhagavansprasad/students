int call(int i)
{
    int j = 1;
    if( i == 0 || i == 1)
    {
        j = 1;
    }
    else
    {
       j = j* call(i-1);
    }
    return j;
}
int main()
{
     int i = 5, j = 0;
     while( i > 0)
     {
         j = call(i);
         i--;
     }
     printf("%d\n", j);
     return 0;
}



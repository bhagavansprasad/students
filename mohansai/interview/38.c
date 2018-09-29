int main()
{
    void fun();
    int i = 1;
    while(i <= 3 )
    {
       printf("%d\n", i);
       if(i >2)
       {
             goto here;
       }
    }
    return 0;
}
void fun()
{
    here:
    printf("Hello\n");
}


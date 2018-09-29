#include<stdio.h>
#include<stdlib.h>
main()
{
    int a=10;
    char c=20,b,d;
    f1(a,b);
    f2(c,d);
}

int f1(int a,int b)
{
    b=&a;
    printf("addres---->%u\n",b);
}
int f2(int c,int d)
{
    d=&c;
    printf("pointe vall--->%u\n",d);
}

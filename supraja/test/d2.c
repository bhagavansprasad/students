#include<stdio.h>
int main()
{
union
{
int a;
char b;
}cc;
cc.b=60;
printf("%d\n",sizeof(cc));
}


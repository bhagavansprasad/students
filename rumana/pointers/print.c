#include<stdio.h>
main()
{
int a=300,b,i;
int *p;
p=&a;
b=p;
for(i=p;i<b+4;i++)
printf("%d",p[i]);
}


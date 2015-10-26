#include<stdio.h>
main()
{
int a=300,i;
char *p;
p=&a;
for(i=0;i<4;i++)
{
printf("%d\n",*p);
p=p+1;
}
}

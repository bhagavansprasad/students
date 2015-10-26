#include<stdio.h>
main()
{
int a,b=1,c;
int n=6,i;
a=(-1);
for(i=1;i<=n;i++)
{
c=a+b;
a=b;
b=c;

printf("%d/n",c);
}
}

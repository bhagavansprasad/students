#include<stdio.h>
int f=1,a=1;
main()
{

int i,r,n=6;

for(i=1;i<=n;i++)
r=fact(i);
}

fact(int l)
{
f=f*a;
printf("factorial values are %d\n",f);
a++;
return f;
}


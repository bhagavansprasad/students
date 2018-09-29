#include<stdio.h>
int f=1,a=1;
main()
{

int i,sum=0,n=6;

for(i=1;i<=n;i++)
sum=sum+fact(i);
printf("sum of factorial values =%d",sum);
}

fact(int l)
{
f=f*a;
printf("factorial values are %d\n",f);
a++;
return f;
}



/* 1!/2!+2!/3!..............+n!/(n+1)! */

#include<stdio.h>
int f=1,a=1,f1=1;
main()
{

int i,sum=0,n=6;

for(i=1;i<=n;i++)
sum=sum +fact(i);
printf("sum of fact values =%d\n",sum);
}

fact(int l)

{
int d;
f=f*a;
f1=f1*(a+1);
d= f/f1;
printf("factorial divison values are %d\n",d);
a++;
return d;
}


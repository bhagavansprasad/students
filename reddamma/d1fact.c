#include<stdio.h>
int factorial=1;
main()
{
int i,x=1,y=1,s=0,n=3;
for(i=0;i<=n;i++)
{
s=s+get_factorial(i+x)/get_factorial(i+y);
printf("%d\n",s);
}
}
int get_factorial(int n)
{
int j,fact=1;
for(j=1;j<=n;j++)
{
fact=fact*j;
}
return fact;
}

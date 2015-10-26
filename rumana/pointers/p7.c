#include<stdio.h>
int swapv(int,int);
main()
{
int a=10,b=20;
swapv(a,b);
printf("%d\n",a);
printf("%d\n",b);
}
int swapv(int x,int y)
{
int t;
t=x;
x=y;
y=t;
printf("%d\n",x);
printf("%d\n",y);
}

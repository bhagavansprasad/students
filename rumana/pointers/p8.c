#include<stdio.h>
void swapr(int *,int *);
main()
{
int a=10,b=20;
swapr(&a,&b);
printf("%d\n",a);
printf("%d\n",b);
}
void swapr(int *x,int *y)
{
int t;
t=*x;
*x=*y;
*y=t;
printf("%d\n",*x);
printf("%d\n",*y);
}

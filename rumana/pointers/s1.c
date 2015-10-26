#include<stdio.h>
void fun(int,int *);
main()
{
int i=-5,j=-2;
fun(i,&j);
printf("%d\n",i);
printf("%d\n",j);
}
void fun(int a,int *b)
{
a=a*a;
*b=*b**b;
printf("%d\n",a);
printf("%d\n",*b);
}

#include<stdio.h>
int *fun();
main()
{
int *p;
p=fun();
printf("%u\n",p);
printf("%d\n",*p);
}
int *fun()
{
static int i=20;
return(&i);
}

#include<stdio.h>
int *check(int,int);
main()
{
int *c;
c=check(10,20);
printf("%u\n",c);
printf("%d\n",*c);
}
int *check(int i,int j)
{
static int *p,*q;
p=&i;
q=&j;
printf("%d\n",*p);
printf("%d\n",*q);
if(i>45)
return(p);
else
return(q);
}

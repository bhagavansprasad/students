#include<stdio.h>
main()
{
int  i,a=300;
char *p=(char *)&a;
for(i=0;i<=3;i++,p++)
printf("%d\t",*p);
}

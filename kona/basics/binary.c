#include<stdio.h>
main()
{
int a=300,i;
char *pch;
pch=(char*)&a;
for(i=0;i<=3;i++,pch++)
{
printf("%d\t",*pch);
}
}

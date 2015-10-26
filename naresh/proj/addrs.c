#include<stdio.h>
main()
{
int a=400,n=4,i;
unsigned char *pch;
pch=&a;
for(i=1;i<=n;i++,pch++)
{
printf("%d\n",*pch);
}
}

#include "stdio.h"
main()
{
int a=0x12131415,i=0,n=4;
char *p;
p=(char *)&a;
p=p+0;
*p=0;
p=p+3;
for(i=0;i<n;i++)
{
printf("%x\n",*p);
p--;
}
}

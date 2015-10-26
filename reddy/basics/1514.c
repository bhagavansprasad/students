#include "stdio.h"
main()
{
int a=0x12131415,i=0,n=5;
char *p;
p=(char *)&a;
*p=0;
for(i=0;i<n;i++)
{
printf("%x\n",*p);
p++;
}
}

#include "stdio.h"
main()
{
int a=0x12131415,i,n=5;
char *pch=(char *)&a;
pch=pch+3;
*pch=0;
pch=pch-3;
for(i=1;i<n;i++)
{
printf("%x",*pch);
pch++;
}
}

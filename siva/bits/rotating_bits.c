#include<stdio.h>
main()
{
unsigned int i=0x96857458,b,l,r,k,m,n,f;
printf("i value %x\n",i);
l=i<<24;
r=i>>24;
b=l|r;
printf("%x\n",b);
k=(i>>16)<<24>>16;
m=(i<<16)>>24<<16;
n=k|m;
f=b|n;
printf("%x",f);
}

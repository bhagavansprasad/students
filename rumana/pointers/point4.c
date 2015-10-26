#include<stdio.h>
main()
{
int a=0x12131415,i;
short int *p;
p=&a;
for(i=0;i<=1;i++,p++)
printf("%x\n",*p);
}



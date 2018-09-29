#include<stdio.h>
main()
{
int a=0x12131415,i,c[10];
char *p;
p=&a;
for(i=0;i<=3;i++,p++)
{
c[i]=*p;
printf("%x\n",c[i]);
}
}


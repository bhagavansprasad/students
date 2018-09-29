#include<stdio.h>
main()
{
int i;
int a=0x12131415;
char *pa=&a;
short *sp=&a;
pa=pa+3;
for(i=0;i<=3;i++)
{
printf("%x\t",*pa);
pa--;
}
printf("%x\t",*sp);
sp++;
printf("%x\t",*sp);
}

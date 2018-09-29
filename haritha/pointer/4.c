#include<stdio.h>
main()
{
int a=0x12131415,i;
char *cp=(char *)&a;
for(i=0;i<=3;i++)
{
printf("%x",*((char *)&a+i));
}
}

#include<stdio.h>
main()
{
int a = 0x12131415,i;
char *p;
*((short int*)&a+1) = 0;
for( i =0; i<4;i++)
{
  p = (char*)&a+i;
printf("%x\t",*p);
}
printf("%x\n",a);
}



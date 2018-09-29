#include<stdio.h>
main()
{
int a=0x12131415;
short *sp=(short *)&a;
sp++;
printf("%x",*sp);
sp--;
printf("%x",*sp);
}

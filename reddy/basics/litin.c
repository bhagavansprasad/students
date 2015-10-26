#include "stdio.h"
main()
{
int a=0x15141312;
char *p=(char *)&a;
if(*p==0x15)
{
printf("l.e\n");
}
else
{
printf("b.i\n");
}
}

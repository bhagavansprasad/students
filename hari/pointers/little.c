#include <stdio.h>
main()
{
int a=300;
char *x=(char *)&a;
if(x[0]==0)
printf("little endian");
else
printf("big endian");
}


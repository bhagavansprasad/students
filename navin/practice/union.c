#include <stdio.h>
#include <string.h>
main()
{
typedef union
{
char b[10];

int a;
float c;
}Union;

Union x,y={65};

x.a=50;
x.c=1.5;
strcpy(x.b,"hello");
printf(" union x: %d\t   %s\t    %f  \n",x.a,x.b,x.c);
printf(" union y: %d\t    %s\t    %f \n",y.a,y.b,y.c);
}

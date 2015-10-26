#include <stdio.h>
#include <string.h>
main()
{
typedef union
{
//char b[10];
float c;
int a;
//float c;
}Union;

Union x={65},y;

y.a=50;
//y.c=1.5;
//strcpy(y.b,"hello");
printf(" union x: %d\t       %f  \n",x.a,x.c);
printf(" union y: %d\t    %f\t     ",y.a,y.c);
}

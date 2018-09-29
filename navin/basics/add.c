#include <stdio.h>
main()
{

int a=521;
int b,c,d,e;
c=a%10;
a=a/10;
b=a/10;
d=a%10;
e=d+b+c;

printf("Out as  %d + %d + %d = %d",c,b,d,e);
}



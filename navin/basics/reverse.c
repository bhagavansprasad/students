#include <stdio.h>
main()
{

int a=521;
int b,c=0,d,e,f;

b=a/10;f=b/10;
d=b%10;
c=((c*10)+(a%10));
e=((c*100)+(d*10)+f);

printf(" %d",e);
}



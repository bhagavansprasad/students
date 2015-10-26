#include <stdio.h>
main()
{
 int a =10;
 int *b,**c,***d,****e;
 b = &a;
 c = &b;
 d = &c;
 e = &d;
 printf("\n%d %d %d %d %d  ",a,*b,**c,***d,****e);
}

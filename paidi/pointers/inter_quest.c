#include <stdio.h>
main()
{
 int a = 10;
 char *p,r,q;
 p=&a;
 r=&p;
 p++;
 q=&r;
 q++;
 printf("%d , %d , %d\n",p,q,r);
 
}

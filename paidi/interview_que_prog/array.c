#include <stdio.h>
main()
{
 int a[]={10,20,30,40};
 char *p;
 p=(char *) a;
 printf("%u\n",p);
 printf("%u\n",p+1);
 printf("%u\n",p+2);
 printf("%d\n",*((int*)p+2));
 printf("%u\n",*p);
 printf("%d\n",*p);
}

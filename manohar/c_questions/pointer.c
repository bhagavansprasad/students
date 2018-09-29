#include <stdio.h>
main()
{
int a=10;
int *p=&a;
printf("a value:%d\na address:%u\n",a,&a);
printf("p value:%d\np address:%u\n",*p,&p);
printf("p after address:%u\np after value:%u\n",*p++,++(*p));

}

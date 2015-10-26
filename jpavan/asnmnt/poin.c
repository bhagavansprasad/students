#include<stdio.h>
main()
{
int a=10;
int *p;
p=&a;
int **pp;
pp=&p;
printf("%d\n",a);
printf("%p\n",&a);
printf("%d\n",*p);
printf("%p\n",&p);

printf("%d\n",*&a);
printf("%p\n",*&p);
printf("%d\n",**&p);
printf("%p\n",pp);
printf("%p\n",*pp);
printf("%d\n",**pp);


}

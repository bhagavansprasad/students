#include<stdio.h>
#include<stdlib.h>
main()
{
char *p;
p=malloc(10);
printf("%p\n",p);
free(p);
free(p);
return 0;
}

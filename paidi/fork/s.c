
#include <stdio.h>
#include<stdlib.h>
/*main()
{
int *p;
p=malloc(100);
printf("--1> %u\n",p);
printf("--2> %u\n",*(p-1));
free(p);
printf("--3> %u \n",p);
printf("--4> %u\n",*(p-1));
//*(p-1)=0;
printf("--5> %u\n",*(p-1));
free(p-1);
//free(p);
}*/


char *amalloc();
main()
{
 char *p=amalloc();
 printf("%s\n",p);
}

char *amalloc()
{

char *a="paidi,prem";

return a;
}

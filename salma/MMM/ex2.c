#include<stdio.h>
#include<stdlib.h>
main()
{
int i;
char *p=malloc(10);
printf("%p\n",p);
*p=0;
printf("%d\n",*p);
/*for(i=1;i<5;i++)
{
*(p-i)=0;
printf("%d\n",*(p-i));
}*/
return 0;
}

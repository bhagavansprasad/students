#include<stdio.h>
main()
{
int i=54;
float a=3.14;
char *ii,*aa;
ii=(char *)&i;
aa=(char *)&a;
printf("addres i is %u\n",ii);
printf("address a is %u\n",aa);
printf("value of i is %d\n",*ii);
printf("value of a is %d\n",*aa);
}

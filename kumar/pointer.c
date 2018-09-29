#include<stdio.h>
main()
{
int s=30;
int *ip;
ip=&s;
printf("address of variable %u\n",&s);
printf("address stored variable %d\n",ip);
printf("value of s variable %d\n",*ip);
}

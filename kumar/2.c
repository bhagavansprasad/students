#include<stdio.h>
int main()
{
int a=30;
int *ip;
&a=ip;
printf("address of vaiable %d\n",&a);
printf("address stored variable %d\n",ip);
printf("value of the variable %d\n",*ip);
}

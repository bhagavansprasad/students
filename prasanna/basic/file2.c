#include<stdio.h>
int func()
{
	extern int i;
	i=40;
	printf("I---->%d\naddress-------> %u\n",i,&i);
}

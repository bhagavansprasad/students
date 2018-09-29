#include<stdio.h>
#include"def.h"
void fun();
main()
{
	int i;
	for(i=1;i<MAX;i++)
	{
		printf("%d",i);
	}
	printf("\n");
	fun();
}

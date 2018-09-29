#include<stdio.h>
main()
{
	int a=10,b=20,c=0,i;
	c=a^b;
	for(i=0;c;i++)
		c=c&c-1;
	printf("%d",i);
}



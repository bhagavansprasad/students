#include<stdio.h>
main()
{
	int a=300,i,*p;
	char *pch;
	p=(char*)&a;
	*pch=&a;
	for(i=0;i<4;i++)
	printf("%d",*pch+i);
}

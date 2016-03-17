#include<stdio.h>
main()
{
	int a=300,i,n=3;
	char *p=&a;
	for(i=0;i<=n;i++)
	{
		printf("%d\n",*(p+i));
		
	}
}


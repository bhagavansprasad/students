#include<stdio.h>
main()
{
	int a=500,i;
	unsigned char *p;
	p=&a;
	for(i=3;i>=0;i--)
	{
		printf("%d\n",p);
		printf("%d\n",*(p+i));
	}
}

#include<stdio.h>
main()
{
	int a=100,b=25,c=54;
	if(a>b)
	{
		if(a>c)
		{
			printf("a is the big no and it is=%d\n",a);
		}
	}
	else if(b>c)
	{
		if(b>a)
		{
			printf("b is the big no and it is=%d\n",b);
		}
	}
	else if(c>a)
	{
		if(c>b)
		{
			printf("c is the big no and it is=%d\n",c);
		}
	}
}

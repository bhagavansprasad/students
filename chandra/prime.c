#include<stdio.h>
main()
{
	int i,num=5;
	for(i=2;i<=(num-1);i++)
	{
		if(num%i==0)
		{
			printf("not prime");
		}
	}
	if(i==num)
	{
		printf("prime");
	}
}

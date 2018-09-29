#include<stdio.h>

main()
{
	char h = 'm';
	char g = 'f';
	int yos = 23, qual = 1;
	if (h == 'm' && yos>=10 && qual == 1)
	{
		printf("salary is 15000\n");
	}
	else if (h == 'm' && yos>=10 && qual ==0)
	{
		printf("salary is 10000");
	}
	else if (h == 'm' && yos<10 && qual == 1)
	{
		printf("salary is 10000");
	}
	else if (h == 'm' && yos<10 && qual == 0)
	{
		printf("salary is 7000");
	}
	if (g =='f' && yos>=10 && qual == 1)
	{
		printf("salary is 12000\n");
	}
	else if (g == 'f' && yos>=10 && qual == 0)
	{
		printf("salary is 9000");
	}
	else if (g == 'f' && yos<10 && qual == 1)
	{
		printf("salary is 10000");
	}
	else if(g == 'f' && yos<10 && qual == 0)
	{
		printf("salary is 6000");
	}
}

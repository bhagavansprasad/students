#include<stdio.h>
main()
{
	int m1 = 56,m2=60,m3=35,m4=43,m5=49, percentage = 0;
	percentage=(m1+m2+m3+m4+m5)/5;
	if(percentage>=60)
	{
		printf("first division");
	}
	else if(percentage>=50)
	{
		printf("second division");
	}
	else if(percentage>=40)
	{
		printf("third division");
	}
	else 
	{
		printf("fail");
	}
}

























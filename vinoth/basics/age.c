#include<stdio.h>
main()
{
	char sex,ms;
	char m = "married";
	char M = "sex";
	int age;
	printf("age,sex,marrital ststus");
	if(ms=='m')
	{
		printf("driver is insured");
		}
		else
		{
			if(sex == 'M')
			{
				if(age>30)
					printf("driver is insured");
				else
					printf("driver is noy insured");
			}
		}
		else
			if(age>25)
				printf("driver is insured");
			else
				printf("driver is not insured");
	}

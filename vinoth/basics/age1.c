#include<stdio.h>
main()
{
	char sex = 'm', ms = 'm';
	int age = 25 ;
	if(ms=='m')
	{
		printf("driver is insured");
	}
	else
	{
		if(sex=='m')
		{
			if(age>30)
			{
"driver is insured");
			}
			else
			{
				printf("driver is not insured");
			}
		}
		else
		{
			if(age>25)
			{
				printf("driver is insured");
			}
			else
			{
				printf("driver is not insured");
			}
		}
	}
}

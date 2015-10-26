#include <stdio.h>
main()
{
	int s1=25,s2=55,s3=60,flag=0;
	if(s1>=35)
	{
		if(s2>=35)
		{
			if(s3>=35)
			{
				flag=1;
			}
		}
	}
	if(flag==0)
	{
		printf("NP\n");
	}
	else
		printf("P\n");
}

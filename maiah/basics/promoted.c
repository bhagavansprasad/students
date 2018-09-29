#include<stdio.h>
main()
{
	int s1=55,s2=46,s3=65,t=0;
	if(s1>=35)
	{
		if(s2>=35)
		{
			if(s3>=35)
			{
				t=1;
			}
		}
	}
	if(t==1)
	{
		printf("promoted");
	}
	else
	{
		printf("not promoted");
	}
}

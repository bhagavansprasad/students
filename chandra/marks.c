#include<stdio.h>
main()
{
	int s1,s2,s3,t;
	printf("enter s1,s2,s3");
	scanf("%d%d%d",&s1,&s2,&s3);
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

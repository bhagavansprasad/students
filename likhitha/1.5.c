#include<stdio.h>
int main()
{
	int s1=30,s2=50,s3=60;
	if(s1>=35)
	{
		if(s2>=35)
		{
			if(s3>=35)
			{
				printf("promoted\n");
			}
		}
	}
	else
		printf("not promoted\n");
}


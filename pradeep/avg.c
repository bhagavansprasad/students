#include <stdio.h>
int main()
{
	int s1=35,s2=35,s3=05,m=0;
	if(s1>=35)
	{
		if(s2>=35)
		{
			if(s3>=35)
			{
				m=1;
			}
		}
	}
	if(m==1)
		printf("promoted");
		else
			printf("not promoted");
}

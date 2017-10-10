#include <stdio.h>

void main()
{
	int s1 = 44, s2 = 42, s3 = 77;
	if(s1>=35)
	{
		if(s2>=35)
		{
			if(s3>=35)
			{
				printf("promoted");
			}
			else
				printf(" not promoted");
		}
		else
			printf("not promoted");
	}
	else
		printf("not promoted");
}

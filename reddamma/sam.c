#include<stdio.h>

union student
{
char s1[100];
int k;
};
main()
{
	union student s;
	{
		int i;
		s.k=300;
		for(i=0;i<4;i++)
		{
			printf("%d",s.s1[i]);
		}
	}
}



#include<stdio.h>

int main()
{
	int i,j,t=1;
	for(i=0;i<4;i++)
	{
		for(j=0;j<4-i;j++)
			printf(" ");

		for(j=0;j<=i;j++)
		{
			printf("%d ",t);
			t++;
		}
		printf("\n");
	
	}
	return 0;
}

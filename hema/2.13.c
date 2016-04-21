#include<stdio.h>
void main()
{
	int i,j;
	for(i=1;i<=5;i++)
	{
		printf("%d",i);
		for(j=1;j<=5;j++)
		{
			printf("%d",j);
		}
	}
	printf("i:%d,j:%d\r\n",i,j);
}

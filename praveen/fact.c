#include <stdio.h>
/*
main()
{
	int fd;
	fd=fact(5,6,7);
	printf("%d\n",fd);
}
*/
int fact(int x,int y,int z)
{
	int i,fact=1;
	int j;
	int sum=0;
	int n[]={x,y,z};
	for(j=0;j<3;j++)
	{
		for(i=1;i<=n[j];i++)
		{
			fact = fact*i;
			printf("%d\n",fact);
		}
		sum = sum+fact;
		printf("%d\n",sum);
		fact=1;
	}
	return sum;
}

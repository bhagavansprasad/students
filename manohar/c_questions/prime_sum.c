#include <stdio.h>
int main()
{
	int n= 10,c=1,count=1,k=0,i=1,j=2;
	for(i=1;c<=n;i++)
	{
		for(j=2;j<i;j++)
		{
			if(i%j==0)
			{
				count++;
				break;
			}
		}
		if(count==1)
		{
			k=k+i;
			c++;
			printf("i value %d------->k value %d\n",i,k);
		}
	}
	printf("sum of first %d numbers %d",n,k);

	return 0;
}

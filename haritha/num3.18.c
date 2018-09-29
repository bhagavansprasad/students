#include<stdio.h>
#include<stdlib.h>
main()
{
	int i,j,c=2,m=3,k,n=5;
	for(i=1;i<=n;i++)
	{
		if(i<=2)
		{
			for(k=65;k<=65+c;k++)
			{
				printf("%c",k);
			}
			for(j=m;j<=i;j++)
			{
				printf(" ");
			}
			for(k=66;k>=65;k--)
			{
				printf("%c",k);
			}
			c--;
			m--;
			printf("\n");
		}
	}


	m=m-2;
	c = 0;

	for(i=1;i<=n;i++)
	{
		if(i<=1)
		{
			for(k=65;k<=65+c;k++)
			{
				printf("%c",k);
			}
			for(j=m;j<=i;j++)
			{
				printf(" ");
			}
			for(k=65;k<=65+c;k++)
			{
				printf("%c",k);
			}
			m++;
			printf("\n");
		}
	}

	c++;
	//printf("c %d\n", c);
	//printf("m %d\n", m);

	for(i=1;i<=2;i++)
	{
		for(k=65;k<=65+c;k++)
		{
			printf("%c",k);
		}
		for(j=m;j<i;j++)
		{
			printf(" ");
		}
		for(k=66;k>=65;k--)
		{
			printf("%c",k);
		}
		c++;
		m=m+2;
		printf("\n");
	}
}


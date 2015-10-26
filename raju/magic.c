#include<stdio.h>
main()
{
	int a[5][5];
	int i=0,j=0,k=1;

	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			a[i][j]=0;	
		}
	}
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	}

	i=0;
	j=2;
	k=1;
	printf("%d. %3d:%3d\n", k, i, j);
	a[i][j]=k;

	do
	{
		k=k+1;
		i=i-1;
		j=j+1;

		if(i<0  || j>4)
		{
			if(i<0  &&  j<=4)
			{
				i=4;
			}
			if(i>=0  && j>4)
			{
				j=0;
			}
			if(i<0  &&  j>4)
			{
				i=i+2;
				j=4;
			}
		}

		if(a[i][j]!=0)
		{
			i=i+2;
			j=j-1;
			printf("%d. %3d:%3d\n", k, i, j);
			a[i][j]=k;
		}
		//printf("a:%d\n",a[i][j]);

		if(a[i][j]==0)
		{
			printf("%d. %3d:%3d\n", k, i, j);
			a[i][j]=k;
		}
	}while(k<25);

#if 1
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	}
#endif
}	



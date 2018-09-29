#include<stdio.h>
main()
{
	int m,n, count=0;
	for(m=1;n<50;m++)
	{
		count =0;
		printf("%d\n",m);
		for(n=2;n<m;n++)
		{
			if(m%n==0)
			{
				count++;
				break;
			}
		}
		if (count==0)
			printf("prime number\n");
		else
			printf("not prime number\n");
	}
}




/*
#include<stdio.h>
main()
{
	int i,n=10,count=0;
	for(i=2;i<n;i++)
	{
		if(n%i==0)
		{
			count++;
			printf("count--=%d\n",count);
		}
	}
	if (count==0)
	{
		printf("prime number--i%d\n",i);
	}
	else
		printf("Not prime number--i%d\n",i);
}
*/

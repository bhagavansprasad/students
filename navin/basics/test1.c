#include<stdio.h>
main()
{
	int k=0,j=0,n=4;
	for(j=0;j<=n;j++)
	{
		k+=(fact(j)/fact(j+1));
	}

	printf("%d",k);

	return 0;
}


int fact(int i)
{
	int a, i = 1;

	for(a = 0; i <= i; i++)
		i*=a;

	return(i);
}	


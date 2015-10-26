#include<stdio.h>
long fact (int num)
{
	long f=1;
	int i=1;
	while(i<=num)
	{
		f=f*i;
		i++;
	}
	return(f);
}
main()
{
	long int line;
	int i,j;
	printf("enter no of lines");
	scanf("%3ld",&line);
	for(i=0;i<line;i++)
	{
		for(j=0;j<line-i-1;j++)
		printf(" ");
		for(j=0;j<=i;j++)
		printf("%3ld",fact(i)/((fact(j))*(fact(i-j))));
		printf("\n"); 
	}
	return(0);
}


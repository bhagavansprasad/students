#include<stdio.h>
main()
{
	int a,b,c,i,sum=0,n;
	printf("Enter a number");
	scanf("%d",&n);
	a=0;
	b=1;
	printf("%d %d",a,b);
	c=a+b;
	sum=sum+c;
	printf(" %d",c);
	for(i=1;i<= n-3;i++)
	{
	  a=b;
	  b=c;
	  c=a+b;
	  printf(" %d",c);
	  sum=sum+c;
	 }
	 printf(" %d",sum);
}	 

	

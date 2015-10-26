#include<stdio.h>
main()
{
	int f=0,i,n;
	printf("Enter a number\n");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
	  f=fact(i);
	  printf(" %d",f);
	}
}
int fact(int x)
{
	int f=x,i;
	for(i=x-1;i>0;i--)
	{
	  f=f*i;
	}
	return f;
}	

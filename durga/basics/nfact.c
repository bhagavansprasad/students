#include<stdio.h>
main()
{
	int n=5,t=0,i;
	for(i=1;i<=n;i++)
	{
		t=get_fact(i);
		printf("%d\t",t);
	}
}
int get_fact(int n)
{
	int f=1,j;
	for(j=1;j<=n;j++)
	{
		f=f*j;
	}
	return(f);
}

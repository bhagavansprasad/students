# include<stdio.h>
#include<fcntl.h>
int fact(int );
main ()
{
	int n = 5,t,i,sum = 0;
	for (i = 1;i <= n;i++)
	{
		t = fact(i);
	}
	printf("%d",t);
}

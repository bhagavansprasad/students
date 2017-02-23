#include<stdio.h>
main()
{
	int n=5,m=10,p=15,x;
	x=fact(p);
}
int fact(int num)
{
	int f=1,i;
	for(i=1;i<=num;i++)
		{
		f=f*i;
		}
	printf("factorial of given=%d\n",f);
}



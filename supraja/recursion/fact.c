#include<stdio.h>
int main()
{
	int a=5;
	int t;
	t=fact(5);
	printf("--------->t:%d\n",t);
}
int fact(int n)
{
	int f;
	if(n==1)
	{
		return 1;
	}
	else
	{
		f=n*fact(n-1);
	}
	return f;
}

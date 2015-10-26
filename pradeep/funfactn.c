#include <stdio.h>
int main()
{
	int n=6;
	for(i=1;i<=n;i++)
	{
		f=fact(i);
		printf("%d\n",f);
	}
}
int fact(int num)
{
	int i=1,f=1;
	for(i=1;i<=num;i++)
	{
		f=f*i;
	}
	return f;
}

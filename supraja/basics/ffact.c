#include <stdio.h>
int main()
{
	int n=5,t=0;
	t=get_factorial(n);
	printf("%d\n",t);
}
int get_factorial (int n)
{
	int f=1,i;
	for(i=1;i<=n;i++)
		f=f*i;
	return (f);
}

#include"stdio.h"
int main()
{
	int n=5,t=0,i;
	for(i=1;i<=n;i++)
	{
		t=get_factorial(i);
		printf("%d\n",t);
	}
}
int get_factorial(int n)
{
	int f=1,j;
	for(j=1;j<=n;j++)
		f=f*j;
	return(f);
}


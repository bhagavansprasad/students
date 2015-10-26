#include"stdio.h"
#if 0
int main()
{
	int n=5,t=0,s=0,m,i,t1;
	for(i=1;i<=n;i++)
	{
		t = get_factorial(i);
		printf("%d\n",t);

		t1 = get_factorial(i+1);
		printf("%d\n",t1);

		m=t1/t;
		printf("%d\n",m);

		s=s+m;

		printf("sum of that is :%d\n",s);
	}
}
#endif

int main()
{
	int n = 5, t = 0;

	for(i = 1; i <= n; i++)
		t = t + get_factorial(i+1)/get_factorial(i);

	printf("sum of that is :%d\n",s);
}

int get_factorial(int n)
{
	int f=1,j;
	for(j=1;j<=n;j++)
		f=f*j;
	return(f);
}


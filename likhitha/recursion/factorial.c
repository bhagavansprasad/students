#include<stdio.h>

int main()
{
	int n=7 , t;

	t=fact(n);
	printf("%d\n",t);
}

int fact(int m)
{
	if( m == 0)
		return 1;

	else if(m==1)
		return m;

	return(m * fact(m-1));
}

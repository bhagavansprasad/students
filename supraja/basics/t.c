#include<stdio.h>
main()
{
	int n = 5, t = 0;

	t = get_factorial_value(n);	

	printf("facorial value of %d is :%d\n", n, t);
}

int get_factorial_value(int num)
{
	int f=1, i=0;

	for(i=1;i<=num;i++)
		f=f*i;

	return(f);
}

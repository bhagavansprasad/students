# include <stdio.h>
# include <fcntl.h>
main ()
{
	int n = 5,t,i,sum = 0;
	for (i = 1; i <= n; i++)
	{
		t=fact(i);
		sum = sum+t;
	}
	printf("%d\n",sum);
}
int fact (int num)
{
	int i ,f = 1;
	for (i = 1; i <= num; i++)
	{
		f = f*i;
	}
	return (f);
}

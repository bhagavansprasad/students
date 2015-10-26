# include <stdio.h>
# include <fcntl.h>
main ()
{
	int n=11;
	int t;
	t = prime(n);
	if (t == 0)
	printf("prime number\n");
	else 	
	printf("not prime number\n");
}
int prime (int n)
{
	int i,flag=0;
	for (i = 2 ;i < n; i++)
	{
		if ( n%i == 0)
		{
			flag = 1;
			break;
		}
	}
	if (flag == 1)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}



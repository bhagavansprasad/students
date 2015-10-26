# include <stdio.h>
main ()
{
	int n=13 , i , flag = 0;
	for (i = 2; i <= n-1 ; i++)
	{
		if (n%i == 0)
		{
			flag = 1;
			break;	
		}
	}
	if (flag == 0)
		printf("%d is a prime number",n);
	else
		printf("%d is not a prime number",n);
}

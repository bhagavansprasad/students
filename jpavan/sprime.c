#include<stdio.h>

main()
{
	int j, c = 1, n = 9, t;

	for(j = 2; c <= n; j++)
	{
		t = prime(j);

		if(t == 1 )
		{
			printf("%d\n", j);
			c++;
		}
	}
}

//NOT PRIME - 0
//PRIME - 1
int prime(int n)
{
	int i, p, flag = 0;

	for(i = 2; i < n; i++)
	{
		if (n%i == 0)
		{
			flag = 1;
			break;
		}
	}	

	if(flag == 1)
		return 0;
	else 
		return 1;

}

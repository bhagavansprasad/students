#include<stdio.h>
int main()
{
	int n = 7, i, flag=1, c = 0, pcount = 0, psum = 0;


	for(c = 2; pcount <= n; c++)
	{
#if 0
		for(i = 2; i < c; i++)
		{
			if (c % i == 0)
			{
				flag = 0;
				break;
			}
		}
#endif
		flag = is_prime(c);
		if(flag == 1)
		{
			pcount++;
			psum = psum + c;
		}
	}

	printf("psum :%d\n", psum);
}




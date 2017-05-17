#include<stdio.h>
int main()
{
	int n=10, i, count=1, t;

	for(i=2; count <= n; i++)
	{
		t = is_prime(i);

		if(t==1)
			printf("%d\n",i);
		count++;
	}
}



#include <stdio.h>
main()
{
	int n=10;
	fun(n);
}
int fun(int n)
{
	static int i=1;
	if(	i == n)
	{
		printf("number :%d\n",n);
		return ;
	}
	else
	{
		printf("number :%d\n",i);
		i++;
		fun(i);
	}
}

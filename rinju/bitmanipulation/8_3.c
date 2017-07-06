#include<stdio.h>
int is_power_of_two(int a)
{
	if(a==0)
		return 0;
	while(a!=1)
	{
		if(a%2!=0)
			return 0;
		a=a/2;
	}
	return 1;
}
main()
{
	int n=7,ret;
	ret=is_power_of_two(n);
	if(ret==0)
		printf("no");
	else
		printf("yes");
}


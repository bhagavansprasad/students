#include <stdio.h>
int bit_on_off(int a,int p)
{

	if(a & (1<<(p-1)) == 0)
	return 0;
	else
	return 1;
}
main()
{
	int a=10,p=4,m;
	m=bit_on_off(a,p);
	printf("%d\n", m);
}

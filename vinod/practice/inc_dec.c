#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int main()
{
	int i=0,j=-1,k=1,r=0, a;
	unsigned int b = 0;
	int x=10,y=5,max=0;
	r = ++i | j++ & --k;
	printf("i-> %d, j-> %d, k-> %d, r-> %d\n", i, j ,k ,r);
	a = 4000000000;
	b = 4000000000 ;
	printf("a %d, b %u\n", a,b);
	printf("a %d, b %u\n", INT_MAX, UINT_MAX);
	printf("0")?printf("1\n"):printf("1\n");
	x>y ? max=x : (max=y);
	printf("max:%d\n", max);
	return 0;
}

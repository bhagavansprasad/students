#include <stdio.h>
#define bit_on_off(a,p)	a&(1<<(p-1))?1:0

main()
{
	int a=10,p=4,m;
	m = bit_on_off(a,p);
	printf("%d\n",m);
}

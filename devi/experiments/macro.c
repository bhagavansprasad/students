#include <stdio.h>
#define MAX 100
main()
{
	int *p;
	p = &MAX;// lval req
	printf("%d %u\n",MAX,p);
}

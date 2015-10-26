#include <stdio.h>
#include <stdlib.h>
int main()
{
	int *m, *c, i;
	m = malloc(4*4);
	c = calloc(4,4);
	
	for(i=0 ; i<4 ; i++)
	{
		printf("m[%d] : %d at %p\n", i, m[i], &m[i]);
		printf("c[%d] : %d at %p\n", i, c[i], &c[i]);
	}

	for(i=0 ; i<4 ; i++)
	{
		m[i] = i;
		c[i] = i;
	}
	printf("--> After assigning\n");
	for(i=0 ; i<4 ; i++)
	{
		printf("m[%d] : %d at %p\n", i, m[i], &m[i]);
		printf("c[%d] : %d at %p\n", i, c[i], &c[i]);
	}

	return 0;
}

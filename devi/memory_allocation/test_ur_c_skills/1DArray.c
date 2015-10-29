#include <stdio.h>
#include <stdlib.h>
#define MAX 10
main()
{
	int *p,i;
	p = (int*)malloc(MAX*sizeof(int));
	for(i=0;i<MAX;i++)
	{
		p[i] = i;
		printf("\n%d",p[i]);
	}
}

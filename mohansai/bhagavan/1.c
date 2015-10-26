#include "stdio.h"

char *fun()
{
	char *p=malloc(sizeof(50));
	strcpy(p,"mohansai welcome to aura");
	return p;
}


main()
{
	char *arr;

	arr = fun();
		printf("%s\n\r ",arr);
}


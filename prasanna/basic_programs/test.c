#include<stdio.h>
#include<malloc.h>
main()
{
	int *ptr  = malloc(100000);
	sleep(10);
	while(1)
	free(ptr);
}

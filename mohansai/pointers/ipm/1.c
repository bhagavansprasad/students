#include "stdio.h"
#include "stdlib.h"
main()
{
	char *ptr=malloc(100);

	char *p=ptr;
	*p='A';
	
	short int *sh=ptr+1;
	*sh=20;

	int *i=ptr+4;
	*i=100;

	printf("char %c\n\r",*p);
	printf("short %d\n\r",*sh);
	printf("int  %d\n\r",*i);

}


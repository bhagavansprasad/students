#include "stdio.h"
#include "stdlib.h"
main()
{
	char *ptr=malloc(100);

char *ch=ptr;
short int *sh=ptr;
int *p=ptr;

	*ch='A';
	printf("char %c\n\r",*ch);
	
	*sh=20;
	printf("short %d\n\r",*sh);

	*p=100;
	printf("int  %d\n\r",*p);

}


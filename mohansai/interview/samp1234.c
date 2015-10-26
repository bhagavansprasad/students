#include "stdio.h"
main()

{
unsigned int i=123456789;
unsigned int j=987654321;


i=i+j;
j=i-j;
i=i-j;

	printf("i-->%d\n j-->%d\n",i,j);
}


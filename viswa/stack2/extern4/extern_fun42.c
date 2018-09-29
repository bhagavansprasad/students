#include "defs.h"
#include "stdio.h"
#include "stdlib.h"
extern int b;
void extern_fun42(void)
{
	printf("-->MAX:%d\r\n",MAX);
	printf("-->a:%d\r\n",a);
	printf("-->b:%d\r\n",b);
}


#include "stdio.h"
extern int a;
void extern_fun3(void)
{
	printf("-->a:%d\r\n",a);
	printf("-->b%d\r\n",b);
}

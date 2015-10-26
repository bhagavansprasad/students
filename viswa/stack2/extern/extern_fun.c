#include "stdio.h"
extern int a;
void extern_fun(void)
{
	printf("-->a:%d\r\n",a);
}

#include "stdio.h"
main()
{
	char *p = "mohansai";
	
	char *q = NULL;
	
	while(*p)
		*q++ = *p++;
	
}


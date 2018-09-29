#include <stdio.h>
main()
{
	char *destsrc,*src="AURANETWORKS";
	destsrc=malloc(sizeof(src)+1);
	strcpy(destsrc,src);
	printf("%s\n",destsrc);
	free(destsrc);
	free(destsrc);
}

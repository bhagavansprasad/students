#include <stdio.h>
#include "stdlib.h"
#include <string.h>

main()
{
	char *s;
	char* fun();
	s = fun();
	printf("%s", s);
	free(s);
}

char* fun()
{
	char *buffer;
	buffer = (char *) malloc(30);
	strcpy(buffer,"RAM-Rarely Adequate Memory");
	return (buffer);
}

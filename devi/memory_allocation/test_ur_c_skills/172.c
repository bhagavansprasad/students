#include <stdio.h>
#include <string.h>

main()
{
	char *s;
	char* fun();
	s = fun();
	printf("%s", s);
}

char* fun()
{
	static char buffer[30];
	strcpy(buffer,"RAM-Rarely Adequate Memory");
	return (buffer);
}

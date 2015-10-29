#include <stdio.h>
#include <string.h>


//o/p is unpredictable bcoz buffer is an auto array

main()
{
	char *s;
	char* fun();
	s = fun();
	printf("%s", s);
}

char* fun()
{
	char buffer[30];
	strcpy(buffer,"RAM-Rarely Adequate Memory");
	return (buffer);
}

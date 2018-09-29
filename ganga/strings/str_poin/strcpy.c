#include <stdio.h>
#include "string.h"

int main()
{
	char sstr[] = "ganga";
	char dstr[] = "";
	char str = strcpy(dstr, sstr);
	printf(" string is :%s\n", str);
	
	return 0;
}

char strcpy(char *dstr, char *sstr)
{
	int i;
	for(i = 0; *sstr != '\0'; i++);
	*dstr++ = *sstr;

	return 0;
}

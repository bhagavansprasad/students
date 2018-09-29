#include <stdio.h>
#include "strings.h"
#include "stdlib.h"

int main()
{
	char p[] = "ramesh";
	int len = strlen(&p);

	printf("%d\n",len); 

	return 0;
}

int strlen(char *q)
{
	int i;
	for(i = 0; *q != '\0'; i++)
	q++;

	return q;
}

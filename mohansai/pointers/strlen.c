#include "stdio.h"

int astrlen(char *name);
main()
{
	int len;
	char name[] = "mohansai";
	len=astrlen(name);
	printf("len--> %d\n\r",len);
}

int astrlen(char *name)
{
int i;

while(name[i++]!='\0');
return i;
}

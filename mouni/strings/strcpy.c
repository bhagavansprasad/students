#include "stdio.h"
main()
{
	char s1[30]="aura networks";
	char s2[100];
	astrcpy(s2, s1);
}

void astrcpy(char *dest, char *src)
{
	int i;
	for(i=0; src[i]!='\0'; i++)
	{
		dest[i]=src[i];
	}
	printf("destination string is :%s \n", dest);
}

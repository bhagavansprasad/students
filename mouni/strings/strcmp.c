#include "stdio.h"

int astrcmp(char *src, char *dest)
{
	int i, flag = 0;
	for(i=0; src[i]!='\0' && dest[i]!='\0';i++)
	{
		if (dest[i] != src[i])
		{
			return 1;
		}
	}
	return 0;
}

main()
{
	char s1[20]="aura networks";
	char s2[20]="aura networks";
	int flag = 0;
	
	flag = astrcmp(s1, s2);

	if (flag == 1)
		printf("strings are not equal\n");
	else
		printf("strings are equal\n");
}

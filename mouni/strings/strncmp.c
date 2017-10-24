#include "stdio.h"
int astrncmp(char *src, char *dest)
{
	int i, n=4;
	for(i=0; i<4 && src[i]!='\0' && dest[i]!='\0'; i++)
	{
		if(dest[i]!=src[i])
		{
			return 1;
		}
	}
	return 0;
}
main()
{
	char s1[20]="auranedworks";
	char s2[20]="auranetworks";
	int flag=0;
	flag=astrncmp(s1, s2);
	if(flag==1)
	{
		printf("strings are not equal\n");
	}
	else
	{
		printf("stings are equal\n");
	}
}


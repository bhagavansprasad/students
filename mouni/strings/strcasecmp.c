#include "stdio.h"

int astrcasecmp(char *src, char *dest)
{
	int i, d=0, n = 0;
	for(i=0; src[i]!='\0' && dest[i]!='\0'; i++)
	{
		if(src[i] < dest[i])
		{
			d = src[i]-dest[i];
		}
		else if(src[i]>=dest[i])
		{
			d=src[i]-dest[i];
		}
		
		if(d != 32)
		{
			n = 1;
			break;
		}
		else if( d != 0)
		{
			n = 1;
			break;
		}
	}
	return n;
}

main()
{
	char s[10] = "Aura";
	char d[10] = "aura";
	int flag = 0; 
	flag = astrcasecmp(s, d);

	if(flag == 0)
	{
		printf("two strings are equal\n");
	}
	else
	{
		printf("two strings are not equal\n");
	}
}

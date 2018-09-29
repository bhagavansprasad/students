#include"string.h"
int is_pl(char*str1)
{
	int i,l,rval;
	l=strlen(str1);
	for(i=0;i<l/2;i++)
	{
		if(str1[i]!=str1[l-i-1])
		{
			return 0;
		}
	}
	return 1;
}

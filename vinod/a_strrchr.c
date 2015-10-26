#include "a_string.h"
char *a_strrchr(const char *a,char c)
{
	int i,len = a_strlen(a);
	for(i = len ; i >= 0 ; i--)
	{
		if(a[i] == c)
			return (char *)&a[i];
	}
	return '\0';
}

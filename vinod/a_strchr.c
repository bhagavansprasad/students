#include "a_string.h"
char *a_strchr(const char *a,char c)
{
	int i,len = a_strlen(a);
	for(i=0 ; i<len ; i++)
	{
		if(a[i] == c)
			return (char *)&a[i];
	}
	return '\0';
}

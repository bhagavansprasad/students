#include "a_string.h"
#include "stdio.h"
char *a_strcat(char *dest, const char *src)
{
	int i,len = a_strlen(dest);

	for (i = 0; (dest[len+i]=src[i]) ; i++);
	
	return (char *)dest;
}

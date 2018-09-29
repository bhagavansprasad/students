#include "a_string.h"
void a_strrev(char *src)
{
	char b;
	int len = a_strlen(src), i, j;
	j = len/2;
	for(i=0 ; i<j ; i++)
	{
		b=src[len-i-1];
		src[len-i-1]=src[i];
		src[i]=b;
	}
}

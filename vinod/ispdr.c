#include"a_string.h"
int is_palindrome(char *p)
{
	int i,len=0;
	len=a_strlen(p);
	for(i=0 ; i < len/2 ; i++)
	{
		if(p[i]!=p[len-i-1])
			return 0;
	}
	return 1;
}

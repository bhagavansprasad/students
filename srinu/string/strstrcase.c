#include <stdio.h>
#include <string.h>
const char *astrstr(const char *haystack, const char *needle)
{
	if ( !*needle )
	{
		return haystack;
	}
	for ( ; *haystack; ++haystack )
	{
		if ( toupper(*haystack) == toupper(*needle) )
		{
			/*
			 * Matched starting char -- loop through remaining chars.
			 */
			const char *h, *n;
			for ( h = haystack, n = needle; *h && *n; ++h, ++n )
			{
				if ( toupper(*h) != toupper(*n) )
				{
					break;
				}
			}
			if ( !*n ) /* matched all of 'needle' to null termination */
			{
				return haystack; /* return the start of the match */
			}
		}
	}
	return 0;
}
int main(void)
{
	const char haystack[200] = "The quick brown fox jumps over the lazy dog.";
	const char needle[20] = "FoX";
	const char *ret = NULL;
ret = strstr(haystack, needle);
	printf("haystack :%p\n", haystack);
	printf("needle   :%p\n", needle);
	printf("ret      :%p\n", ret);
	printf("The substring is: %s\n\n", ret);

	ret = strstr(haystack, needle);
	printf("haystack :%p\n", haystack);
	printf("needle   :%p\n", needle);
	printf("ret      :%p\n", ret);
	printf("The substring is: %s\n\n", ret);

//return 0;
	ret = astrstr(haystack, needle);
	printf("haystack :%p\n", haystack);
	printf("needle   :%p\n", needle);
	printf("ret      :%p\n", ret);
	printf("The substring is: %s\n", ret);

	return(0);
}

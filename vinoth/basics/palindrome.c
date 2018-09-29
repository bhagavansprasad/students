#include <stdio.h>
#include <string.h>
main ()
{
	int i, j;
	char s[300] ={"agphpa"};
	for (i = 0, j = strlen(s)-1; i<=j; i++, j--)
	{
		if (s[i] != s[j])
			break;
	}
	if (i>j)
	{
		printf ("it is a palindrome\n");
	}
	else
	{
		printf("it is not a palindrome\n");
	}
}

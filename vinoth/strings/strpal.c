#include <stdio.h>
#include <string.h>
char atolower (char a);

main ()
{
	char s[100] = "madam iam a level";
	int i, j, k, palindrome = 0;
	for (i = 0; s[i] != '\0'; i++)
	{
		for (  ; s[i] == ' ' && s[i] != '\0'; i++);
		
		j = i;

		for (  ; s[i] != ' ' && s[i] != '\0'; i++);
		
		k = i-1;

		for (  ; s[j] == s[k]; j++, k--)
		{
			if (j >= k)
			{
				palindrome ++;
				break;
			}
		}
	}
	printf ("string : %s\n", s);
	printf ("no. of palindrome : %d\n", palindrome);
}



/*char atolower (char a)
{
	if (a>='A' && a<='z')
	{
		a = a + 32;
	}
	return a;
}*/

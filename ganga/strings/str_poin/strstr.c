#include <stdio.h>
#include <string.h>

void main()
{
	char s1;
	int p = malloc(20);
	char s2;
	int q = malloc(10);

	int i, j= 0;

	for(i = 0; *s1 != '\0'; i++, s1++)
	{
		if(*s1 == *s2)
		{
			s1++, s2++;
			printf("strstr is :%c\n", *s1);
		}

		else if(*s1 != '\0' && *s2 == '\0')
		{
			s1++, s2++;
			printf("strstr is :%c\n", *s1);
		}
	}
}

#include <stdio.h>
#include <string.h>

void main()
{
	char s1[] = "global edge";
	char s2[] = "edge";
	int i, j= 0;

	for(i = 0; s1[i] != '\0'; i++)
	{
		if(s1[i] == s2[j])
		{
			j++;
			printf("%c\n", s1[i]);
		}
		
		//else if(s1[i] != '\0' && s2[j] == '\0')
		//	printf("%c\n", s1[i]);
	}
}

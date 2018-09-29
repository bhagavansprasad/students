#include <stdio.h>

void main()
{
	char str1[100] = "gangaaii";
	char str2[100] = "ramesh";
	int i, j ;
	for(i = 0 ; str1[i] !='\0' || str2[j] != '\0' ; i++)
	{
		printf("%3c\n", str1[i]);

		for(j = i ; j <= i ; j++)
		{
			printf("%3c\n", str2[j]);
		}

	}
}

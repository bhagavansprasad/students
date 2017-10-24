#include <stdio.h>
#include <stdlib.h>

main()
{
	char str1[10] = "mahesh";
	char str2[10] = "ramesh";
	char str[10];
	int i, j, k = 0, d;

	for(i = 0; str1[i] != '\0'; i++)
	{
		for(j = 0; str2[j] != '\0'; j++)
		{
			if(str1[i] != str2[j]);
				str[k] = str1[i];
		}
		k++;
	}
	printf("%s\n", str);
}

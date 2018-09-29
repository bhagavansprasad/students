#include <stdio.h>

main()
{
	char str[10] = "addidas";
	int i, j = 0;
	char str1[10] = " ";

	for(i = 0; str[i] != '\0'; i++)
	{	
		if(str[i] != 'd')
		{
			str1[j] = str[i];
			j++;
		}
	}
	printf("%s\n", str1);
}

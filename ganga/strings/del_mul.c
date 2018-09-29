#include "stdio.h"
#include "string.h"

void main()
{
	char str[100] = "rameshvvgh";
	int i, j, k = 0;

	for(i = 0 ; str[i] != '\0' ; i++)
	{
		for(j = i+1; str[j] != '\0'; j++)
		{
			if(str[i] == str[j]);
		}
		str[k] = str[i];
		k++;
	}
	printf("%s\n" , str);
}

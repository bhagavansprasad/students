#include <stdio.h>

main()
{
	char s1[20] = "networking";
	char s2[10] = "work";
	char str[10], temp;
	int i, j = 0, k = 0, len;
	for(len = 0; s2[len] != '\0'; len++);
	for(i = 0; s1[i] != '\0'; i++)
	{
		if(s1[i] != s2[j])
			printf("%c", s1[i]);
		else
		{
			while(s2[j] != '\0')
			{
				j = len - (j+1);
				temp = s2[j];
				str[k] = temp;
				printf("%c", str[k]);
		k++;
		j++;
			}
		}
	}
	printf("\n");
}

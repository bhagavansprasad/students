#include <stdio.h>
#include <string.h>

main()
{
	char *str="paidi kumar banagalore aura";
	char i,j;
	for(i=0;str[i]!='\0';i++)
	{
		if(str[i+1] == ' ' || str[i+1] == '\0')
		{
			for(j = i;j>=0 && str[j]!= ' ' ;j--)
				printf("%c",str[j]);
		}
		printf(" ");
	}
		printf("\n");
}

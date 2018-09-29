#include "stdio.h"

int get_word_count(char *p)
{
	int i = 0, count = 1;

	//printf("In function p:%s\n", p);

	for(i=0; p[i] != '\0'; i++)
	{
		if ((p[i] != ' ')||(p[i]=='\0') && (p[i+1] == ' '))
		{
			count++;
		}
	}

	return(count);
}

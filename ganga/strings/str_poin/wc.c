#include <stdio.h>
#include "string.h"

void main()
{ 
	char str [] = " ramesh ganga  ";
	int wc = word_count(str);
	printf("word count is: %d\n", wc);
}

int word_count(char *str)
{
	int wc, i;
	if(*str = ' ')
		wc = 0;
	else 
		wc = 1;

	for( i = 0; *str != '\0' ; i++)
	{
		str++;
		if(*str = ' ' && *str++ != ' ' && *str++ != '\0')
			wc++;
	}
	return wc;
}

#include <stdio.h>
#include <string.h>
int count_words(char *str);
main()
{
	char str[50]="         blue      red       green         ";
	printf("--->number of words is :%d\n",count_words(str));
}
int count_words(char *str)
{
	int cnt=0;
	while(*str!='\0')
	{
		while(*str==' ')
		str++;
		if(*str=='\0')
		return cnt;
		while(*str!=' ' && *str!='\0')
		{
			putchar(*str);
			str++;
		}
		cnt++;
		printf("\n");
	}
	return cnt;
}

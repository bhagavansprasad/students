#include <stdio.h>
void del_char(char *str,char ch)
{
	int i,j;
	for(i=0,j=0;str[i];i++)
	{
		if(str[i] != ch)
			str[j++] = str[i];

	}
	str[j] = '\0';
}
main()
{
	char str[]="data structures through c in depth";
	puts(str);
	del_char(str,'u');
	puts(str);
}

#include <stdio.h>
char str_r_chr(char *);
main()
{
	char *str="manohar";
	str_r_chr(str);
}
char str_r_chr(char *str)
{
	int i;
	for(i=0;str[i]!='\0';i++)
	{

	}
	printf("%c\n",str[i-1]);
}

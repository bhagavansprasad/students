#include <stdio.h>
main()
{
	char s[]="world";
	int i=0;
	for(i=0;s[i];i++)
	{
		printf("%c\n",*(i=s));
	}
}

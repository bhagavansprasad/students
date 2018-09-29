#include <stdio.h>
#include <string.h>
char strlwr(char str[]);
main()
{
	char str[10]="SREENU";
	printf("%s\n",strlwr(str));
}
char strlwr(char str[])
{
	int i;
	for(i=0;str[i]!='\0';i++)
	{
		if(str[i]>=97 && str[i]<=122)
		str[i]=str[i]-32;
		return &str;
	}
}

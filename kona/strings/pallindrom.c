#include <stdio.h>
#include <string.h>
main()
{
	char str[50]="radar";
	int i,j;
	for(i=0,j=strlen(str)-1;i<=j;i++,j--)
	{
		if(str[i]!=str[j])
			break;
	}
	if(i>j)
		printf("string is pallindrom\n");
	else
		printf("string is not pallindrom\n");
}

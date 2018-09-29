#include "stdio.h"
#include "string.h"
main()
{
	char str[20]="venky";
	char rev[20];
	int i,j;
	for(i=strlen(str)-1,j=0;i>=0;i--,j++)
	{
		rev[j]=str[i];
		rev[j]='\0';
	}
	if(strcmp(rev,str))
		printf("the str is polin");
	else
		printf("the str is not pol");
	return 0;
}

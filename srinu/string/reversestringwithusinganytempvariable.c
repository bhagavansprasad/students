#include<stdio.h>
#include<string.h>
main()
{
	int i=0,j=0;
	char s[100]="i have many books";
	printf("%s\n",s);
	for(j=strlen(s)-1;i>=0;i++,j--)
	{
		printf("%c",s[j]);
		if(j == 0)
			break;
	}
	printf("\n");
}

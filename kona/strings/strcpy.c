#include <stdio.h>
#include <string.h>
main()
{
	char str1[10]="sreenu";
	char str2[10];
	int i;
	for(i=0;str1[i]!='\0';i++)
	{
		str2[i]=str1[i];
	}
	str2[i]='\0';
	printf("%s\n",str2);
}

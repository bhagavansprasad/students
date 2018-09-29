#include <stdio.h>
main()
{
	int i,len=20;
	char str[50]="my name is venkatesamaiah\0";
	for(i=0;i<=len;i++)
	{
		printf("%s\n",&str[i]);
	}
}

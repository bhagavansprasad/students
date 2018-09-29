#include<stdio.h>
main()
{
	char str[]="India";
	int i;
	for(i=0;str[i]!='\0';i++)
	{
		printf("string is :%c\n",str[i]);
		printf("string address is :%p\n",&str[i]);
	}
}

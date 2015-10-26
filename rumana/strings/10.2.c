#include<stdio.h>
main()
{
	char str[]="India";
	char *p;
	p=str;
	while(*p!='\0')
	{
		printf("string value is :%c\n",*p);
		printf("string address is :%p\n",p);
		p++;
	}
}

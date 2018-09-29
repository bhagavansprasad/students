#include<stdio.h>
main()
{
	int length=0;
	char str[100]="my name is lucky";
	length=get_length(str);
	printf("%d",length);
}
int get_length(char*p)
{
int i=0;

	for(i=0;p[i]!='\0';i++);
	return i;
}

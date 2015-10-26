#include "stdio.h"
#include "fcntl.h"
main()
{
	int i=0;
	char buff[100]="reddy vinay";
	for(i=0;buff[i]!='\0';i++)
	{
	printf("%c",buff[i]);
	}
	printf("length of the string %d\r\n",i);
}

#include <stdio.h>
#include <fcntl.h>
main()
{
	int len=0;
	char buff[100]="reddy vinay";
	len= astrlen(buff);
	printf("length of the string %d\r\n",len);
	return(0);
}
int astrlen(char *p)
{
	int i=0;
	for(i=0;p[i]!='\0';i++);
	return(i);
}

#include<stdio.h>
#include<fcntl.h>
main()
{
	char buff[100]="venkatesa maiah chintha"
		"i am in the institute\0";
	int len=0;
	len=astrlen(buff);
	printf("length of the string is %d\r\n",len);
	return 0;
}
int astrlen(char *p)
{
	int i=0;
	for(i=0;p[i]!='\0';i++);
	return i;
}

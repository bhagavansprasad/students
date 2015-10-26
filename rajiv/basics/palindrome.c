#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
main()
{
	int i=0,j;
	char str[]="dad madam punished me";
	while(str[i]!='\0')
	{
	    int h=strlen(str)-1;
	

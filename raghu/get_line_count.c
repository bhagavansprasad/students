/*function for counting th number of lines in a file*/
#include <stdio.h>
int get_line_count(char * buff)
{
	int i,c=0;
	for(i=0;buff[i]!='\0';i++)
	{
		if(buff[i]=='\n')
		c++;
	}
	//printf("the number of lines in a file is : %d ",c);
	return c;
}

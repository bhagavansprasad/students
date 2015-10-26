#include<stdio.h>
#include<fcntl.h>
get_line_count(char*buff)
{
	int count = 0,i;
	for(i=0;buff[i] != '\0';i++)
	{
	if (buff[i]=='\n')
	count++;
	}
	printf("%d\n",count);
	return count;

}

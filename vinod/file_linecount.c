#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

int get_linecount(char *a,int r);

int main()
{
	char buff[100];
	int retval=0,count=0;
	
	int fd = open("g.txt",O_RDONLY);

	if(fd ==-1)
	{
	//	perror("Unable to open file because---->");
	//	printf("--->errno:%d\n",errno);
		exit(1);
	}

	do
		{
			retval = read(fd,buff,100);
			count += get_linecount(buff,retval);
			buff[retval] = '\0';i
	
	 	}while(retval > 1);
		
		printf("Line count:%d\n", count);
	
	return 0;
}

int get_linecount(char *a,int r)
{
	int i=0, count=0;
	for(i=0 ; i < r ; i++)
	{
		if(a[i] == '\n')
			count++;
	}
	return count;
}

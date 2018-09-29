#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<unistd.h>

int get_wordcount(char *a,int r);

int main()
{
	char buff[512];
	int retval=0,count=0;
	int fd = open("a.txt",O_RDONLY);

	if(fd==-1)
	{
		printf("file not exist \n");
	}

	else
	{
		do
		{
			retval = read(fd,buff,80);
			count += get_wordcount(buff,retval);
			buff[retval] = '\0';
			if(retval > 0)
				printf("%s", buff);
		}while(retval > 0);
		printf("Word count:%d\n", count);
	}
	return 0;
}

int get_wordcount(char *a,int r)
{
	int i=0, count=0;
	for(i=0 ; i<r ; i++)
	{
		if((a[i] == ' ' || a[i] == '\n' || a[i] == '\0')  && a[i+1] != ' ')
			count++;
	}
	return count;
}

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#define MAX_LEN 100
main()
{
	int fd=0;
	int len=0;
	int words=0;
	int retval = 0;
	char buff[MAX_LEN];

	fd = open("myown.txt",O_RDONLY);
	
	if(fd<0)
	{
		perror("Unable to open file : ");
		exit(1);
	}
	
	while(1)
	{
		retval = read(fd, buff, MAX_LEN);
		len += retval;
		words += get_wordcount(buff, MAX_LEN);
		if(retval < MAX_LEN)
			break;
	}
	printf("Number of bytes -> %d\n", len);
	printf("Number of words -> %d\n", words);
}
int get_wordcount(char *a, int len)
{
	int i, count = 0;
	for(i = 0; i<len ; i++)
	{
		if(a[i] != ' ' && i != 99)
		{
			count++;
			for( ; a[i+1] !=' ' && a[i+1] != '\0'; i++);
		}
	}
	return count;
}

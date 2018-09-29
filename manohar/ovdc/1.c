#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
main()
{
	int fd,i=0,j=10000,temp,read_retval,word = 0,sum = 0;
	char buff[300];
	fd = open("/proc/2934/stat",O_RDONLY);
	if(fd == -1)
	{
		printf("file open failed\n");
		exit(1);
	}

	read_retval = read(fd,buff,300);

	buff[read_retval]='\0';

	printf("%s\n",buff);

	for(i = 0;buff[i] != '\0' ; i++)
	{
		if(buff[i] == ' ')
		{
			word ++;
			
		}
		else 
		{
			if(word>11 && word<16)
			{
			temp=buff[i]-48;
			for(j = 10000;j >= 1;j = j / 10)
			{


			printf("temp--->%d\n",temp);
			sum = sum + temp;
			}
		}
	}
			printf("sum--->%d\n",sum);
	close(fd);
}

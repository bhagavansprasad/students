#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#define SIZE 20
char *m1[]={"hi","hw r u","good","nthng"};
char *m2[]={"hello","fn,u?","wat else","bye"};
main()
{
	int fd,pid,rval;
	int i =0, j =0;
	char buff1[SIZE+1];
	char buff2[SIZE+1];
	fd = open("myfifo",O_RDWR);
	pid = fork();
	if(pid > 0)
	{
		while(1)
		{
			write(fd,m1[i],SIZE+1);
			sleep(1);
			rval = read(fd,buff1,SIZE+1);
			buff1[rval]='\0';
			printf("from c: %s\n",buff1);
			if(strcmp(buff1,"bye")==0)
				exit(0);
			i++;
		}
	}
	else
	{
		while(1)
		{
			rval = read(fd,buff2,SIZE+1);
			buff2[rval]='\0';
			printf("from p: %s\n",buff2);
			if(strcmp(buff2,"bye")==0)
				exit(0);
			write(fd,m2[j],SIZE+1);
			sleep(1);
			j++;
		}
	}
}

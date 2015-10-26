#include<stdio.h>
#include<fcntl.h>
main()
{
	int fd,pid,s,i,len = 20;
	char buff[50];
	//pid= fork();
	fd = open("a.txt",0,O_RDONLY);
	//for (i =0;buff[i]!='\0';i++);
	//s = read(fd,buff,10);
	//buff[s]='\0';
	//printf("%s\n",buff);
	pid= fork();
	if(pid == 0)
	{
		fd = open("a.txt",0,O_RDONLY);
		//s = read(fd,buff,len);
		//buff[i]='\0';
		//for(i=0;;i++)
		while(1)
		{
		s = read(fd,buff,len);
		buff[s]='\0';
		printf("i am the child process id is =%d\n",fd);
		printf("%s\n",buff);
		}
			
	}
	else
	{
		fd = open("a.txt",0,O_RDONLY);
		s = read(fd,buff,len);
		buff[s]='\0';
		printf("i am the child process id is =%d\n",fd);
		printf("%s\n",buff);
		close(fd);
	}
}


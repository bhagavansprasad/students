#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
main()
{
	int pid,fd,fp;
	pid=fork();
	if(pid==0)
	{
		fd=open("f.txt",O_RDONLY,0);
		printf("fd value is %d\n",fd);
		fp=lseek(fd,0l,1);
		printf("fp in chaild is %d\n",fp);
		fp=lseek(fd,5l,1);
		printf("fp value in chaild is %d\n",fp);
	}
	else
	{
		fd=open("f.txt",O_RDONLY,0);
		printf("fd value in parent is %d\n",fd);
		fp=lseek(fd,0l,1);
		printf("fp value in parent  is %d\n",fp);
		fp=lseek(fd,10l,1);
		printf("value in parent is %d\n",fp);
	}
}


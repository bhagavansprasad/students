#include "stdio.h"
#include<stdlib.h>
#include "fcntl.h"
main()
{
	int pid,fd1,r=0,fp;
	char buff[100];
	fd1=open("f.txt",O_RDONLY,0);
	printf("fd1 is %d\n",fd1);
	pid=fork();
	if(pid==0)
	{
		fp=lseek(fd1,0l,1);
		printf("file pointer in chaild is %d\n",fp);
		fp=lseek(fd1,0l,1);
		printf("file pointer in chaild is %d\n",fp);
	}

	else
	{
		fp=lseek(fd1,0l,1);
		printf("file pointer in parent is %d\n",fp);
		fp=lseek(fd1,10l,1);
		printf("file pointer in parent is %d\n",fp);
	}
}	

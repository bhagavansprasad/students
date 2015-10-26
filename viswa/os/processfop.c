#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
main()
{
	int pid,wfd,pwfd,cfdo,crfd;
	char buff[100];
	int len =10;
	pid = fork();
	if(pid == 0)
	{
		cfdo = open("t.txt",O_RDONLY,0);
		printf("the rwturn value of the child open is %d\n",cfdo );
		crfd = read(cfdo,buff,len);
		buff[crfd] = '\0';
		printf("the rwturn value of the child open is %d\n",crfd );
		printf("the  value of the child open is %s\n",buff );
		wfd = open("t1.txt",O_CREAT|O_WRONLY,0777);
		printf("the return value of the parent is %d\n",wfd);
	}
	else
	{
		wait();
		wfd = open("t1.txt",O_CREAT|O_WRONLY,0777);
		printf("the return value of the parent is %d\n",wfd);
		pwfd = write(wfd,buff,crfd);
		printf("the return value of the parent is %d\n",pwfd);
		printf("the value of the parent is %s\n",buff);
	}
}

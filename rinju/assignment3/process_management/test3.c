
#include <stdio.h>
#include<fcntl.h>
int a=10;
main()

{	
	//FILE *fp;
	int pid,fd;
	char buff[100] = "hi how are you";
	char arr[50];


	fd=open("temp.tx",O_CREAT |O_RDWR);
	pid=fork();
	if(pid == 0)
	{
		
			int retval=	write(fd,buff,100);
			printf("i am child\n");
	}
	else
	{int retval;

			
	      while( retval=read(fd,arr,100)){

			arr[retval]='\0';
			printf("%s",arr);}
			printf("i am parent\n");
	}
			close(fd);	
}

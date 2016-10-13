#include "stdio.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
main()
{
	//open 1.txt in read mode
	//open 2.txt in write mode
	//read first 10 bytes from 1.txt
	//write 10 bytes to 2.txt
	//read last 10 bytes from 1.txt
	//write 10 bytes to 2.txt
	//close 1.txt
	//close 2.txt


	int fd1 = 0,fd2 = 0, rd = 0, ld = 0, wd=0;
	char buff[100];


	fd1 = crpc_open("t.txt", O_RDONLY, 0);
	printf("fd1 :%d\n", fd1);

	fd2 = crpc_open("s.txt", O_WRONLY, 0);
	printf("fd2 :%d\n", fd2);

	rd = crpc_read(fd1, buff, 10);
	printf("rd :%d\n", rd);
	rd[buff]='\0';
	printf("buff :%s\n",buff);

	wd = crpc_write(fd2, buff, 10);
	printf("wd :%d\n", wd);
	wd[buff]='\0';
	printf("buff :%s\n",buff);

	ld = crpc_lseek(fd1, -10, SEEK_END); 
	printf("ld :%d\n", ld);

	rd = crpc_read(fd1, buff, 10);
	printf("rd :%d\n", rd);
	rd[buff]='\0';
    printf("buff :%s\n",buff);

	wd = crpc_write(fd2, buff, 10);
	printf("wd :%d\n", wd);
	wd[buff]='\0';
  printf("buff :%s\n",buff); 

	close(fd1);
	close(fd2);
}


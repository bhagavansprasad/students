#include <stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<string.h>
#include<unistd.h>

void main()
{
 int fd=-1,fd1=0,retval=0;
char buffer[50]="aura institut paidi kumar";
  fd = creat("t.txt",O_CREAT|0777);
  fd1= open("t.txt",O_RDWR);    
  if(fd1== -1)
  {
   perror("file will be not open\n");
   exit(0);
  }
  retval = write(fd1,buffer,strlen(buffer));
  printf("retval-->=%d\n",retval);
  printf("fd1-->=%d\n",fd1);
}

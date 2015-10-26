#include"stdio.h"
#include"fcntl.h"
#define MSG 63

main()
{
int fd;
char msgbuf[MSG+1];
if((fd=open("testpipe",O_RDWR))<0)
perror("pipe open failed fd");
for(;;)
{
if(read(fd,msgbuf,MSG+1)>0)
printf("message received :%s \n",msgbuf);
}
}


#include <stdio.h>
#include <fcntl.h>
#define MSGSIZ 63

main()
{
  int fd;
  char msgbuff[11];

  fd=open("testpipe",O_RDWR);
  if(fd<0)
   perror("pipe open failed");

//  for( ; ; )
  {
   if(read(fd,msgbuff,MSGSIZ+1)>0)
    printf("message received :%s\n",msgbuff);
  }
  
}

#include <stdio.h>
#include "header.h"
swfd ,len;
void server (int rfd, int wfd)
{
 swfd = wfd;
 for(;;)
  {
    read(rfd, s1, paidi);
	printf("from client i am recvng msg ---->= %s\n", s1);

    write(wfd, "hai hello", paidi);
	sleep(2);
   }	
	read(rfd,s3,paidi);
	printf("press the key to stop\n",s3);
	sleep(2);

     printf("PRESS CTRL+C\n");
      sleep(5);             	
  }

}

void abc()
{
    printf("(you have pressed  ctrl + c  KEY)\n");
    write(swfd, "BYE", strlen(msg4));
    sleep(2);
}


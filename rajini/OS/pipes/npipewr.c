#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
//#define MSGSIZ 63

main()
{
		int fd,j,nwrite;
		char msgbuf[50];
		
		if((fd=open("testpie",O_WRONLY))<0)   
			perror("fifo open failed\n");

//		for(j=1;j<argc;j++)
		{
			strcpy(msgbuf,"Hi How r u");
			if((nwrite=write(fd,msgbuf,MSGSIZ+1))<=0)
				perror("message write failed\n");
		}
		exit(0);
	}

	

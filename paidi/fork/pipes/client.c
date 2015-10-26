#include <stdio.h>
#include "header.h"
int len;
void client (int rfd, int wfd)
{ 
   for(;;)
   {
	 write(wfd,"aura network",paidi);

	read(rfd, s2, paidi);
	printf("client recvng from server:%s\n\n",s2);
	sleep(2);
	write(wfd,"hai aura net work",paidi);
    read(rfd,msg4,MACRO);
	if((strcmp(msg4,"BYE")) == 0)
	{
		printf("iam getting reply : BYE\n");
		exit(1);
		}

   }

  }
}

void client(int rfd,int wfd)
{
    int len;
    for(;;)
    {
        write(wfd,"HELLO",MACRO);

        read(rfd,msg2,MACRO);
        printf("ITS FROM SERVER END IAM RECEIVING MSG2:%s\t\tSERVER PID IS:%d\n\n",msg2,getpid());

        write(wfd,"THANQ FOR THE REPLY",MACRO);
        sleep(2);
       
        signal(SIGINT,abc);   

//        len=read(rfd,msg4,MACRO);
        read(rfd,msg4,MACRO);
//        perror("");
//          msg4[len] = "\0";
//      printf("len %d ",len);
        printf("reading:%s\n",msg4);
    }   
        if((strcmp(msg4,"BYE")) == 0)
        {
            printf("FROM SERVER END IAM GETTING REPLY msg4: BYE\n");
            exit(1);
        }
        else
        printf("THE STRING IS NOT SAME\n");
}

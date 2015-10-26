#include"stdio.h"
#include"fcntl.h"
#include"errno.h"
#define MSGSIZ 63

main(argc,argv)
int argc;
char *argv[];
{
int fd,j,nwrite;
char msgbuf[MSGSIZ];
if(argc<2)
{
printf("usage:<Filename><message><message>........\n");
exit(1);
}
if((fd=open("testpipe",O_WRONLY))<0)
perror("fifo open failed");
for(j=1;j<argc;j++)
{
strcpy(msgbuf,argv[j]);
if((nwrite=write(fd,msgbuf,MSGSIZ+1))<=0)
perror("message write failed");
}
exit(0);
}

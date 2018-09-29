#include<stdio.h>
#include<fcntl.h>
#include<errno.h>
#include"afop.h"
main()
{
client_req();
int fd,fd1,l=10,r,w;
fd=aopen("t.txt",O_RDONLY,0);
printf("---->fd value is :%d\n",fd);
fd1=aopen("new.txt",O_RDWR|O_CREAT,0644);
printf("----->fd1 value is :%d\n",fd1);

while(1)
{
 r=aread(fd,buf,l);
 buf[r]='\0';
 printf("%s\n",buf);
 w=awrite(fd1,buf,r);
 if(r<l)
 {
  break;
  }
  }
  aclose(fd);
  aclose(fd1);
  }

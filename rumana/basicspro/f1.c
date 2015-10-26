#include<stdio.h>
#include"fop.h"
#include<fcntl.h>
main()
{
int fd1,fd2,r,w,len=10;
char buff1[200],buff2[200];
fd1=aopen("a.txt",O_RDONLY,0);
fd2=aopen("b.txt",O_RDWR|O_CREAT,0777);
printf("fd1 is %d\n",fd1);
printf("fd2 is %d\n",fd2);

while(1)

{
	r=aread(fd1,buff1,len);
	buff1[r]='\0';
	printf("read in the file  is %s",buff1);
	w=awrite(fd2,buff2,len);
	//printf("write in the file  is %s",buff2);
	if(r<len)
	break;
}
 aclose(fd1);
 aclose(fd2);
}

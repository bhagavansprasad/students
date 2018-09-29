#include<stdio.h>
#include<fcntl.h>
#define fname "log1.txt"
main()
{
int fd,fd1,r,w,fp,fileremover;
char buff[2000];

fd=open("log1.txt",O_RDONLY,0);
printf("fd value is %d\n",fd);

fd1=open("newlog.txt",O_CREAT|O_RDWR,0777);
printf("fd1 is %d\n",fd1);

fp=lseek(fd,-1000l,2);
printf("file pointer is %d\n",fp);

r=read(fd,buff,1000);
printf("no of bytes reading is %d\n",r);

w=write(fd1,buff,r);
printf("no of bytes writing in to the file%d\n",w);

 fileremover=remove(fname);
printf("file had removed :%d",fileremover);

close(fd);
close(fd1);

}

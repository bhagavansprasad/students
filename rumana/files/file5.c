#include<stdio.h>
#include<fcntl.h>
main()
{
int fd,count=0,r,i;
char buff[500];
fd=open("file2.c",O_RDWR,0);
printf("%d",fd);
r=read(fd,buff,500);
buff[r]='\0';
for(i=0;buff[i]!='\0';i++)
{
if(buff[i]=='\n')
count++;
}
printf("%d\n",count);
}

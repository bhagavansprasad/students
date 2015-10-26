#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
int fd, rval,wval;
fd=open("t2.txt",O_RDONLY);
if(fd<0)
{
printf("there exist error in opening file");
exit(1);
}
while(1)
{
rval=read(fd,buff,10);
buff[rval]='\0';
printf("%s",buff);
if(rval<10)
break;
}
while(1)
{
wval=write(rval,buff,10)
buff[wval]='\0';
printf("%s",buff);
if(wval<10)
break;
}
close(fd);
}

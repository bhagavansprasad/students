#include <stdio.h>
#include <fcntl.h>

main()
{
int fd1,fd2,i,rv,len=10;
char buff[512];
fd1=open("a.txt",O_RDONLY);
fd2=open("case.txt",O_CREAT|O_RDWR,0644);
while(1)
{
	rv=read(fd1,buff,len);
		buff[rv]='\0';
for(i=0;buff[i]!='\0';i++)
{
	if(buff[i]>=97&&buff[i]<=122)
	{
		buff[i]=buff[i]-32;
			buff[rv]='\0';
			}

	else if(buff[i]>=65&&buff[i]<=90)
	{
		buff[i]=buff[i]+32;
		buff[rv]='\0';
	}
}
	buff[rv]='\0';
write(fd2,buff,len);
if(rv<len)
	break;
}
close(fd1);
close(fd2);


	}

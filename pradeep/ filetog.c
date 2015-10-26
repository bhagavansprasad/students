#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
int main()
{
	int fd=0,fd1=0,w,c,r,i,len=10;
	char buff[100];
	fd=open("lol.txt",0,O_RDONLY);
	fd1=open("cp.txt",O_CREAT|O_WRONLY,0777);
	while(1)
	{
		r=read(fd,buff,len);
		buff[r]='\0';
		for(i=0;buff[i]!='\0';i++)
		{
			if(buff[i]<65 || buff[i]>122)
				buff[i]=buff[i];
			if(buff[i]>=65 && buff[i]<=90)
				buff[i]=buff[i]+32;
			else
				if(buff[i]>=97 && buff[i]<=122)
					buff[i]=buff[i]-32;
		}
		w=write(fd1,buff,r);
		if(r<len)
			break;
	}
	close (fd);
	close (fd1);
}

#include<stdio.h>
#include<fcntl.h>
main()
{
	int i,fd,fd1,r=0,w,l=10;
	char buf[200];
	fd=open("first.c",O_RDONLY);
	printf("%d",fd);
	while(1)
	{
		r=read(fd,buf,l);
		buf[i]='\0';
		for(i=0;buf[i]!='\0';i++)
		{
			if(buf[i]>=65 && buf[i]<=90)
				buf[i]=buf[i]+32;
			printf("%s",buf);
				fd1=open("new.c",O_CREAT|O_RDWR,0777);
			w=write(fd1,buf,r);
			if(w<0)
			{
				printf("error in program");
			}
			if(r<l)
			break;
		}
		}
		close("%d",fd);
	}





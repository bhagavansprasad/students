#include<stdio.h>
#include <unistd.h>
#include<sys/stat.h>
#include <fcntl.h>
main()
{
	int fd,len,i,nw=0,nl=0,s=0;
	char buf[100];

	fd = open("r1.txt",O_RDONLY);

	while(1)
	{
		len=read(fd,buf,100);
		buf[len]='\0';
		for(i=0; buf[i] != '\0'; i++)
		{
						
			if(buf[i] == ' ')
			{
				for(;buf[i]==' ';i++);
				i--;
			}

			if(buf[i]>=65 && buf[i]<=122)
			{
				nw++;
				for(;buf[i]>=65 && buf[i]<=122;i++);
				i--;
			}

			if(buf[i]=='\n')
			{
			nl++;
//			continue;
			}	
		}
		s=s+len;
		if(len < 100)
			break;
	}
	close(fd);
	printf("nl :%d, nw: %d,  s:%d\n",nl,nw,s);
}

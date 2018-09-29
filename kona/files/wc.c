#include<stdio.h>
#include<fcntl.h>
main()
{
	int fd,r,ln=10,s=0,c=0,i,k=0;
	char buf[100];
	fd=open("first.c",O_RDWR);
	printf("%d\n",fd);
	while(1)
	{
		r=read(fd,buf,ln);
		s=s+r;
		buf[r]='\0';
		for(i=0;buf[i]!='\0';i++)
		{
			if(buf[i]!='\n')
				c++;
			if((buf[i]==' ' && buf[i+1]!=' ') && buf[i]=='\0')
				k++;
		}
		if(r<ln)
			break;
	}
	printf("%d\t%d\t%d",s,c,k);
close(fd);
}
